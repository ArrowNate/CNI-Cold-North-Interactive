#ifndef __MATHHELPER_H
#define __MATHHELPER_H
#include <math.h>

// I dont know if we need math helper tbh, 
// There is already a glm::vec3 data type

#define PI 3.1415926535f
#define DEG_TO_RAD PI / 180.0f
#define RAD_TO_DEG 180.0f / PI

//------------------3D Vectors-----------------------------------------
	struct Vector3 {
		float x;
		float y;
		float z;

		Vector3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
			: x{ _x }, y{ _y }, z{ _z } {}

		float MagnitudeSqr() const {
			return x * x + y * y + z * z;
		}

		float Magnitude() const {
			return (float)sqrt(x * x + y * y + z * z);
		}

		Vector3 Normalized() const {
			float mag = Magnitude();
			if (mag == 0.0f) {
				return Vector3(0.0f, 0.0f, 0.0f);
			}
			else {
				return Vector3(x / mag, y / mag, z / mag);
			}
		}

		Vector3& operator+=(const Vector3& rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		Vector3& operator-=(const Vector3& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		Vector3 operator-() const {
			return Vector3(-x, -y, -z);
		}
	};

	inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs) {
		return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
	}

	inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs) {
		return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	inline Vector3 operator*(const Vector3& lhs, float rhs) {
		return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
	}

	inline Vector3 operator*(float lhs, const Vector3& rhs) {
		return Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
	}

	inline Vector3 operator/(const Vector3& lhs, float rhs) {
		return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.y / rhs);
	}

	inline Vector3 operator/(float lhs, const Vector3& rhs) {
		return Vector3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.x);
	}

	inline Vector3 Lerp(const Vector3& start, const Vector3& end, float time) {
		if (time <= 0.0f) {
			return start;
		}

		if (time >= 1.0f) {
			return end;
		}

		Vector3 dir = (end - start).Normalized();
		float mag = (end - start).Magnitude();

		return start + dir * mag * time;
	}

	inline Vector3 RotateVector(const Vector3& vec, float angle) {
		float radAngle = (float)(angle * DEG_TO_RAD);

		return Vector3(
			(float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)),
			(float)(vec.x * sin(radAngle) + vec.y * cos(radAngle))
		);
	}

	// will add 3d by adding z positions once we can test them.  -mikaelo
	const Vector3 Vec3_Zero = { 0.0f, 0.0f };
	const Vector3 Vec3_One = { 1.0f, 1.0f };
	const Vector3 Vec3_Up = { 0.0f, 1.0f };
	const Vector3 Vec3_Right = { 1.0f, 0.0f };

	// cubic bezier curve
	struct BezierCurve {
		Vector3 p0;
		Vector3 p1;
		Vector3 p2;
		Vector3 p3;

		Vector3 CalculatePointAlongCurve(float t) {
			float tt = t * t;
			float ttt = tt * t;
			float u = 1.0f - t;
			float uu = u * u;
			float uuu = uu * u;

			Vector3 point = (uuu * p0) + (3 * uu * t * p1) + (3 * u * tt * p2) + (ttt * p3);
			point.x = (float)round(point.x);
			point.y = (float)round(point.y);
			point.z = (float)round(point.z);
			return point;
		}
	};

	struct Vertex3D {
		Vector3 position;

		struct UV {
			float u;
			float v;
		} uv;

		struct Color {
			float r;
			float g;
			float b;
			float a;
		} color;


		void SetPosition(float x, float y, float z) {
			position.x = x;
			position.y = y;
			position.z = z;
		}
		void SetUV(float u, float v) {
			uv.u = u;
			uv.v = v;
		}
		void SetColor(float r, float g, float b, float a) {
			color.r = r;
			color.g = g;
			color.b = b;
			color.a = a;
		}
	};
//------------------3D Vectors-----------------------------------------

//------------------2D Vectors-----------------------------------------
	struct Vector2 {
		float x;
		float y;

		Vector2(float _x = 0.0f, float _y = 0.0f)
			: x{ _x }, y{ _y } {}

		float MagnitudeSqr() const {
			return x * x + y * y;
		}

		float Magnitude() const {
			return (float)sqrt(x * x + y * y);
		}

		Vector2 Normalized() const {
			float mag = Magnitude();
			if (mag == 0.0f) {
				return Vector2(0.0f, 0.0f);
			}
			else {
				return Vector2(x / mag, y / mag);
			}
		}

		Vector2& operator+=(const Vector2& rhs) {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		Vector2& operator-=(const Vector2& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		Vector2 operator-() const {
			return Vector2(-x, -y);
		}
	};

	inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	inline Vector2 operator*(const Vector2& lhs, float rhs) {
		return Vector2(lhs.x * rhs, lhs.y * rhs);
	}

	inline Vector2 operator*(float lhs, const Vector2& rhs) {
		return Vector2(lhs * rhs.x, lhs * rhs.y);
	}

	inline Vector2 operator/(const Vector2& lhs, float rhs) {
		return Vector2(lhs.x / rhs, lhs.y / rhs);
	}

	inline Vector2 operator/(float lhs, const Vector2& rhs) {
		return Vector2(lhs / rhs.x, lhs / rhs.y);
	}

	inline Vector2 Lerp(const Vector2& start, const Vector2& end, float time) {
		if (time <= 0.0f) {
			return start;
		}

		if (time >= 1.0f) {
			return end;
		}

		Vector2 dir = (end - start).Normalized();
		float mag = (end - start).Magnitude();

		return start + dir * mag * time;
	}

	inline Vector2 RotateVector(const Vector2& vec, float angle) {
		float radAngle = (float)(angle * DEG_TO_RAD);

		return Vector2(
			(float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)),
			(float)(vec.x * sin(radAngle) + vec.y * cos(radAngle))
		);
	}

	const Vector2 Vec2_Zero = { 0.0f, 0.0f };
	const Vector2 Vec2_One = { 1.0f, 1.0f };
	const Vector2 Vec2_Up = { 0.0f, 1.0f };
	const Vector2 Vec2_Right = { 1.0f, 0.0f };


	struct Vertex2 {
		Vector2 position;

		struct UV {
			float u;
			float v;
		} uv;

		struct Color {
			float r;
			float g;
			float b;
			float a;
		} color;


		void SetPosition(float x, float y) {
			position.x = x;
			position.y = y;
		}
		void SetUV(float u, float v) {
			uv.u = u;
			uv.v = v;
		}
		void SetColor(float r, float g, float b, float a) {
			color.r = r;
			color.g = g;
			color.b = b;
			color.a = a;
		}
	};
//------------------2D Vectors-----------------------------------------
#endif
