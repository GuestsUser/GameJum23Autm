#pragma once
#include <deque>

class Quaternion;

class Vector3 { //���W����3�Z�߂Ĉ�����悤�ɂ�����
private:
	float x, y, z;
public:
	Vector3(float gx = 0, float gy = 0, float gz = 0) :x(gx), y(gy), z(gz) {} //�����l�𑴁X�ݒ肷��`���̃R���X�g���N�^�A�ݒ�͑S�ďȂ������ł���
	Vector3(const Vector3& pos) :x(pos.x), y(pos.y), z(pos.z) {} //�R�s�[�R���X�g���N�^�A���葤�̐��l�̃A�h���X��������肹���A�l���R�s�[����̂ŃI�[�o�[�t���[�͖��Ȃ�
	Vector3(const Quaternion& q); //�N�H�[�^�j�I������Vector3�������o���ď��������鎖���ł���

	float GetX() const { return x; } //x���擾
	float GetY() const { return y; } //y���擾
	float GetZ() const { return z; } //z���擾

	void SetX(float gx) { x = gx; } //x��ݒ�
	void SetY(float gy) { y = gy; } //y��ݒ�
	void SetZ(float gz) { z = gz; } //z��ݒ�
	void SetXYZ(float gx, float gy, float gz) { //�X�̐��l�ݒ肪�ʓ|�ȏꍇ����ň�C�ɐݒ�
		x = gx;
		y = gy;
		z = gz;
	}
	void SetXYZ(Vector3 in_pos)
	{
		*this = in_pos;
	}

	Vector3 operator=(const Vector3& r) { //const��Ԃ�l�ɕt�����a=b=c�̌^�̎��Ab=c�̕Ԃ�l��const�ƂȂ�Aa=const d�ŁAconst�w��̂Ȃ��{�֐����ĂׂȂ��Ȃ��Ă��܂��s�����const����
		SetXYZ(r.x, r.y, r.z);
		return *this;
	}

	const Vector3 operator+() const { return *this; }
	const Vector3 operator-() const { return Vector3(-x, -y, -z); } //-Vector3�̗l�ɕϐ��̑O��-��t����ƑS�Ă̐��l���}�C�i�X�ɂł���

	const Vector3 operator+ (const Vector3& r) const { return Vector3(x + r.x, y + r.y, z + r.z); } //Vector3���m�����Z�ł���
	const Vector3 operator- (const Vector3& r) const { return Vector3(x - r.x, y - r.y, z - r.z); } //Vector3���m�̌��Z���ł���

	Vector3 operator+= (const Vector3& r) { //Vector3�̉��Z������ł���
		(*this) = (*this) + r;
		return *this;
	}
	Vector3 operator-= (const Vector3& r) { //Vector3�̌��Z������ł���
		(*this) = (*this) - r;
		return *this;
	}
};

const Vector3 operator*(const Vector3& l, const Vector3& r);
template<typename T> const Vector3 operator*(const T& l, const Vector3& r) { return Vector3(l * r.GetX(), l * r.GetY(), l * r.GetZ()); }
template<typename T> const Vector3 operator*(const Vector3& l, const T& r) { return Vector3(l.GetX() * r, l.GetY() * r, l.GetZ() * r); }
const Vector3 operator/(const Vector3& l, const Vector3& r);
template<typename T> const Vector3 operator/(const T& l, const Vector3& r) { return Vector3(l / r.GetX(), l / r.GetY(), l / r.GetZ()); }
template<typename T> const Vector3 operator/(const Vector3& l, const T& r) { return Vector3(l.GetX() / r, l.GetY() / r, l.GetZ() / r); }

Vector3 operator*=(Vector3& l, const Vector3& r);
template<typename T> Vector3 operator*=(Vector3& l, const T& r) {
	l = l * r;
	return l;
}
Vector3 operator/=(Vector3& l, const Vector3& r);
template<typename T> Vector3 operator/=(Vector3& l, const T& r) {
	l = l / r;
	return l;
}

