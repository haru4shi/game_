#pragma once

class Timer
{
public:
	Timer(float nowTime);
	float GetTime();

private:
	float nowTime = 0;
};

