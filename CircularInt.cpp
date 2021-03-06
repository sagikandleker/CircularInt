#include <vector>
#include <set>
#include <iostream>
#include <string>
#include "CircularInt.hpp"

CircularInt::CircularInt(int a, int b)
{
	if(a > b)
	{
		this->max = a;
		this->min = b;
	}
	else
	{
		this->min = a;
		this->max = b;
	}
	this->now = this->min;
}

CircularInt::CircularInt(const CircularInt& h)
{
	this->min = h.min;
	this->max = h.max;
	this->now = h.now;
}

CircularInt& CircularInt::operator-=(const int num){
	this->now = this->now - num;
	if(this->now < min)
	{
		this->now = this->now % max + max;
	}
	return *this;
}

CircularInt& CircularInt::operator-=(const CircularInt& h){
	this->now = this->now - h.now;
	if(this->now < min)
	{
		this->now = this->now % max + max;
	}
	return *this;
}

CircularInt& CircularInt::operator+=(const int num) {
	this->now = this->now+num;
	if(this->now > max)
	{
		this->now = this->now % max;
	}
	return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& h) {
	this->now = this->now+h.now;
	if(this->now > max)
	{
		this->now = this->now % max;
	}
	return *this;
}
CircularInt CircularInt::operator--(const int){
	CircularInt temp(*this);
	operator--();
	return temp;
}
CircularInt& CircularInt::operator--(){
	now--;
	while(now<min){
		now=now+max;
	}
	return *this;
}

CircularInt CircularInt::operator++(int){
	CircularInt temp(*this);
	operator++();
	return temp;
}

CircularInt& CircularInt::operator++(){
	now++;
	if(now > max)
	{
		now =now % max;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const int num){

	now = num;
	if(now > max)
	{
		now =now % max;
	}
	while(now<min){
		now+=max;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const CircularInt& h){
	now = h.now;
	if(now > max)
	{
		now =now % max;
	}
	while(now<min){
		now+=max;
	}
	return *this;

}

CircularInt& CircularInt::operator*=(const int num){

	this->now *= num;

	while(now > max)
	{
		now-=max;
	}
	while(now < min)
	{
		now+=max;
	}

	return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& h){
	this->now *= h.now;

	while(now > max)
	{
		now-=max;
	}
	while(now < min)
	{
		now+=max;
	}

	return *this;
}

CircularInt& CircularInt::operator/=(const int num){
	
	for(int i = this->min; i < this->max; i++)
	{
		int temp = i*num;
		while(temp>this->max){
			temp-=this->max;
		}

		while(temp<this->min){
			temp+=this->max;
		}

		if(temp == this->now)
		{
			this->now = i;
			return *this;
		}
	}

	throw string("There is no number x in {"+to_string(this->min)+ ","+ to_string(this->max)+"} such that x*" + to_string(num)+"="+to_string(this->now));
}

CircularInt& CircularInt::operator/=(const CircularInt& h){
	CircularInt Object(h);
	for(int i = this->min; i < this->max; i++)
	{
		int temp = i *Object.now;
		while(temp>this->max){
			temp-=this->max;
		}

		while(temp<this->min){
			temp+=this->max;
		}

		if(temp == Object.now)
		{
			this->now = i;
			return *this;
		}
	}

	throw string("There is no number x in {"+to_string(this->min)+ ","+ to_string(this->max)+"} such that x*" + to_string(Object.now)+"="+to_string(this->now));
}
