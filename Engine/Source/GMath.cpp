#include <GMath.h>
#include <iostream>

#pragma region Vec2 

//------------------------------------------------------------------------------------------------

Vec2 Vec2::operator+(const Vec2& _v) const { return Vec2(x + _v.x, y + _v.y); }
Vec2 Vec2::operator-(const Vec2& _v) const { return Vec2(x - _v.x, y - _v.y); }
Vec2 Vec2::operator*(const Vec2& _v) const { return Vec2(x * _v.x, y * _v.y); }
Vec2 Vec2::operator*(const float _val) const { return Vec2(x * _val, y * _val); }
Vec2 Vec2::operator/(const float _val) const { return Vec2(x / _val, y / _val); }
Vec2 Vec2::operator-() const { return Vec2(-x, -y); }

Vec2& Vec2::operator+=(const Vec2& _v) { x += _v.x; y += _v.y; return *this; }
Vec2& Vec2::operator-=(const Vec2& _v) { x -= _v.x; y -= _v.y; return *this; }
Vec2& Vec2::operator*=(const Vec2& _v) { x *= _v.x; y *= _v.y; return *this; }
Vec2& Vec2::operator*=(const float _val) { x *= _val; y *= _val; return *this; }
Vec2& Vec2::operator/=(const float _val) { x /= _val; y /= _val; return *this; }

float Vec2::LengthSq(void) const { return SQ(x) + SQ(y); }
float Vec2::Lenght(void) const { return sqrtf(LengthSq()); }

Vec2 Vec2::Normalize(void)
{
	float len = Lenght();
	return len > 0 ? *this / len : *this;
}

float Vec2::NormalizeGetLength(void)
{
	float len = Lenght();
	if (len > 0)
		*this /= len;
	return len;
}

float Vec2::Max() const { return max(x, y); }
float Vec2::Min() const { return min(x, y); }

Vec2 Vec2::Max(const Vec2& _v1, const Vec2& _v2) { return Vec2(max(_v1.x, _v2.x), max(_v1.y, _v2.y)); }
Vec2 Vec2::Min(const Vec2& _v1, const Vec2& _v2) { return Vec2(min(_v1.x, _v2.x), min(_v1.y, _v2.y)); }

float Vec2::Dot(const Vec2& _v1, const Vec2& _v2) { return _v1.x * _v2.x + _v1.y * _v2.y; }
float Vec2::Cross(const Vec2& _v1, const Vec2& _v2) { return _v1.x * _v2.y - _v1.y * _v2.x; }

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region Vec3 

//------------------------------------------------------------------------------------------------

Vec3 Vec3::operator+(const Vec3& _v) const { return Vec3(x + _v.x, y + _v.y, z + _v.z); }
Vec3 Vec3::operator-(const Vec3& _v) const { return Vec3(x - _v.x, y - _v.y, z - _v.z); }
Vec3 Vec3::operator*(const Vec3& _v) const { return Vec3(x * _v.x, y * _v.y, z * _v.z); }
Vec3 Vec3::operator*(const float _val) const { return Vec3(x * _val, y * _val, z * _val); }
Vec3 Vec3::operator/(const float _val) const { return Vec3(x / _val, y / _val, z / _val); }
Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }

Vec3& Vec3::operator+=(const Vec3& _v) { x += _v.x; y += _v.y; z += _v.z; return *this; }
Vec3& Vec3::operator-=(const Vec3& _v) { x -= _v.x; y -= _v.y; z -= _v.z; return *this; }
Vec3& Vec3::operator*=(const Vec3& _v) { x *= _v.x; y *= _v.y; z *= _v.z; return *this; }
Vec3& Vec3::operator*=(const float _val) { x *= _val; y *= _val; z *= _val; return *this; }
Vec3& Vec3::operator/=(const float _val) { x /= _val; y /= _val; z /= _val; return *this; }

float Vec3::LengthSq(void) const { return SQ(x) + SQ(y) + SQ(z); }
float Vec3::Length(void) const { return sqrtf(LengthSq()); }

