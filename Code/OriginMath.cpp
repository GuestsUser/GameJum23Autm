#include "OriginMath.h"
#include <cmath>

double OriginMath::MPI = 3.14159265359; //static�ϐ��̐��l�ݒ�
double OriginMath::Deg2Rad = MPI / 180;
double OriginMath::Rad2Deg = 180 / MPI;

const Vector3 operator*(const Vector3& l, const Vector3& r) { return Vector3(l.GetX() * r.GetX(), l.GetY() * r.GetY(), l.GetZ() * r.GetZ()); }
const Vector3 operator/(const Vector3& l, const Vector3& r) { return Vector3(l.GetX() / r.GetX(), l.GetY() / r.GetY(), l.GetZ() / r.GetZ()); }

Vector3 operator*=(Vector3& l, const Vector3& r) {
	l = l * r;
	return l;
}
Vector3 operator/=(Vector3& l, const Vector3& r) {
	l = l / r;
	return l;
}

Vector3::Vector3(const Quaternion& q) :x(q.ReadAxis().x), y(q.ReadAxis().y), z(q.ReadAxis().z) {}

Vector3 WToImaginaryMul(const float& single, const Vector3& queue) { //�����Ƌ������̌v�Z
	Vector3 ans;

	//������S�Ă̒l�������x�N�g���Ƃ��ē���
	ans.SetX(queue.GetX() * single);
	ans.SetY(queue.GetY() * single);
	ans.SetZ(queue.GetZ() * single);
	return ans;
}
Quaternion ImaginaryMul(const Vector3& q1, const Vector3& q2) { //�N�H�[�^�j�I���������v�Z
	return Quaternion(q1.GetY() * q2.GetZ() - q1.GetZ() * q2.GetY(), q1.GetZ() * q2.GetX() - q1.GetX() * q2.GetZ(), q1.GetX() * q2.GetY() - q1.GetY() * q2.GetX(), -(q1.GetX() * q2.GetX() + q1.GetY() * q2.GetY() + q1.GetZ() * q2.GetZ()));
}

Quaternion OriginMath::QuaternionMul(const Quaternion& ql, const Quaternion& qr) {//�N�H�[�^�j�I���ρAql�ɍ��ӁAqr�ɉE��
	Vector3 imag1 = WToImaginaryMul(ql.GetW(), qr.ReadAxis());
	Vector3 imag2 = WToImaginaryMul(qr.GetW(), ql.ReadAxis());
	Quaternion imag3 = ImaginaryMul(ql.ReadAxis(), qr.ReadAxis());
	Vector3 imaginary = Vector3(imag1.GetX() + imag2.GetX() + imag3.ReadAxis().GetX(), imag1.GetY() + imag2.GetY() + imag3.ReadAxis().GetY(), imag1.GetZ() + imag2.GetZ() + imag3.ReadAxis().GetZ());

	return Quaternion(imaginary.GetX(), imaginary.GetY(), imaginary.GetZ(), ql.GetW() * qr.GetW() + imag3.GetW());

}
Vector3 OriginMath::PointRotationQuaternion(const Vector3& xyz, const Quaternion& q) { //�E��n�Aq�Ɉ�؂̉�]��������ĂȂ���Ԃ̒��_�����xyz�Ƃ��Aq�ɉ�]�Axyz�ɋ���������Ƌ�����3������]���Ă����
	Quaternion conj = Quaternion(-q.ReadAxis().GetX(), -q.ReadAxis().GetY(), -q.ReadAxis().GetZ(), q.GetW());//q�̋����N�H�[�^�j�I��
	Quaternion xyzw = Quaternion(xyz);
	Quaternion edit = QuaternionMul(q, xyzw);//q*p*q����  �̌`
	return Vector3(QuaternionMul(edit, conj)); //EditAxis�̎Q�Ƃ����̂܂ܕԂ��Ǝ󂯎���ŏ�񂪏����Ă��܂��̂Œl�n���̌^�ɒ���
}

Quaternion OriginMath::Rad2Quaternion(const Vector3& angle) {
	Quaternion x = Quaternion(sin(angle.GetX() / 2), 0, 0, cos(angle.GetX() / 2));
	Quaternion y = Quaternion(0, sin(angle.GetY() / 2), 0, cos(angle.GetY() / 2));
	Quaternion z = Quaternion(0, 0, sin(angle.GetZ() / 2), cos(angle.GetZ() / 2));

	Quaternion xy = QuaternionMul(x, y);
	return QuaternionMul(xy, z);
}
