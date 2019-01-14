//***************************************************************************************
// d3dUtil.h by X_Jun(MKXJun) (C) 2018-2019 All Rights Reserved.
// Licensed under the MIT License.
//
// D3Dʵ�ù��߼�
// Direct3D utility tools.
//***************************************************************************************

#ifndef D3DUTIL_H
#define D3DUTIL_H

#include <d3d11_1.h>			// �Ѱ���Windows.h
#include <DirectXCollision.h>	// �Ѱ���DirectXMath.h
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include <d3dcompiler.h>
#include <wincodec.h>
#include <filesystem>
#include <vector>
#include <string>
#include "ScreenGrab.h"
#include "DDSTextureLoader.h"	
#include "WICTextureLoader.h"

//
// �����
//

// ��ȫCOM����ͷź�
#define SAFE_RELEASE(p) { if ((p)) { (p)->Release(); (p) = nullptr; } }

//
// ��ɫ��������غ���
//

// ------------------------------
// CreateShaderFromFile����
// ------------------------------
// [In]csoFileNameInOut ����õ���ɫ���������ļ�(.cso)������ָ��������Ѱ�Ҹ��ļ�����ȡ
// [In]hlslFileName     ��ɫ�����룬��δ�ҵ���ɫ���������ļ��������ɫ������
// [In]entryPoint       ��ڵ�(ָ����ʼ�ĺ���)
// [In]shaderModel      ��ɫ��ģ�ͣ���ʽΪ"*s_5_0"��*����Ϊc,d,g,h,p,v֮һ
// [Out]ppBlobOut       �����ɫ����������Ϣ
HRESULT CreateShaderFromFile(const WCHAR* csoFileNameInOut, const WCHAR* hlslFileName, LPCSTR entryPoint, LPCSTR shaderModel, ID3DBlob** ppBlobOut);

//
// ����������غ���
//

// ------------------------------
// CreateDDSTexture2DArrayFromFile����
// ------------------------------
// �ú���Ҫ�����е�dds�����Ŀ��ߡ����ݸ�ʽ��mip�ȼ�һ��
// [In]d3dDevice			D3D�豸
// [In]d3dDeviceContext		D3D�豸������
// [In]fileNames			dds�ļ�������
// [OutOpt]textureArray		���������������Դ
// [OutOpt]textureArrayView ���������������Դ��ͼ
// [In]generateMips			�Ƿ�����mipmaps
HRESULT CreateDDSTexture2DArrayFromFile(
	ID3D11Device * d3dDevice,
	ID3D11DeviceContext * d3dDeviceContext,
	const std::vector<std::wstring>& fileNames,
	ID3D11Texture2D** textureArray,
	ID3D11ShaderResourceView** textureArrayView,
	bool generateMips = false);

// ------------------------------
// CreateWICTexture2DArrayFromFile����
// ------------------------------
// �ú���Ҫ�����е�dds�����Ŀ��ߡ����ݸ�ʽ��mip�ȼ�һ��
// [In]d3dDevice			D3D�豸
// [In]d3dDeviceContext		D3D�豸������
// [In]fileNames			dds�ļ�������
// [OutOpt]textureArray		���������������Դ
// [OutOpt]textureArrayView ���������������Դ��ͼ
// [In]generateMips			�Ƿ�����mipmaps
HRESULT CreateWICTexture2DArrayFromFile(
	ID3D11Device * d3dDevice,
	ID3D11DeviceContext * d3dDeviceContext,
	const std::vector<std::wstring>& fileNames,
	ID3D11Texture2D** textureArray,
	ID3D11ShaderResourceView** textureArrayView,
	bool generateMips = false);


//
// ������������غ���
//


// ------------------------------
// CreateWICTexture2DCubeFromFile����
// ------------------------------
// ���ݸ�����һ�Ű����������������λͼ����������������
// Ҫ���������߱�Ϊ4:3���Ұ�������ʽ����:
// .  +Y .  .
// -X +Z +X -Z 
// .  -Y .  .
// [In]d3dDevice			D3D�豸
// [In]d3dDeviceContext		D3D�豸������
// [In]cubeMapFileName		λͼ�ļ���
// [OutOpt]textureArray		���������������Դ
// [OutOpt]textureCubeView	�����������������Դ��ͼ
// [In]generateMips			�Ƿ�����mipmaps
HRESULT CreateWICTexture2DCubeFromFile(
	ID3D11Device * d3dDevice,
	ID3D11DeviceContext * d3dDeviceContext,
	const std::wstring& cubeMapFileName,
	ID3D11Texture2D** textureArray,
	ID3D11ShaderResourceView** textureCubeView,
	bool generateMips = false);

// ------------------------------
// CreateWICTexture2DCubeFromFile����
// ------------------------------
// ���ݰ�D3D11_TEXTURECUBE_FACE����˳�������������������������������
// Ҫ��λͼ��ͬ�����ߡ����ݸ�ʽ��������
// ��Ҳ���Ը�������6�ŵ�������Ȼ���ڻ�ȡ����������Ļ��������д����������Դ��ͼ
// [In]d3dDevice			D3D�豸
// [In]d3dDeviceContext		D3D�豸������
// [In]cubeMapFileNames		λͼ�ļ�������
// [OutOpt]textureArray		���������������Դ
// [OutOpt]textureCubeView	�����������������Դ��ͼ
// [In]generateMips			�Ƿ�����mipmaps
HRESULT CreateWICTexture2DCubeFromFile(
	ID3D11Device * d3dDevice,
	ID3D11DeviceContext * d3dDeviceContext,
	const std::vector<std::wstring>& cubeMapFileNames,
	ID3D11Texture2D** textureArray,
	ID3D11ShaderResourceView** textureCubeView,
	bool generateMips = false);


#endif