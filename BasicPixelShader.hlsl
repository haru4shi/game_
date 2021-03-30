#include"BasicShaderHeader.hlsli"

Texture2D<float4> tex:register(t0);//0番スロットに設定されたテクスチャ
SamplerState smp:register(s0);//0番のスロットに設定されたサンプラー
float4 PSmain(VSOutput input) : SV_TARGET
{
	float3 light = normalize(float3(1,-1,1));//右下奥　向きのライト
	float diffuse = saturate(dot(-light, input.normal));//diffuseを[0,1]の範囲にClampする
	float brightness = diffuse + 0.5f;//アンビエント項を0.3として計算
	float4 texcolor = tex.Sample(smp, input.uv);
	return float4(brightness, brightness, brightness, 1)*texcolor;
	//return float4(1, 1, 1, 1);
}