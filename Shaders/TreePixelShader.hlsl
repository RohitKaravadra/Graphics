Texture2D tex : register(t0);
SamplerState samplerLinear : register(s0);

struct PS_INPUT
{
    float4 Pos : SV_POSITION;
    float3 Normal : NORMAL;
    float3 Tangent : TANGENT;
    float2 TexCoords : TEXCOORD;
};

float4 Pixel(PS_INPUT input) : SV_Target0
{
    float4 colour = tex.Sample(samplerLinear, input.TexCoords);
    if (colour[3] < 0.5f)
        discard;
    return float4(colour.rgb, 1.0);
}
