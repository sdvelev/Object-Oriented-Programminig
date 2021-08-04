#pragma once

// Add all other required methods and fields of the class.

class Vector4D {
private:
    double a;
    double b;
    double c;
    double d;
public:
    Vector4D();
    Vector4D(double, double, double, double);
    Vector4D(const Vector4D& other);

    double &operator[](int index);

    friend Vector4D operator+(const Vector4D& lhs, const Vector4D& rhs);
    Vector4D& operator+=(const Vector4D& rhs);

    void operator=(const Vector4D& other);

    friend Vector4D operator-(const Vector4D& lhs, const Vector4D& rhs);
    Vector4D& operator-=(const Vector4D& rhs);

    friend Vector4D operator*(const Vector4D& lhs, const Vector4D& rhs);
    Vector4D& operator*=(const Vector4D& rhs);
    friend Vector4D operator*(const Vector4D& lhs, double rhs);
    Vector4D& operator*=(double rhs);

    friend Vector4D operator/(const Vector4D& lhs, const Vector4D& rhs);
    Vector4D& operator/=(const Vector4D& rhs);

    friend bool operator==(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator!=(const Vector4D& lhs, const Vector4D& rhs);

    friend bool operator<(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator>(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator<=(const Vector4D& lhs, const Vector4D& rhs);
    friend bool operator>=(const Vector4D& lhs, const Vector4D& rhs);
    
    friend bool operator!(const Vector4D& rhs);

    friend Vector4D operator-(const Vector4D& rhs);

    void print() const;

};
