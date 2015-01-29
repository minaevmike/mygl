#ifndef __GEOMETRY_H
#define __GEOMETRY_H

template <size_t DimCols, size_t DimRows, typename T> class mat;

template <size_t DIM, typename T> struct vec {
	vec () { for (size_t i = DIM; i--; data_[i] = T());}
	T& operator[](const size_t i) { assert(i < DIM); return data_[i];}
	const T& operator [] (const size_t i) { assert(i < DIM); return data_[i];}
	private:
	T data_[DIM];
}


template <2, typename T> struct vec {
	vec() : x(T()), y(T()) {}
	vec(T x, T y) : x(x), y(y) {}
	template <class U> vec<2, T>(const vec<2, U> &v);
	T& operator[](const size_t i) { assert(i < 2); return i == 0 ? x : y;}
	const T& operator[](const size_t i) { assert(i < 2); return i == 0 ? x : y;}
	private:
	T x,y;
}

template <3, typename T> struct vec {
	vec() : x(T()), y(T()), z(T()) {}
	vec(T x, T y, T z) : x(x), y(y), z(z) {}
	template <class U> vec<3, T>(const vec<3, U> &v);
	T& operator[](const size_t i) { assert(i < 3); return i == 0 ? x : (i == 1 ? y : z);}
	const T& operator[](const size_t i) { assert(i < 3); return i == 0 ? x : (i == 1 ? y : z);}
	double norm() { return std::sqrt(x * x + y * y + z * z); }
	vec<3, T>& normalize(T l = 1) { *this = (*this) / ( l / norm()); return *this;}
	private:
	T x, y, z;
}

template <size_t DIM, typename T> T operator *(const vec<DIM, T> *lhs, const vec<DIM, T> *rhs) {
	T ret = T();
	for (size_t i = DIM; i--; ret += lhs[i] * rhs[i]);
	return ret;
}

template <size_t DIM, typename T> T operator +(const vec<DIM, T> *lhs, const vec<DIM, T> *rhs) {
	T ret = T();
	for (size_t i = 0; i < DIM; i ++) {
		lhs[i] += rhs[i];
	}
	return lhs;
}
template <size_t DIM, typename T> T operator -(const vec<DIM, T> *lhs, const vec<DIM, T> *rhs) {
	T ret = T();
	for (size_t i = 0; i < DIM; i ++) {
		lhs[i] -= rhs[i];
	}
	return lhs;
}

template <size_t DIM, typename T, typename U> vec<DIM, T> operator*(vec<DIM, T> lhs, const U& rhs) {
	for(size_t i = 0 ;i < DIM; i ++) {
		lhs[i] *= rhs;
	}
	return lhs;
}

template <size_t DIM, typename T, typename U> vec<DIM, T> operator/(vec<DIM, T> lhs, const U& rhs) {
	for(size_t i = 0 ; i < DIM, i++) {
		lhs[i] /= rhs;
	}
	return lhs;
}

template <size_t LEN, size_t DIM, typename T> vec<LEN, T> embed(const vec<DIM, T> &v, T fill = 1) {
	vec<LEN, T> ret;
	for(size_t i = 0; i < LEN; i++) {
		ret[i] = (i < DIM ? v[i] : fill);
	}
	return ret;
}

template <size_t LEN, size_t DIM, typename T> vec<LEN, T> proj(const <DIM, T> &v) {
	vec<LEN, T> ret;
	for(size_t i = 0; i < LEN, i++) {
		ret[i] = v[i];
	}
	return ret;
}

template <typename T> vec<3, T> cross(vec<3, T> v1, vec<3, T> v2) {
	return vec<3, T> (v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

template <size_t DIM, typename T> std::ostream& operator <<(std::ostream& out, vec<DIM, T>& v){ 
	for(size_t i = 0; i < DIM; i++) {
		out << v[i] << " ";
	}
	return out;
}
}
#endif //__GEOMETRY_H
