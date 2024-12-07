
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
    float4 color = tex.Sample(samplerLinear, input.TexCoords);
    if (color.a < 0.5f)
        discard;
    
    float3 lightDir = normalize(float3(-1, 0.2, -0.2));
    input.Normal = normalize(input.Normal);
    
    color = (color / 3.1459) * float4(1, 1, 1, 1) * 5 * max(dot(lightDir, input.Normal), 0) + color * 0.2; // calculate simple lighting
    return float4(color.rgb, 1.0);
}
