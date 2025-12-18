#pragma once

#include <SDL3/SDL_audio.h>
#include <atomic>
#include <vector>

struct SoundData
{
	SDL_AudioSpec spec;
	Uint8* wavData;
	Uint32 wavDataLength;
};

enum StreamState
{
	READY = 1, PLAYING = 2, STOPPED = 3
};

class Stream
{
private:
	SDL_AudioStream* _stream;
	StreamState _state;

	void StopStream()
	{
		SDL_ClearAudioStream(_stream);
		SDL_UnbindAudioStream(_stream);

		SDL_DestroyAudioStream(_stream);

		_state = STOPPED;
	}

public:
	Stream(SDL_AudioSpec spec, SDL_AudioDeviceID deviceId)
	{
		_stream = SDL_CreateAudioStream(&spec, NULL);

		SDL_BindAudioStream(deviceId, _stream);

		_state = READY;
	}

	~Stream() {}

	void CheckPlayback(SoundData* soundData, std::atomic<bool>& haltRequest)
	{
		while (_state != STOPPED)
		{
			if ((_state != READY && SDL_GetAudioStreamQueued(_stream) == 0) || haltRequest)
			{
				StopStream();
			}

			if (_state == READY)
			{
				Uint32 bytesQueued = SDL_GetAudioStreamQueued(_stream);
				int bytesRemaining = ((int)soundData->wavDataLength) - bytesQueued;

				std::vector<Uint8> wavDataRemainingVec = std::vector<Uint8>(bytesRemaining, '\0');

				Uint8* wavDataRemaining = &wavDataRemainingVec[0];

				SDL_memcpy(wavDataRemaining, (const Uint32*)&soundData->wavData[bytesQueued], bytesRemaining);
				SDL_PutAudioStreamData(_stream, wavDataRemaining, bytesRemaining);

				SDL_FlushAudioStream(_stream);

				_state = PLAYING;
			}
		}
	}
};