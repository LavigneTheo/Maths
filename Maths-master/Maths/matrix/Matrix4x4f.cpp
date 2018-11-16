#include "Matrix4x4.h"


Matrix4x4::Matrix4x4(float* data) : m_data(data) {
	
}

Matrix4x4::Matrix4x4()  {
	m_data_dynamicly_allodated = true;
	m_data = (float*) malloc(sizeof(float) * 16);
	for (int i = 0; i < 16; i++)
		*(m_data + i) = 0;
}

Matrix4x4::~Matrix4x4() {
	if (m_data_dynamicly_allodated)
		free(m_data);
}

float* Matrix4x4::get_data() const {
	return m_data;
}

void Matrix4x4::set_data(float* data) {
	if (m_data_dynamicly_allodated) {
		free(m_data);
		m_data_dynamicly_allodated = false;
	}
		
	m_data = data;
}

void Matrix4x4::mul(const Matrix4x4& mat) {
	std::array<float, 16> data_cpy;
	for (int i = 0; i < 16; i++)
		data_cpy.at(i) = *(m_data + i);
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			float sum = 0;
			for (int index = 0; index < 4; index++) {
				float th_mat = data_cpy.at(y * 4 + index);
				float mat2 = mat.get(index * 4 + x);
				sum += data_cpy.at(y * 4 + index) * mat.get(index * 4 + x);
			}
			*(m_data + x + 4 * y) = sum;
		}
	}
}

void Matrix4x4::mul(const float& scalar) {
	for (int i = 0; i < 16; i++)
		*(m_data + i) *= scalar;
}

float Matrix4x4::get(const int& index) const {
	if (index > 15)
		return 0;
	return *(m_data + index);
}

void Matrix4x4::set(const int& index, const float& value) {
	*(m_data + index) = value;
}

void Matrix4x4::identity() {
	*(m_data) = 1;
	*(m_data + 5) = 1;
	*(m_data + 10) = 1;
	*(m_data + 15) = 1;
}

void Matrix4x4::get_projection_matrix(Matrix4x4& projection, const int& WIDRH, const int& HEIGHT) {
	
	const float FOV = 70, Z_NEAR = 0.1f, Z_FAR = 6000;
	float aspectRatio = WIDRH /(float)HEIGHT;
	float y_scale = (float)((1.f / tanf(deg_to_rad(FOV / 2.f))) * aspectRatio);
	float x_scale = y_scale / aspectRatio;
	float frustum_length = Z_FAR - Z_NEAR;

	projection.set(0, x_scale);
	projection.set(5, y_scale);
	projection.set(10, -((Z_FAR + Z_NEAR) / frustum_length));
	projection.set(14, -1);
	projection.set(11, -((2 * Z_NEAR * Z_FAR) / frustum_length));
	projection.set(15, 0);

	projection.print();
}

void Matrix4x4::print() const {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			std::cout << *(m_data + y * 4 + x) << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix4x4::translate(const float x, const float y, const float z) {
	*(m_data + 3) += x;
	*(m_data + 7) += y;
	*(m_data + 11) += z;
}