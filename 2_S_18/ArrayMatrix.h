#pragma once

#include <array>
#include <iostream>

using namespace std;

class ArrayMatrix
{
public:
	ArrayMatrix();
	ArrayMatrix(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33);

	ArrayMatrix(const ArrayMatrix& rhs);
	ArrayMatrix& operator=(const ArrayMatrix& rhs) = delete;

	virtual ~ArrayMatrix();

public:
	void TransformToTransposeMatrix();						// ת����ת�þ���
	void TransformToAdjointMatrix();						// ת�����������
	void TransformToInverseMatrix();						// ת���������

	float GetDeterminant();									// ��������ʽ

	void DoMultiplication(const ArrayMatrix &mat);			// ������������
	void DoMultiplication(const float scalar);				// ������������

private:
	void ChangeData(int srcRow, int srcColumn, int desRow, int desColum);		// ����srcλ�ú�desλ�õ�����

	float GetDeterminant3x3(array<float, 9> &arrayData);

public:
	void SetData(int row, int column, float data) { m_data[row * m_rowAndColumnCount + column] = data; }
	float GetData(int row, int column) const { return m_data[row * m_rowAndColumnCount + column]; }

	int GetDataCount() { return m_dataCount; }
	int GetRowAndColumnCount() { return m_rowAndColumnCount; }

	float GetDataByIndex(int index) const { return m_data[index]; }

private:
	const int m_dataCount = 16;
	const int m_rowAndColumnCount = 4;

	array<float, 16> m_data;
};