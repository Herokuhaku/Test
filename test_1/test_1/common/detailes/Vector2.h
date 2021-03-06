#include "../Vector2.h"

template <class T>
Vector2Template<T>::Vector2Template()
{
	x = 0;
	y = 0;
}

template <class T>
Vector2Template<T>::Vector2Template(T x_, T y_)
{
	x = x_;
	y = y_;
}

template <class T>
Vector2Template<T>& Vector2Template<T>::operator=(const Vector2Template<T>& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
}

template <class T>
Vector2Template<T>& Vector2Template<T>::operator+=(const Vector2Template<T>& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

template <class T>
Vector2Template<T>& Vector2Template<T>::operator-=(const Vector2Template<T>& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

template <class T>
Vector2Template<T>& Vector2Template<T>::operator*=(const Vector2Template<T>& vec)
{
	x *= vec.x;
	y *= vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

template <class T>
Vector2Template<T>& Vector2Template<T>::operator/=(const Vector2Template<T>& vec)
{
	!vec.x ? x = 1000000000 : x /= vec.x;
	!vec.y ? y = 1000000000 : y /= vec.y;
	return *this;
	// TODO: return ステートメントをここに挿入します
}

template <class T>
bool Vector2Template<T>::operator>=(const Vector2Template<T>& vec)const
{
	return (x >= vec.x && y >= vec.y);
}

template <class T>
bool Vector2Template<T>::operator<=(const Vector2Template<T>& vec) const
{
	return (x <= vec.x && y <= vec.y);
}

template <class T>
bool Vector2Template<T>::operator>(const Vector2Template<T>& vec) const
{
	return (x > vec.x && y > vec.y);
}

template <class T>
bool Vector2Template<T>::operator<(const Vector2Template<T>& vec) const
{
	return (x < vec.x && y < vec.y);
}

template <class T>
bool Vector2Template<T>::operator==(const Vector2Template<T>& vec) const
{
	return (x == vec.x && y == vec.y);
}

template <class T>
bool Vector2Template<T>::operator!=(const Vector2Template<T>& vec) const
{
	return (x != vec.x && y != vec.y);
}

template <class T>
bool Vector2Template<T>::operator&&(const Vector2Template<T>& vec) const
{
	return ((x && vec.x) && (y && vec.y));
}

template <class T>
bool Vector2Template<T>::operator||(const Vector2Template<T>& vec) const
{
	return ((x || vec.x) || (y || vec.y));
}

template <class T>
T& Vector2Template<T>::operator[](const int& num)
{
	if (!num)
	{
		return x;
	}
	else if (num == 1)
	{
		return y;
	}
	return x;
	// TODO: return ステートメントをここに挿入します
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator+(const Vector2Template<T>& vec)const
{
	return Vector2Template<T>(x + vec.x,y + vec.y);
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator-(const Vector2Template<T>& vec)const
{
	return Vector2Template<T>(x - vec.x,y - vec.y);
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator*(const Vector2Template<T>& vec)const
{
	return Vector2Template<T>(x * vec.x, y * vec.y);
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator/(const Vector2Template<T>& vec)const
{
	Vector2Template<T> tmp(0,0);
	!vec.x ? tmp.x = 1000000000 : x / vec.x;
	!vec.y ? tmp.y = 1000000000 : y / vec.y;

	return tmp;
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator%(const Vector2Template<T>& vec) const
{
	Vector2Template<T> tmp(0,0);
	!vec.x ? tmp.x = 1000000000 : x % vec.x;
	!vec.y ? tmp.y = 1000000000 : y % vec.y;
	return tmp;
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator+()const
{
	return Vector2Template<T>(x,y);
	//return Vector2(x+tmp.x,y+tmp.y);
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator-()const
{
	return Vector2Template<T>(-x,-y);
}

template <class T>
Vector2Template<T>& Vector2Template<T>::operator++()
{
	x++;
	y++;
	return *this;
}

template <class T>
Vector2Template<T> Vector2Template<T>::operator++(int)
{
	Vector2Template<T> tmp = *this;
	++*this;
	return tmp;
	// TODO: return ステートメントをここに挿入します
}

template <class T>
Vector2Template<T> operator+(const Vector2Template<T>& vec, const int& num)
{
	return Vector2Template<T>(vec.x + num,vec.y + num);
}

template <class T>
Vector2Template<T> operator-(const Vector2Template<T>& vec, const int& num)
{
	return Vector2Template<T>(vec.x - num, vec.y - num);
}

template <class T>
Vector2Template<T> operator*(const Vector2Template<T>& vec, const int& num)
{
	return Vector2Template<T>(vec.x * num, vec.y * num);
}

template <class T>
Vector2Template<T> operator/(const Vector2Template<T>&vec, const int& num)
{
	if (!num)
	{
		return Vector2Template<T>(1000000000, 1000000000);
	}
	return Vector2Template<T>(vec.x / num, vec.y / num);
}

template <class T>
Vector2Template<T> operator+(const int& num, const Vector2Template<T>& vec)
{
	return Vector2Template<T>(num + vec.x,num + vec.y);
}

template <class T>
Vector2Template<T> operator-(const int& num, const Vector2Template<T>& vec)
{
	return Vector2Template<T>(num - vec.x, num - vec.y);
}

template <class T>
Vector2Template<T> operator*(const int& num, const Vector2Template<T>& vec)
{
	return Vector2Template<T>(num * vec.x,num * vec.y);
}

template <class T>
Vector2Template<T> operator/(const int& num, const Vector2Template<T>& vec)
{
	return Vector2Template<T>(num / vec.x,num/vec.y);
}

template <class T>
Vector2Template<T> operator+(const Vector2Template<T>& vec, const float& num)
{
	return Vector2Template<T>(vec.x + num,vec.y + num);
}

template <class T>
Vector2Template<T> operator-(const Vector2Template<T>& vec, const float& num)
{
	return Vector2Template<T>(vec.x - num, vec.y - num);
}

template <class T>
Vector2Template<T> operator*(const Vector2Template<T>& vec, const float& num)
{
	return Vector2Template<T>(vec.x * num, vec.y * num);
}

template <class T>
Vector2Template<T> operator/(const Vector2Template<T>& vec, const float& num)
{
	if (!num)
	{
		return Vector2Template<T><T>(1000000000, 1000000000);
	}
	return Vector2Template<T>(vec.x / num, vec.y / num);
}
