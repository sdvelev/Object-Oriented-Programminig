#include<iostream>
#include"Vector4D.hpp"

using namespace std;

Vector4D::Vector4D() {
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}

Vector4D::Vector4D(double _a, double _b, double _c, double _d) {
	this->a = _a;
	this->b = _b;
	this->c = _c;
	this->d = _d;
}

Vector4D::Vector4D(const Vector4D& other) {
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
	this->d = other.d;
}

double& Vector4D::operator[](int index) {
	if (index == 0) {
		return this->a;
	}
	else if (index == 1) {
		return this->b;
	}
	else if (index == 2) {
		return this->c;
	}
	else if (index == 3) {
		return this->d;
	}
}

Vector4D operator+(const Vector4D& lhs, const Vector4D& rhs) {
	Vector4D result;
	result.a = lhs.a + rhs.a;
	result.b = lhs.b + rhs.b;
	result.c = lhs.c + rhs.c;
	result.d = lhs.d + rhs.d;
	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs) {

	this->a = this->a + rhs.a;
	this->b = this->b + rhs.b;
	this->c = this->c + rhs.c;
	this->d = this->d + rhs.d;
	return *this;
}



void Vector4D::print() const {
	cout << this->a << " " << this->b << " " << this->c << " " << this->d << endl;
}

void Vector4D::operator=(const Vector4D& other) {
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
	this->d = other.d;
}


Vector4D operator-(const Vector4D& lhs, const Vector4D& rhs) {
	Vector4D result;
	result.a = lhs.a - rhs.a;
	result.b = lhs.b - rhs.b;
	result.c = lhs.c - rhs.c;
	result.d = lhs.d - rhs.d;
	return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs) {
	this->a = this->a - rhs.a;
	this->b = this->b - rhs.b;
	this->c = this->c - rhs.c;
	this->d = this->d - rhs.d;
	return *this;
}


Vector4D operator*(const Vector4D& lhs, const Vector4D& rhs) {
	Vector4D result;
	result.a = lhs.a * rhs.a;
	result.b = lhs.b * rhs.b;
	result.c = lhs.c * rhs.c;
	result.d = lhs.d * rhs.d;
	return result;
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs) {
	this->a = this->a * rhs.a;
	this->b = this->b * rhs.b;
	this->c = this->c * rhs.c;
	this->d = this->d * rhs.d;
	return *this;
}

Vector4D operator*(const Vector4D& lhs, double rhs) {
	Vector4D result;
	result.a = lhs.a * rhs;
	result.b = lhs.b * rhs;
	result.c = lhs.c * rhs;
	result.d = lhs.d * rhs;
	return result;
}

Vector4D& Vector4D::operator*=(double rhs) {
	this->a = this->a * rhs;
	this->b = this->b * rhs;
	this->c = this->c * rhs;
	this->d = this->d * rhs;
	return *this;
}

Vector4D operator/(const Vector4D& lhs, const Vector4D& rhs) {
	Vector4D result;
	result.a = lhs.a / rhs.a;
	result.b = lhs.b / rhs.b;
	result.c = lhs.c / rhs.c;
	result.d = lhs.d / rhs.d;
	return result;
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs) {
	this->a = this->a / rhs.a;
	this->b = this->b / rhs.b;
	this->c = this->c / rhs.c;
	this->d = this->d / rhs.d;
	return *this;
}

bool operator==(const Vector4D& lhs, const Vector4D& rhs) {
	if (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d)
	{
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const Vector4D& lhs, const Vector4D& rhs) {
	if (lhs.a != rhs.a || lhs.b != rhs.b || lhs.c != rhs.c || lhs.d != rhs.d)
	{
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const Vector4D& lhs, const Vector4D& rhs) {
	
	if (lhs.a > rhs.a) {
		return false;
	}
	else if (lhs.a < rhs.a) {
		return true;
	}
	else {
		if (lhs.b > rhs.b) {
			return false;
		}
		else if (lhs.a < rhs.a) {
			return true;
		}
		else {
			if (lhs.c > rhs.c) {
				return false;
			}
			else if (lhs.c < rhs.c) {
				return true;
			}
			else {
				if (lhs.d > rhs.d) {
					return false;
				}
				else if (lhs.d < rhs.d) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

bool operator<=(const Vector4D& lhs, const Vector4D& rhs) {
	/*if (lhs.a <= rhs.b && lhs.b <= rhs.b && lhs.c <= rhs.c && lhs.d <= rhs.d)
	{
		return true;
	}
	else {
		return false;
	}*/

	if (lhs.a > rhs.a) {
		return false;
	}
	else if (lhs.a < rhs.a) {
		return true;
	}
	else {
		if (lhs.b > rhs.b) {
			return false;
		}
		else if (lhs.a < rhs.a) {
			return true;
		}
		else {
			if (lhs.c > rhs.c) {
				return false;
			}
			else if (lhs.c < rhs.c) {
				return true;
			}
			else {
				if (lhs.d > rhs.d) {
					return false;
				}
				else if (lhs.d < rhs.d) {
					return true;
				}
				else {
					return true;
				}
			}
		}
	}
}

bool operator>(const Vector4D& lhs, const Vector4D& rhs) {
	/*if (lhs.a > rhs.b && lhs.b > rhs.b && lhs.c > rhs.c && lhs.d > rhs.d)
	{
		return true;
	}
	else {
		return false;
	}*/

	if (lhs.a < rhs.a) {
		return false;
	}
	else if (lhs.a > rhs.a) {
		return true;
	}
	else {
		if (lhs.b < rhs.b) {
			return false;
		}
		else if (lhs.a > rhs.a) {
			return true;
		}
		else {
			if (lhs.c < rhs.c) {
				return false;
			}
			else if (lhs.c > rhs.c) {
				return true;
			}
			else {
				if (lhs.d < rhs.d) {
					return false;
				}
				else if (lhs.d > rhs.d) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

bool operator>=(const Vector4D& lhs, const Vector4D& rhs) {
	/*if (lhs.a >= rhs.b && lhs.b >= rhs.b && lhs.c >= rhs.c && lhs.d >= rhs.d)
	{
		return true;
	}
	else {
		return false;
	}*/

	if (lhs.a < rhs.a) {
		return false;
	}
	else if (lhs.a > rhs.a) {
		return true;
	}
	else {
		if (lhs.b < rhs.b) {
			return false;
		}
		else if (lhs.a > rhs.a) {
			return true;
		}
		else {
			if (lhs.c < rhs.c) {
				return false;
			}
			else if (lhs.c > rhs.c) {
				return true;
			}
			else {
				if (lhs.d < rhs.d) {
					return false;
				}
				else if (lhs.d > rhs.d) {
					return true;
				}
				else {
					return true;
				}
			}
		}
	}


}

bool operator!(const Vector4D& rhs) {
	if (rhs.a == 0 && rhs.b == 0 && rhs.c == 0 && rhs.d == 0) {
		return true;
	}
	else {
		return false;
	}
}

Vector4D operator-(const Vector4D& rhs) {
	Vector4D result;
	result.a = -rhs.a;
	result.b = -rhs.b;
	result.c = -rhs.c;
	result.d = -rhs.d;
	return result;
}