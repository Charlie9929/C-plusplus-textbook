#include<iostream>
#include<iomanip>
#include<stdexcept>
#include"时间显示.h"

using namespace std;

Time::Time(int hour, int minute, int second) {
	setTime(hour, minute, second);
}
void Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}
void Time::setHour(int h) {
	if (h >= 0 && h < 24)
		hour = h;
	else
		throw invalid_argument("hour must be 0-23");
}
void Time::setMinute(int m) {
	if (m >= 0 && m < 60)
		minute = m;
	else
		throw invalid_argument("minute must be 0-59");
}
void Time::setSecond(int s) {
	if (s>= 0 && s < 60)
		second = s;
	else
		throw invalid_argument("minute must be 0-59");
}

unsigned int Time::getHour()const {
	return hour;
}
unsigned int Time::getMinute()const {
	return minute;
}
unsigned int Time::getSecond()const {
	return second;
}


void Time::printniversal() const {
	cout << setfill('0') << setw(2) << hour <<":"<< setw(2) << minute <<':'<< setw(2) << second;
}

void Time::printStandard() const {
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ':' << setfill('0') << setw(2) << minute << ':' << setw(2) << second << (hour < 12 ? "AM" : "PM");
}

int main() {
	Time t1;
	Time t2(2);
	Time t3(21, 34);
	Time t4(12, 25, 42);
	cout << "Construcuted with:\n\nt1:all arguments defaulted\n";
	t1.printniversal();
	cout << "\n";
	t1.printStandard();

	cout << "\n\nt2:hour确定，其他默认";
	t2.printniversal();
	cout << endl;
	t2.printStandard();

	cout << "\n\nt3:小时，分钟确定，秒默认";
	t3.printniversal();
	cout << "\n";
	t3.printStandard();

	cout << "\n\nt4:全部确定";
	t4.printniversal();
	cout << endl;
	t4.printStandard();

	try {
		Time t5(26, 75, 99);

	}
	catch (invalid_argument& e) {
		cerr << "\n\nException while intializing t5:" << e.what() << endl;
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                          