#pragma once

#include <iostream>

namespace Math {

    template <typename TL>
    class Coord {
    public:
        TL x;
        TL y;

    public:
        Coord(TL x, TL y);
        Coord();
        ~Coord() { }

        void operator=(Coord<TL> other);
        void operator+=(Coord<TL> other);
        void operator-=(Coord<TL> other);
        void operator*=(double scalar);
        void operator/=(double scalar);

        Coord<TL> operator+(Coord<TL> other);
        Coord<TL> operator-(Coord<TL> other);
        Coord<TL> operator*(Coord<TL> other);
        Coord<TL> operator*(double scalar);
        Coord<TL> operator/(Coord<TL> other);
        Coord<TL> operator/(double scalar);
    };

    typedef Coord<double> CoordD;
    typedef Coord<float> CoordF;
    typedef Coord<int> CoordI;
    typedef Coord<unsigned int> CoordU;

    template <typename TL>
    Coord<TL>::Coord(TL x, TL y) :
    x(x),
    y(y) { }

    template <typename TL>
    Coord<TL>::Coord() {
        this->x = 0;
        this->y = 0;
    }

    template <typename TL>
    void Coord<TL>::operator=(Coord<TL> other) {
        this->x = other.x;
        this->y = other.y;
    }

    template <typename TL>
    void Coord<TL>::operator+=(Coord<TL> other) {
        this->x += other.x;
        this->y += other.y;
    }

    template <typename TL>
    void Coord<TL>::operator-=(Coord<TL> other) {
        this->x -= other.x;
        this->y -= other.y;
    }

    template <typename TL>
    void Coord<TL>::operator*=(double scalar) {
        this->x = this->x * scalar;
        this->y = this->y * scalar;
    }

    template <typename TL>
    void Coord<TL>::operator/=(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        this->x /= scalar;
        this->y /= scalar;
    }

    template <typename TL>
    Coord<TL> Coord<TL>::operator+(Coord<TL> other) {
        return Coord<TL>(this->x + other.x, this->y + other.y);
    }

    template <typename TL>
    Coord<TL> Coord<TL>::operator-(Coord<TL> other) {
        return Coord<TL>(this->x - other.x, this->y - other.y);
    }

    template <typename TL>
    Coord<TL> Coord<TL>::operator*(Coord<TL> other) {
        return Coord<TL>(this->x * other.x, this->y * other.y);
    }

    template <typename TL>
    Coord<TL> Coord<TL>::operator*(double scalar) {
        return Coord<TL>(this->x * scalar, this->y * scalar);
    }

    template <typename TL>
    Coord<TL> Coord<TL>::operator/(Coord<TL> other) {
        if (other.x == 0.0f || other.y == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        return Coord<TL>(this->x / other.x, this->y / other.y);
    }

    template <typename TL>
    Coord<TL> Coord<TL>::operator/(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }

        return Coord<TL>(this->x / scalar, this->y / scalar);
    }

}