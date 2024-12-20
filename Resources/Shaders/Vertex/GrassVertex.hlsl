cbuffer ConstBuffer
{
	float4x4 VP;
	float T;
};

struct VS_INPUT
{
	float4 Pos : POS;
	float3 Normal : NORMAL;
	float3 Tangent : TANGENT;
	float2 TexCoords : TEXCOORD;
	float3 InstancePosition : INSTANCEPOSITION;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float3 Normal : NORMAL;
	float3 Tangent : TANGENT;
	float2 TexCoords : TEXCOORD;
};

PS_INPUT Vertex(VS_INPUT input)
{
	PS_INPUT output;
    
	output.Pos = input.Pos;
	
     // animate by changing position
	output.Pos.x += sin(input.InstancePosition.x + T * 2) * input.Pos.y * 0.2;
	output.Pos.z += sin(input.InstancePosition.z + T * 2) * input.Pos.y * 0.2;
	
     // Billboard rotation (cancel out W rotation)
	float3x3 billBRot = (float3x3) VP;
	
    // Apply billboard rotation to the vertex position
	output.Pos = float4(mul(output.Pos.xyz, billBRot), 1);
	output.Pos.xyz += input.InstancePosition;
	
    // Apply world position and project to screen space
	output.Pos = mul(output.Pos, VP);
    
    // normal and tangent projection
	output.Normal = normalize(mul(input.Normal, billBRot));
	output.Tangent = normalize(mul(input.Tangent, billBRot));
    
	output.TexCoords = input.TexCoords;
    
	return output;
}