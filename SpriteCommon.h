#pragma once
#include"PipelineSet.h"
#include <DirectXMath.h>


class SpriteCommon
{
private:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	static const int SpriteSRVCount = 512;

private:

	PipelineSet pipelineSet;

	DirectX::XMMATRIX matProjection{};

	ComPtr<ID3D12DescriptorHeap> descHeap;

	ComPtr<ID3D12Resource> texBuff[SpriteSRVCount];

	ID3D12Device* Device = nullptr;

public:

	void initialize(ID3D12Device* device, int window_width, int window_height);

private:
	void CreateGraphicsPipeline();

};