Vec3 Vec3::Normalize(void)
{
	float len = Length();
	return len > 0 ? *this / len : *this;
}

float Vec3::NormalizeGetLength(void)
{
	float len = Length();
	if (len > 0)
		*this /= len;
	return len;
}

float Vec3::Dot(const Vec3& _v1, const Vec3& _v2) {
	return _v1.x * _v2.x + _v1.y * _v2.y + _v1.z * _v2.z;
}

Vec3 Vec3::Cross(const Vec3& _v1, const Vec3& _v2)
{
	return Vec3(_v2.y * _v1.z - _v2.z * _v1.y,
		_v2.z * _v1.x - _v2.x * _v1.z,
		_v2.x * _v1.y - _v2.y * _v1.x);
}

float Vec3::Max(void) const { return max(x, max(y, z)); }
float Vec3::Min(void) const { return min(x, min(y, z)); }

Vec3 Vec3::Max(const Vec3& v1, const Vec3& v2)
{
	return Vec3(max(v1.x, v2.x),
		max(v1.y, v2.y),
		max(v1.z, v2.z));
}

Vec3 Vec3::Min(const Vec3& v1, const Vec3& v2)
{
	return Vec3(min(v1.x, v2.x),
		min(v1.y, v2.y),
		min(v1.z, v2.z));
}

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region Vec4

//------------------------------------------------------------------------------------------------

Vec4 Vec4::operator+(const Vec4& _v) const { return Vec4(x + _v.x, y + _v.y, z + _v.z, _v.w + w); }
Vec4 Vec4::operator-(const Vec4& _v) const { return Vec4(x - _v.x, y - _v.y, z - _v.z, _v.w - w); }
Vec4 Vec4::operator*(const Vec4& _v) const { return Vec4(x * _v.x, y * _v.y, z * _v.z, _v.w * w); }
Vec4 Vec4::operator*(const float _val) const { return Vec4(x * _val, y * _val, z * _val, w * _val); }
Vec4 Vec4::operator/(const float _val) const { return Vec4(x / _val, y / _val, z / _val, w / _val); }
Vec4 Vec4::operator-() const { return Vec4(-x, -y, -z, -w); }

Vec4& Vec4::operator+=(const Vec4& _v) { x += _v.x; y += _v.y; z += _v.z; w += _v.w; return *this; }
Vec4& Vec4::operator-=(const Vec4& _v) { x -= _v.x; y -= _v.y; z -= _v.z; w -= _v.w; return *this; }
Vec4& Vec4::operator*=(const Vec4& _v) { x *= _v.x; y *= _v.y; z *= _v.z; w *= _v.w; return *this; }
Vec4& Vec4::operator*=(const float _val) { x *= _val; y *= _val; z *= _val; w *= _val; return *this; }
Vec4& Vec4::operator/=(const float _val) { x /= _val; y /= _val; z /= _val; w /= _val; return *this; }

float Vec4::LengthSq(void) const { return SQ(x) + SQ(y) + SQ(z) + SQ(w); }
float Vec4::Length(void) const { return sqrtf(LengthSq()); }

Vec4 Vec4::Normalize(void)
{
	float len = Length();
	return len > 0 ? *this / len : *this;
}

Vec4 Vec4::Project(void) { return w > 0 ? *this / w : *this; }

float Vec4::NormalizeGetLength(void)
{
	float len = Length();
	if (len > 0)
		*this /= len;
	return len;
}

float Vec4::Max() const { return max(x, max(y, max(w, z))); }

Vec4 Vec4::Max(const Vec4& v1, const Vec4& v2)
{
	return Vec4(max(v1.x, v2.x),
		max(v1.y, v2.y),
		max(v1.z, v2.z),
		max(v1.w, v2.w));
}

float Vec4::Dot(const Vec4& _v1, const Vec4& _v2) {
	return _v1.x * _v2.x + _v1.y * _v2.y + _v1.z * _v2.z + _v1.w * _v2.w;
}

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region Matrix

