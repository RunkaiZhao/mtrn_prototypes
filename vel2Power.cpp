#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Twist {
	vector <float> linear;
	vector <float> angular;
};

class ToPower {
private:
	float maxVel;
	float vel;
	float perc;

public:
	ToPower(Twist *msg, float maxVel) {
		this->vel = msg->linear.back();
		this->maxVel = maxVel;
	}

	float vel2Power() {
		if (this->vel > this->maxVel) {
			cout << "Resign value to velocity" << endl;
			return 0;
		}
		this->perc = this->vel / this->maxVel;
		return this->perc;
	}
};


int main() {
	while (1) {
		float maxVel = 50;
		cout << "The max velocity is: " << maxVel << endl;
		float vel;
		cout << "Please type velocity value (in two decimal places): ";
		cin >> vel;

		Twist msg[4];
		msg[0].linear.push_back(vel);
		msg[1].linear.push_back(vel);
		msg[2].linear.push_back(vel);
		msg[3].linear.push_back(vel);
		
		
		float power[4] = { 0 };
		cout << "Linear velocity: ";
		for (int i = 0; i < 4; i++) {	
			ToPower topower(&msg[i], maxVel);	
			std::cout << std::fixed;
			std::cout << std::setprecision(2);
			cout << msg[i].linear.back() << ' ';
			power[i] = topower.vel2Power();
		}
		cout << endl;

		cout << "Power percentage: ";
		for (int i = 0; i < 4; i++) {
			std::cout << std::fixed;
			std::cout << std::setprecision(2);
			cout << power[i] << ' ';
		}
		cout << endl << endl;
	}

	return 0;
}

