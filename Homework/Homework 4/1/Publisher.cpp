#include"Publisher.hpp"

using namespace std;

Publisher::Publisher() {}

Publisher::Publisher(Averager* _averager)
{
	if (_averager) {
		this->averagers.push_back(_averager);
	}
}

Publisher::Publisher(MovingAverager* _movingAverager)
{
	if (_movingAverager) {
		this->movingAveragers.push_back(_movingAverager);
	}
}

Publisher::Publisher(PeriodicSampler* _periodicSampler)
{
	if (_periodicSampler) {
		this->periodicSamplers.push_back(_periodicSampler);
	}
}