//------------------------------------------------------------------------------------------------

Matrix::Matrix() { Identity(); }
Matrix::Matrix(float* _other) { memcpy(&m, _other, 16 * sizeof(float)); }

Matrix::Matrix(float _m1, float _m2, float _m3, float _m4,
	float _m5, float _m6, float _m7, float _m8,
	float _m9, float _m10, float _m11, float _m12,
	float _m13, float _m14, float _m15, float _m16)
{
	m[0] = _m1, m[1] = _m2, m[2] = _m3, m[3] = _m4;
	m[4] = _m5, m[5] = _m6, m[6] = _m7, m[7] = _m8;
	m[8] = _m9, m[9] = _m10, m[10] = _m11, m[11] = _m12;
	m[12] = _m13, m[13] = _m14, m[14] = _m15, m[15] = _m16;
}

void Matrix::Identity()
{
	memset(m, 0, 16 * sizeof(float));
	m[0] = m[5] = m[10] = m[15] = 1;
}

Matrix Matrix::Transpose() const
{
	Matrix mat;
	mat.m[0] = m[0], mat.m[1] = m[4], mat.m[2] = m[8], mat.m[3] = m[12];
	mat.m[4] = m[1], mat.m[5] = m[5], mat.m[6] = m[9], mat.m[7] = m[13];
	mat.m[8] = m[2], mat.m[9] = m[6], mat.m[10] = m[10], mat.m[11] = m[14];
	mat.m[12] = m[3], mat.m[13] = m[7], mat.m[14] = m[11], mat.m[15] = m[15];
	return mat;
}

Matrix Matrix::Translation(const Vec3 v)
{
	Matrix mat;
	mat.a[0][3] = v.x;
	mat.a[1][3] = v.y;
	mat.a[2][3] = v.z;
	return mat;
}

Matrix Matrix::Scaling(const Vec3 v)
{
	Matrix mat;
	mat.m[0] = v.x;
	mat.m[5] = v.y;
	mat.m[10] = v.z;
	return mat;
}

Matrix Matrix::RotateX(float angle)
{
	float sint = sin(angle), cost = cos(angle);
	Matrix mat;
	mat.m[5] = mat.m[10] = cost;
	mat.m[6] = -sint;
	mat.m[9] = sint;
	return mat;
}

Matrix Matrix::RotateY(float angle)
{
	float sint = sin(angle), cost = cos(angle);
	Matrix mat;
	mat.m[0] = mat.m[10] = cost;
	mat.m[8] = -sint;
	mat.m[2] = sint;
	return mat;
}

Matrix Matrix::RotateZ(float angle)
{
	float sint = sin(angle), cost = cos(angle);
	Matrix mat;
	mat.m[0] = mat.m[5] = cost;
	mat.m[1] = -sint;
	mat.m[0] = sint;
	return mat;
}

Matrix Matrix::Projection(float _fov, float _aspect, float _near, float _far)
{
	float dFov = _fov * M_PI / 180; // contains conversion from degree
	float tanHalfFov = tan(_fov / 2);
	Matrix _mat;
	_mat.m[0] = 1.0f / (_aspect * tanHalfFov);
	_mat.m[5] = -1.0f / tanHalfFov;
	_mat.m[10] = -_far / (_far - _near);
	_mat.m[11] = -(_far * _near) / (_far - _near);
	_mat.m[14] = -1.0f;
	_mat.m[15] = 0.0f;

	return _mat;
}

