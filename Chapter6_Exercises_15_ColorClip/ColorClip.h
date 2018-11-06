/*********************************************************************************
*FileName:        ColorClip.h
*Author:
*Version:         1.0
*Date:            2018/8/6
*Description:     ColorClip Ӧ����
**********************************************************************************/

#pragma once

#include "../Common/D3DApp.h"
#include "../Common/UploadBuffer.h"
#include "../Common/MathHelper.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;

// ���ӵĶ������ݽṹ
struct Vertex
{
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
	//XMCOLOR Color;
};

// Constant buffer �ṹ
struct ObjectConstants
{
	XMFLOAT4X4 WorldViewProj = MathHelper::Identity4x4();
};

class ColorClip : public D3DApp
{
public:
	ColorClip(HINSTANCE hInstance);
	ColorClip(const ColorClip& rhs) = delete;
	ColorClip& operator=(const ColorClip& rhs) = delete;
	~ColorClip();

	virtual bool Initialize() override;

protected:
	virtual void OnResize() override;
	virtual void Update(const GameTimer& gt) override;
	virtual void Draw(const GameTimer& gt) override;

	virtual void OnMouseDown(WPARAM btnState, int x, int y) override;
	virtual void OnMouseUp(WPARAM btnState, int x, int y) override;
	virtual void OnMouseMove(WPARAM btnState, int x, int y) override;

	void BuildDescriptorHeaps();						// ���� Descriptor Heap
	void BuildConstantBuffers();						// ���� Constant buffer
	void BuildRootSignature();							// ���� root signature�����԰� shader ��Ҫʹ�õ���Դ
	void BuildShadersAndInputLayout();					// ���� shader ���
	void BuildBoxGeometry();							// ������������
	void BuildPSO();									// ����������Ⱦ����

private:

	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;		// �൱�� Shader �ĺ���ǩ��
	ComPtr<ID3D12DescriptorHeap> mCbvHeap = nullptr;			// Constant buffer view Descriptor heap

	std::unique_ptr<UploadBuffer<ObjectConstants>> mObjectCB = nullptr;			// Constant buffer

	std::unique_ptr<MeshGeometry> mBoxGeo = nullptr;			// ���� Mesh Geometry �ṹ

	ComPtr<ID3DBlob> mvsByteCode = nullptr;						// vertex shader ����
	ComPtr<ID3DBlob> mpsByteCode = nullptr;						// 

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;			// shader layout

	ComPtr<ID3D12PipelineState> mPSO = nullptr;					// pipeline

	XMFLOAT4X4 mWorld = MathHelper::Identity4x4();
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.5f*XM_PI;
	float mPhi = XM_PIDIV4;
	float mRadius = 5.0f;

	POINT mLastMousePos;
};
