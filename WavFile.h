#pragma once


typedef struct __WAVEFORMAT
{
	WORD wFormatTag; 
	WORD nChannels; 
	DWORD nSamplesPerSec; 
	DWORD nAvgBytesPerSec; 
	WORD nBlockAlign; 
}WAVEFORMAT;//wave format

typedef struct __PCMWAVEFORMAT
{
	WAVEFORMAT wf;
	WORD       wBitsPerSample; 
}PCMWAVEFORMAT; // pcm wave format


struct CHUNK_HEADER
{
	char szRiffID[4]; // 'R','I','F','F'
	DWORD dwRiffSize;
};//chunk header

class CWavFile
{
public:
	CWavFile(void);
public:
	~CWavFile(void);
public:
	int Open(WAVEFORMAT * pFormat,char * filename);
	int Close();
private:
	int m_nWaveSize;
	FILE * m_pFile;
	char * m_pBuffer;
};



//
//
//1. RIFF�ṹ
//
//      ��Դ�����ļ���ʽRIFF(Resources Interchange File Format)��һ�ֶ�ý���ļ��Ĵ洢��ʽ��������RIFF�ļ���WAV�ļ���AVI�ļ���RIFF���Կ�����һ����״�ṹ����������ɵ�λΪ��chunk��ÿ��chunk�ɡ�����롱�������ݴ�С���������ݡ�����ɡ�һ����ԣ�chunk�����������ڲ��ٰ���chunk,�����������⣬���ֱ��ԡ�RIFF������LIST��Ϊ������chunk�����С�RIFF��chuuk�ñ����ļ�ϵͳ�ĸ�Ŀ¼����LIST��chunk��Ӧ��Ŀ¼��������chunk���Ӧһ����ļ���RIFF�ļ���һЩ��chunk��ɡ�
//
//��дRIFF�ļ����ķ�����ʹ����mmio��ͷ��Win32 API����������mmioOpen( ).
//
//2. Chunk�ṹ��ɽ���
//
//��1��FOURCC(Four Character Code)��ʾ4��ASCII�ַ���һ�����ĸ��ֽڣ�Ҳ�����������ֽڼ���1���ո񣬵����м䲻���пո�������ʾListType��ChunkID,��ʼ��ʶ����Ϣ��
//
//��2��CHUNK �� ���ݽṹ��ChunkID, ChunkSize, ChunkData
//
//ChunkID��1��FOURCC,��ʶchunk�����ƣ�ChunkSize����ռ��4���ֽڣ���ʾChunkData���ֵ����ݴ�С�����ֽ�Ϊ��λ��ChunkData��������chunk��ʵ���Ե����ݣ�����chunk�ľ������ݡ�1��chunk��������ݿ����ǹ�����Ƶ�ļ��ı��뷽ʽ����������Ϣ��Ҳ��������Ƶ����Ƶ���ݣ������ʾ����������ͨ��ChunkID����ʶ��
//
//      ע�� �鱾�����ռ��ż����Bytes, ��Ҫʱ�����ڽ�β��0 .
//
//��3��LIST�� ���ݽṹ����LIST�� ListSize ListType ListData
//
//��LIST��Ҳ��FOURCC,����ID���̶��ģ�ÿ��LIST�����ԡ�LIST����ͷ��ListSizeռ��4���ֽڣ���ʾListType��ListData�����ּ���һ��Ĵ�С��ListType��һ��FOURCC���Ƕ�LIST����������������ݵı�ʶ����ListData���Ǹ�LIST����������������CHUNK����LIST��ɣ����ǵĸ�������ɴ�������ǲ�ȷ���ġ�ע��LISTҲ��chunk.
//
//(4) RIFF�� ���ݽṹ����RIFF�� FileSize FileType FileData
//
//��RIFF��Ҳ��һ��FOURCC�����ڱ�ʶ���ļ���һ��RIFF��ʽ���ļ���FileSize��һ��4�ֽڵ����ݣ������ļ��Ĵ�С����������FileType��FileData�����֡�FileType��һ��FOURCC������˵���ļ����ͣ��硱WAV��, ��AVI���ȡ�FileData���ֱ�ʾ�ļ��ľ������ݣ�������LISTҲ������CHUNK.
//
//3 WAV�ļ�chunk�ṹ
//
//   ��WAVE�������2���ӿ飺��fmt����͡�data����
//
//struct RIFF_HEADER
//
//{
//
//char szRiffID[4]; // 'R','I','F','F'
//
//DWORD dwRiffSize;
//
//char szRiffFormat[4]; // 'W','A','V','E'
//
//};
//
//
//typedef struct { 
//
//    WAVEFORMAT wf; 
//
//    WORD       wBitsPerSample; 
//
//} PCMWAVEFORMAT; 
//
//
//typedef struct { 
//
//    WORD wFormatTag; 
//
//    WORD nChannels; 
//
//    DWORD nSamplesPerSec; 
//
//   DWORD nAvgBytesPerSec; 
//
//    WORD nBlockAlign; 
//
//} WAVEFORMAT;
//
//
//Fact Chunk�ǿ�ѡ�ֶΣ�һ�㵱wav�ļ���ĳЩ���ת�����ɣ��������Chunk���ṹ�������£�
//
//struct FACT_BLOCK
//
//{
//
//char szFactID[4]; // 'f','a','c','t'
//
//DWORD dwFactSize;
//
//};
//
//
//"data"Chunk�����������������ݣ� Data Chunkͷ�ṹ�������£�
//
//struct DATA_BLOCK
//
//{
//
//char szDataID[4]; // 'd','a','t','a'
//
//DWORD dwDataSize;
//
//};
//
//
//4 WAV�淶�ļ�ʵ������
//
//     WAVE�ļ���������1�����С�WAVE��chunk��RIFF�ļ�����WAVE������2���ӿ���ɣ���fmt��chunk �͡�data��chunk
//
//     �淶WAVE�ļ���ʽ˵����
//
//ƫ��Offset ��СSize ����Name ˵��Desciption
//
//��ͷ��RIFF ͷ����
//
//0   4    ChunkID    ��RIFF����0x52494646 ����
//
//4   4    ChunkSize   36+�ӿ�2��С= 4+��8+�ӿ�1��С��+��8+�ӿ�2��С��
//
//8   4    Format       ��WAVE����0x57415645 ����
//
//��WAVE����ʽ��2���ӿ���ɣ���fmt���͡�data����
//
//�ӿ顰fmt��������Ƶ���ݵĸ�ʽ��
//
//12   4    Subchunk1ID   ��fmt����0x666d7420 ����
//
//16   4    Subchunk1Size   16 for PCM
//
//20   2    AudioFormat     PCM = 1 ������1��ʾһЩѹ����ʽ��
//
//22   2    NumChannels    ͨ����Mono = 1, Stereo =2 ��
//
//24   4    SampleRate      ������80000��44100��
//
//28   4    ByteRate        = =SampleRate * NumChannels * BitsPerSample / 8
//
//32   2    BlockAlign      = = NumChnnels * BitsPerSample / 8 ����������ͨ����
//
//34    2    BitsPerSample     8 bits = 8, 16 bits =16 ��
//
//      2    ExtraParamSize    �����PCM����ô������
//
//      x    ExtraParams       ��������Ŀռ�
//
//�ӿ顱data���������ݴ�С��ʵ�ʵ�������
//
//36    4    Subchunk2ID      ��data�� ��0x64617461 ����
//
//40    4    Subchunk2Size     = = NumSamples * NumChannels * BitsPerSample / 8
//
//44    *    Data              ʵ�ʵ���Ƶ����
//
//
//
//     ע�⣺WAVE�ļ�ȱʡ���ֽ���ΪС�����ʹ��RIFX�滻RIFF����ô�ֽ���Ϊ����
//
//�������ݽ�����ż���ֽڣ��������Ϊ��������0�����Ȳ��䣬��������0��
//
//8λ����ʱ����Χ0~255����16λ����ʱ��-32768~32768 .
//
//WAVE�ļ������ɿ���ɣ�RIFF WAVE Chunk, Format Chunk, Fact Chunk����ѡ��, Data Chunk. 
//