Matrix Matrix::LookAt(Vec3 _from, Vec3 _to, Vec3 _up)
{
	Vec3 forward = (_from - _to).Normalize();
	Vec3 right = Vec3::Cross(_up, forward);
	Vec3 up = Vec3::Cross(forward, right);

	Matrix mat;

	mat.a[0][0] = right.x;
	mat.a[0][1] = right.y;
	mat.a[0][2] = right.z;

	mat.a[1][0] = up.x;
	mat.a[1][1] = up.y;
	mat.a[1][2] = up.z;

	mat.a[2][0] = forward.x;
	mat.a[2][1] = forward.y;
	mat.a[2][2] = forward.z;

	mat.a[0][3] = -Vec3::Dot(_from, right);
	mat.a[1][3] = -Vec3::Dot(_from, up);
	mat.a[2][3] = -Vec3::Dot(_from, forward);

	return mat;
}

Matrix Matrix::View(Vec3 _pos, Vec3 _forward)
{
	_forward = _forward.Normalize();
	Vec3 right = Vec3::Cross(Vec3(0, 1, 0), _forward);
	Vec3 up = Vec3::Cross(_forward, right);

	Matrix mat;

	mat.a[0][0] = right.x;
	mat.a[1][0] = right.y;
	mat.a[2][0] = right.z;

	mat.a[0][1] = up.x;
	mat.a[1][1] = up.y;
	mat.a[2][1] = up.z;

	mat.a[0][2] = -_forward.x;
	mat.a[1][2] = -_forward.y;
	mat.a[2][2] = -_forward.z;

	mat.a[0][3] = -Vec3::Dot(_pos, right);
	mat.a[1][3] = -Vec3::Dot(_pos, up);
	mat.a[2][3] = Vec3::Dot(_pos, _forward);

	return mat;
}

Vec3 Matrix::MulPoint(const Vec3& v) const
{
	Vec3 v1 = Vec3(
		(v.x * m[0] + v.y * m[1] + v.z * m[2]) + m[3],
		(v.x * m[4] + v.y * m[5] + v.z * m[6]) + m[7],
		(v.x * m[8] + v.y * m[9] + v.z * m[10]) + m[11]);
	float w;
	w = m[12] * v.x + m[13] * v.y + m[14] * v.z + m[15];
	w = 1.0f / w;
	return (v1 * w);
}

Vec3 Matrix::MulVec(const Vec3& v)
{
	return Vec3(
		(v.x * m[0] + v.y * m[1] + v.z * m[2]) + m[3],
		(v.x * m[4] + v.y * m[5] + v.z * m[6]) + m[7],
		(v.x * m[8] + v.y * m[9] + v.z * m[10]) + m[11]);
}

Matrix Matrix::Mul(const Matrix& matrix) const
{
	Matrix ret;
	ret.m[0] = m[0] * matrix.m[0] + m[4] * matrix.m[1] + m[8] * matrix.m[2] + m[12] * matrix.m[3];
	ret.m[1] = m[1] * matrix.m[0] + m[5] * matrix.m[1] + m[9] * matrix.m[2] + m[13] * matrix.m[3];
	ret.m[2] = m[2] * matrix.m[0] + m[6] * matrix.m[1] + m[10] * matrix.m[2] + m[14] * matrix.m[3];
	ret.m[3] = m[3] * matrix.m[0] + m[7] * matrix.m[1] + m[11] * matrix.m[2] + m[15] * matrix.m[3];
	ret.m[4] = m[0] * matrix.m[4] + m[4] * matrix.m[5] + m[8] * matrix.m[6] + m[12] * matrix.m[7];
	ret.m[5] = m[1] * matrix.m[4] + m[5] * matrix.m[5] + m[9] * matrix.m[6] + m[13] * matrix.m[7];
	ret.m[6] = m[2] * matrix.m[4] + m[6] * matrix.m[5] + m[10] * matrix.m[6] + m[14] * matrix.m[7];
	ret.m[7] = m[3] * matrix.m[4] + m[7] * matrix.m[5] + m[11] * matrix.m[6] + m[15] * matrix.m[7];
	ret.m[8] = m[0] * matrix.m[8] + m[4] * matrix.m[9] + m[8] * matrix.m[10] + m[12] * matrix.m[11];
	ret.m[9] = m[1] * matrix.m[8] + m[5] * matrix.m[9] + m[9] * matrix.m[10] + m[13] * matrix.m[11];
	ret.m[10] = m[2] * matrix.m[8] + m[6] * matrix.m[9] + m[10] * matrix.m[10] + m[14] * matrix.m[11];
	ret.m[11] = m[3] * matrix.m[8] + m[7] * matrix.m[9] + m[11] * matrix.m[10] + m[15] * matrix.m[11];
	ret.m[12] = m[0] * matrix.m[12] + m[4] * matrix.m[13] + m[8] * matrix.m[14] + m[12] * matrix.m[15];
	ret.m[13] = m[1] * matrix.m[12] + m[5] * matrix.m[13] + m[9] * matrix.m[14] + m[13] * matrix.m[15];
	ret.m[14] = m[2] * matrix.m[12] + m[6] * matrix.m[13] + m[10] * matrix.m[14] + m[14] * matrix.m[15];
	ret.m[15] = m[3] * matrix.m[12] + m[7] * matrix.m[13] + m[11] * matrix.m[14] + m[15] * matrix.m[15];
	return ret;
}

