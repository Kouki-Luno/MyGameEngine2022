//������������������������������������������������������������������������������
 // �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
//������������������������������������������������������������������������������
Texture2D	g_texture : register(t0);	//�e�N�X�`���[
SamplerState	g_sampler : register(s0);	//�T���v���[

//������������������������������������������������������������������������������
 // �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer global
{
	//float4x4	matWVP;			// ���[���h�E�r���[�E�v���W�F�N�V�����̍����s��
	float4x4	matW;	//���[���h�s��
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUT
{
	float4 pos    : SV_POSITION;	//�ʒu
	float2 uv	: TEXCOORD;			//UV���W
	//float4 color	: COLOR;	//�F�i���邳�j
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������

VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD)//, float4 normal : NORMAL)
{
	//�s�N�Z���V�F�[�_�[�֓n�����
	VS_OUT outData;

	//���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
	//�X�N���[�����W�ɕϊ����A�s�N�Z���V�F�[�_�[��
	outData.pos = mul(pos, matW);
	outData.uv = uv;

	//�@������]
	//normal = mul(pos, matW);

	//float4 light = float4(1, 0, 0, 0);
	//light = normalize(light);
	//outData.color = dot(normal, light);
	//outData.color = clamp(dot(normal, light), 0, 1);

	//�܂Ƃ߂ďo��
	return outData;

}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUT inData) : SV_Target
{
	return g_texture.Sample(g_sampler, inData.uv); //*inData.color;

	//float4 diffuse = g_texture.Sample(g_sampler, inData.uv) * inData.color;
	//float4 ambient = g_texture.Sample(g_sampler, inData.uv) * float4(0.2, 0.2, 0.2, 1);
	//return diffuse + ambient;

	//if (inData.pos.x < 400)
	//{
	//	return float4(0, 0, 0, 1);
	//}
	//else
	//{
	//	return float4(1,1,1,1);
	//}

}