class Quaternion { //xyz��w�̏����������N�H�[�^�j�I���A�����I�ɂ�Vector3��float�^�ϐ���2�������Ŏ���
private:
	float w;
	Vector3 axis; //��������ɃC���X�^���X�����ł�����|�C���^�ɒu������
public:
	Quaternion(float gx = 0, float gy = 0, float gz = 0, float gw = 0) :axis(Vector3(gx, gy, gz)), w(gw) {}
	Quaternion(const Vector3& pos, float gw = 0) :axis(pos), w(gw) {} //xyz��Vector3�ŁAq��float�ŏ������ł���Aq�͏Ȃ���
	Quaternion(const Quaternion& q) :axis(q.axis), w(q.w) {} //�R�s�[�R���X�g���N�^���g����

	float GetW() const { return w; } //w���擾
	const Vector3& ReadAxis() const { return axis; } //Vector3�̏���ǂݏo��

	void SetW(float gw) { w = gw; } //w��ݒ�
	Vector3& EditAxis() { return axis; } //Vector3�����������\�Ȍ`�Ŏ擾����
};

class OriginMath { //���Z�ɕ֗��ȋ@�\�Z�߁A���̃N���X�̕ϐ��Ȃǂ��g�p�������ꍇ�t�@�C�����C���N���[�h���AOriginMath::�g�p�������ϐ���֐� �̌`���Ŏg�p�\
	OriginMath() {} //���̐����֎~

public:
	enum class HorizonPivot { left = -1, center, right }; //���S�_�ݒ�p�񋓌^�A����͐�������
	enum class VerticalPivot { top = -1, center, down }; //��L�̐�������

	static double MPI; //�~����
	static double Deg2Rad; //�f�O���[�p(45�Ƃ�90�Ƃ�)���烉�W�A���p(1.27�Ƃ�3.14)�֕ύX���������l�ɂ��̒l���|����Ƃ��Ă����
	static double Rad2Deg; //���W�A���p����f�O���[�p�֕ύX���������l�ɂ��̒l���|����Ƃ��Ă����

	static Quaternion QuaternionMul(const Quaternion& ql, const Quaternion& qr); //�N�H�[�^�j�I���ρAql�ɍ��ӁAqr�ɉE��
	static Quaternion Rad2Quaternion(const Vector3& angle); //���W�A���p���N�H�[�^�j�I����
	static Vector3 PointRotationQuaternion(const Vector3& xyz, const Quaternion& q); //�E��n�A���蒆�_����̋�����xyz�ɁAq�ɉ�]������ƁAxyz��3������]���Ă����Axyz�̒l�͉�]�ŕό`�����ĂȂ������g�p���鎖
};

class LinerFunction { //y=ax+b�̌`�ŕ\�����ꎟ������\���ł���N���X
	float slope; //�X��
	float yIntercept; //y�ؕ�
	bool parallelY; //y�ɕ��s�ȏꍇtrue

public:
	LinerFunction(const Vector3& pos1, const Vector3& pos2) { //2�_�ŌX���A�ؕЂ����߂鏉��������(���`���͕K�v�ɉ����Ēǉ�����)
		parallelY = pos1.GetX() - pos2.GetX() == 0; //y�ɕ��s���ǂ����L�^

		if (parallelY) { //x���g���Ȃ�(y���ɕ��s)�̏ꍇ��������g�p
			slope = 0; //�X���Ȃ�
			yIntercept = pos1.GetX(); //x=b�̌`�ɂ���
			return;
		}

		slope = (pos1.GetY() - pos2.GetY()) / (pos1.GetX() - pos2.GetX()); //�X���o���A�����܂ŗ����ꍇx�͎g����̂�0�Ŋ���`�F�b�N�͂��Ȃ�
		yIntercept = -slope * pos1.GetX() + pos1.GetY(); //�ؕЏo���Ay��0�ł�y=b�̌`�ɂȂ�
	}

	int GetX(int y) { return parallelY ? yIntercept : (y - yIntercept) / slope; } //�ꎟ�֐����y���W����Ή�����x���擾
	int GetY(int x) { return slope * x + yIntercept; } //��L��y�擾��
};