Matrix Matrix::Inverse() const
{
	Matrix inv;
	inv[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
	inv[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
	inv[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
	inv[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
	inv[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
	inv[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
	inv[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
	inv[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
	inv[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
	inv[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
	inv[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
	inv[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
	inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
	inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
	inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
	inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

	float det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

	if (det == 0) {
		// Handle this case
	}
	det = 1.0 / det;

	for (int i = 0; i < 16; i++)
		inv[i] = inv[i] * det;

	return inv;
}

float& Matrix::operator[](int _index) { return m[_index]; }
Matrix Matrix::operator*(Matrix& _other) { return Mul(_other); }

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region Color

//------------------------------------------------------------------------------------------------

Color::Color() { r = g = b = a = 1; }

Color::Color(float _r, float _g, float _b, float _a)
{
	r = clamp(_r, 0, 1);
	g = clamp(_g, 0, 1);
	b = clamp(_b, 0, 1);
	a = clamp(_a, 0, 1);
}

Color Color::operator+(const Color& _col)
{
	return Color(clamp(r + _col.r, 0, 1),
		clamp(g + _col.g, 0, 1),
		clamp(b + _col.b, 0, 1),
		clamp(a + _col.a, 0, 1));
}

Color Color::operator-(const Color& _col)
{
	return Color(clamp(r - _col.r, 0, 1),
		clamp(g - _col.g, 0, 1),
		clamp(b - _col.b, 0, 1),
		clamp(a - _col.a, 0, 1));
}

Color Color::operator*(const Color& _col)
{
	return Color(clamp(r * _col.r, 0, 1),
		clamp(g * _col.g, 0, 1),
		clamp(b * _col.b, 0, 1),
		clamp(a * _col.a, 0, 1));
}

Color Color::operator*(const float _val)
{
	return Color(clamp(r * _val, 0, 1),
		clamp(g * _val, 0, 1),
		clamp(b * _val, 0, 1),
		clamp(a * _val, 0, 1));
}

Color Color::operator/(const float _val)
{
	return Color(clamp(r / _val, 0, 1),
		clamp(g / _val, 0, 1),
		clamp(b / _val, 0, 1),
		clamp(a / _val, 0, 1));
}

Color& Color::operator+=(const Color& _col)
{
	r = clamp(r + _col.r, 0, 1);
	g = clamp(g + _col.g, 0, 1);
	b = clamp(b + _col.b, 0, 1);
	a = clamp(a + _col.a, 0, 1);
	return *this;
}

Color& Color::operator-=(const Color& _col)
{
	r = clamp(r - _col.r, 0, 1);
	g = clamp(g - _col.g, 0, 1);
	b = clamp(b - _col.b, 0, 1);
	a = clamp(a - _col.a, 0, 1);
	return *this;
}

Color& Color::operator*=(const Color& _col)
{
	r = clamp(r * _col.r, 0, 1);
	g = clamp(r * _col.g, 0, 1);
	b = clamp(r * _col.b, 0, 1);
	a = clamp(r * _col.a, 0, 1);
	return *this;
}

Color& Color::operator*=(const float _val)
{
	r = clamp(r * _val, 0, 1);
	g = clamp(r * _val, 0, 1);
	b = clamp(r * _val, 0, 1);
	a = clamp(r * _val, 0, 1);
	return *this;
}

Color& Color::operator/=(const float _val)
{
	r = clamp(r / _val, 0, 1);
	g = clamp(g / _val, 0, 1);
	b = clamp(b / _val, 0, 1);
	a = clamp(a / _val, 0, 1);
	return *this;
}

float Color::operator[](int index) { return v[index]; }

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region Shading Frame

//------------------------------------------------------------------------------------------------

ShadingFrame::ShadingFrame(Vec3& _normal)
{
	_normal = _normal.Normalize();

	Vec3 tmp = std::abs(_normal.x) > 0.9f ? Vec3(0, 1, 0) : Vec3(1, 0, 0);
	Vec3 u = Vec3::Cross(_normal, tmp).Normalize();
	Vec3 v = Vec3::Cross(_normal, u).Normalize();

	m[0] = u.x; m[1] = v.x; m[2] = _normal.x;
	m[3] = u.y; m[4] = v.y; m[5] = _normal.y;
	m[6] = u.z; m[7] = v.z; m[8] = _normal.z;
}

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region Quaternion

//------------------------------------------------------------------------------------------------

float Quaternion::LengthSq() const { return SQ(a) + SQ(b) + SQ(c) + SQ(d); }
float Quaternion::Length() const { return sqrt(LengthSq()); }

float Quaternion::Dot(Quaternion& _q1, Quaternion& _q2) { return _q1.a * _q2.a + _q1.b * _q2.b + _q1.c * _q2.c + _q1.d + _q2.d; }

Quaternion Quaternion::Slerp(Quaternion& _q1, Quaternion& _q2, float _time)
{
	float _dot = Dot(_q1, _q2);
	float angle = _dot < 0 ? acos(-_dot) : acos(_dot); // finding shortest path
	float sint = sin(angle), sintr = sin(angle * (1 - _time)), sintt = sin(angle * _time);
	return (_q1 * sintr + _q2 * sintt) / sint;
}

Quaternion Quaternion::Normalize()
{
	float len = Length();
	return len > 0 ? *this / len : *this;
}

Matrix Quaternion::ToMatrix() const
{
	Matrix _mat;

	_mat.a[0][0] = 1 - 2 * SQ(c) - 2 * SQ(d);
	_mat.a[0][1] = 2 * b * c - 2 * a * d;
	_mat.a[0][1] = 2 * b * d + 2 * a * c;

	_mat.a[1][0] = 2 * b * c + 2 * a * d;
	_mat.a[1][1] = 1 - 2 * SQ(b) - 2 * SQ(d);
	_mat.a[1][2] = 2 * c * d - 2 * a * b;

	_mat.a[2][0] = 2 * b * d - 2 * a * c;
	_mat.a[2][1] = 2 * c * d + 2 * a * b;
	_mat.a[2][2] = 1 - 2 * SQ(b) - 2 * SQ(c);

	return _mat;
}

Quaternion Quaternion::Conjugate() { return Quaternion(a, -b, -c, -d); }
Quaternion Quaternion::Inverse() { return Conjugate() / Length(); }

Vec3 Quaternion::RotatePoint(Vec3 _v)
{
	Normalize();
	Quaternion _point(0, _v.x, _v.y, _v.z);
	Quaternion conj = Conjugate();
	Quaternion res = (*this) * _point * conj;
	return Vec3(res.b, res.c, res.d);
}

Quaternion Quaternion::operator+(const Quaternion& _other) { return Quaternion(a + _other.a, b + _other.b, c + _other.c, d + _other.d); }
Quaternion Quaternion::operator-(const Quaternion& _other) { return Quaternion(a - _other.a, b - _other.b, c - _other.c, d - _other.d); }
Quaternion Quaternion::operator*(const float _val) { return Quaternion(a * _val, b * _val, c * _val, d * _val); }
Quaternion Quaternion::operator/(const float _val) { return Quaternion(a / _val, b / _val, c / _val, d / _val); }

Quaternion& Quaternion::operator+=(const Quaternion& _other) { a += _other.a; b += _other.b; c += _other.c; d += _other.d; return *this; }
Quaternion& Quaternion::operator-=(const Quaternion& _other) { a -= _other.a; b -= _other.b; c -= _other.c; d -= _other.d; return *this; }
Quaternion& Quaternion::operator*=(const float _val) { a *= _val; b *= _val; c *= _val; d *= _val; return *this; }
Quaternion& Quaternion::operator/=(const float _val) { a /= _val; b /= _val; c /= _val; d /= _val; return *this; }

Quaternion Quaternion::operator*(const Quaternion& _qt)
{
	return Quaternion(
		a * _qt.a - b * _qt.b - c * _qt.c - d * _qt.d,
		a * _qt.b + b * _qt.a + c * _qt.d - d * _qt.c,
		a * _qt.c - b * _qt.d + c * _qt.a + d * _qt.b,
		a * _qt.d + b * _qt.c - c * _qt.b + d * _qt.a
	);
}

Quaternion Quaternion::operator*=(const Quaternion& _qt)
{
	a = a * _qt.a - b * _qt.b - c * _qt.c - d * _qt.d;
	b = a * _qt.b + b * _qt.a + c * _qt.d - d * _qt.c;
	c = a * _qt.c - b * _qt.d + c * _qt.a + d * _qt.b;
	d = a * _qt.d + b * _qt.c - c * _qt.b + d * _qt.a;
	return *this;
}

Vec3 Quaternion::operator*(const Vec3& _v) { return RotatePoint(_v); }

//------------------------------------------------------------------------------------------------

#pragma endregion

#pragma region ostream operator

//------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, Vec2 _v) {
	return os << "(" << _v.x << "," << _v.y << ")";
}

std::ostream& operator<<(std::ostream& os, Vec3 _v) {
	return os << "(" << _v.x << "," << _v.y << "," << _v.z << ")";
}

std::ostream& operator<<(std::ostream& os, Vec4 _v) {
	return os << "(" << _v.x << "," << _v.y << "," << _v.z << "," << _v.w << ")";
}

std::ostream& operator<<(std::ostream& os, Matrix _mat)
{
	os << "[" << _mat[0] << "," << _mat[1] << "," << _mat[2] << "," << _mat[3] << "]\n";
	os << "[" << _mat[4] << "," << _mat[5] << "," << _mat[6] << "," << _mat[7] << "]\n";
	os << "[" << _mat[8] << "," << _mat[9] << "," << _mat[10] << "," << _mat[11] << "]\n";
	os << "[" << _mat[12] << "," << _mat[13] << "," << _mat[14] << "," << _mat[15] << "]\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, Color& _color)
{
	os << "(" << static_cast<int>(_color.r) << ","
		<< static_cast<int>(_color.g) << ","
		<< static_cast<int>(_color.b) << ","
		<< static_cast<int>(_color.a) << ")\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, ShadingFrame& _sf)
{
	std::cout << "[" << _sf.m[0] << "," << _sf.m[1] << "," << _sf.m[2] << "]\n";
	std::cout << "[" << _sf.m[3] << "," << _sf.m[4] << "," << _sf.m[5] << "]\n";
	std::cout << "[" << _sf.m[6] << "," << _sf.m[7] << "," << _sf.m[8] << "]\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, Quaternion& _quat)
{
	os << "(" << _quat.a << "," << _quat.b << "," << _quat.c << "," << _quat.d << ")";
	return os;
}

//------------------------------------------------------------------------------------------------

#pragma endregion