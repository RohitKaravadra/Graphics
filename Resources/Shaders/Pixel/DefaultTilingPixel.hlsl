Texture2D tex : register(t0);
SamplerState samplerLinear : register(s0);

cbuffer ConstBuffer
{
    float2 T;
};

struct PS_INPUT
{
    float4 Pos : SV_POSITION;
    float3 Normal : NORMAL;
    float3 Tangent : TANGENT;
    float2 TexCoords : TEXCOORD;
};

float4 Pixel(PS_INPUT input) : SV_Target0
{
    float4 color = tex.Sample(samplerLinear, input.TexCoords * T);
    if (color.a < 0.5f)
        discard;
    
    color = (color / 3.1459) * float4(1, 1, 1, 1) * 10 * max(dot(normalize(float3(-1, 0.2, -0.2)), input.Normal), 0) + color * 0.2; // calculate simple lighting
    return float4(color.rgb, 1.0);
}
