//#define _CRT_SECURE_NO_WARNINGS//strcpy�̃o�b�t�@�I�[�o�[�̌x�����~�߂邽�߂ɂ���B
//strcpy_s�Ƃ����͎̂g����̂��H�g������_CRT_SECURE_NO_WARNINGS�ł͂Ȃ�strcpy_s�ɂ����ق��������H
//#include "DxLib.h"
#include "ActiveMath.h"
//#include <string.h>//������p�H
//#include <stdlib.h>//�I������exit()�֐��������Ă��� itoa�֐��iint����char�ւ̕ϊ��j
//#include <stdio.h>
//#define _USE_MATH_DEFINES//
//#include <math.h>//_USE_MATH_DEFINES ���`���Ă���Acmath�i��++�p�j �� math.h�ic����p�j ���C���N���[�h����K�v������܂��B

//#include <windows.h>//�ҏW���ɉ摜�I���_�C�A���O�Ŏg�p
//#include <tchar.h>//�ҏW���ɉ摜�I���_�C�A���O�Ŏg�p�@�f�B���N�g���[���̑���֘A�Ŏg�p

#include <shlwapi.h>//PathRelativePathTo�Ŏg�p
#pragma comment( lib, "Shlwapi.lib" )//PathRelativePathTo�Ŏg�p
#include <shlobj.h> //���̃A�v���Œ�`���ꂽGetOpenDirectoryName�֘A�Ŏg�p


//���O���[�o���ϐ�
char ApplicationTitle[] = "Active Math Message Editor";

int FPS = 60;
int WindowWidth = 1000, WindowHeight = 750 + 24 + 24, ColorBitNum = 32;//PC���j�^�[��1920 * 1080


#define MONSTER_MAX 500//�����X�^�[�̌��̍ő�i���ҏW���[�h�C�����X�^�[�ҏW���[�h�ŋ��L�j
//SHOUMON_MAX��KADAI�\���̂̃����o�[�����烉�C�u�����Œ�`���邵���Ȃ��B
//DAIMON_MAX�͑��݂��Ȃ��B

////////�@�ρ@���@////////
//���ϐ�
int red = GetColor(255, 0, 0);
int green = GetColor(0, 255, 0);
int blue = GetColor(0, 0, 255);
int cyan = GetColor(0, 255, 255);
int magenta = GetColor(255, 0, 255);
int yellow = GetColor(255, 255, 0);
int black = GetColor(0, 0, 0);
int gray = GetColor(204, 204, 204);//80��
int white = GetColor(255, 255, 255);
int gray60 = GetColor(153, 153, 153);
int gray30 = GetColor(77, 77, 77);


////////�@�\�@���@�́@////////
//�k���b�Z�[�W�ҏW�p�p�b�h�l
//���G���A
const int EditorPadAreaMax = 3;//�O�F�C���f�b�N�X�G���A�C�P�F�{�^���G���A�C�Q�F�x�[�X�{�^���G���A
static int EditorPadAreaKosuu = -1;
static struct AREACONTROL EditorPadArea[EditorPadAreaMax] = { 0 };
//���{�^���t�H�[��
const int EditorButtonFormMax = 2;//�C���f�b�N�X�p�ƃ{�^���E�x�[�X�{�^���p
static int EditorButtonFormKouu;//�ŏI�{�^���̗v�f�ԍ��i���[�h���Ɏ擾�ł��邩�炱���ł͎w�肵�Ȃ��j�i�{�^���������o���Ƃ��Ɏg�p����j
static struct BUTTONFORM EditorButtonForm[EditorButtonFormMax] = { 0 };
//�����͗p�C���f�b�N�X
const int EditorIndexMax = 6;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
static int EditorIndexKosuu;//�ŏI�{�^���̗v�f�ԍ��i���[�h���Ɏ擾�ł��邩�炱���ł͎w�肵�Ȃ��j�i�{�^���������o���Ƃ��Ɏg�p����j
static struct BUTTONCONTROL EditorIndex[EditorIndexMax] = { 0 };
//�����͗p�{�^��
const int EditorButtonMax0 = 18;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
const int EditorButtonMax1 = 18;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
const int EditorButtonMax2 = 18;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
const int EditorButtonMax3 = 17;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
const int EditorButtonMax4 = 18;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
const int EditorButtonMax5 = 36;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
const int EditorButtonMax[6] = { EditorButtonMax0,	EditorButtonMax1, EditorButtonMax2,	EditorButtonMax3, EditorButtonMax4, EditorButtonMax5 };//�{�^���z��̗v�f��
static int EditorButtonKosuu[6];//�ŏI�{�^���̗v�f�ԍ��i���[�h���Ɏ擾�ł��邩�炱���ł͎w�肵�Ȃ��j�i�{�^���������o���Ƃ��Ɏg�p����j
static struct INPUTTEXTBUTTONCTRL EditorButton0[EditorButtonMax0];
static struct INPUTTEXTBUTTONCTRL EditorButton1[EditorButtonMax1];
static struct INPUTTEXTBUTTONCTRL EditorButton2[EditorButtonMax2];
static struct INPUTTEXTBUTTONCTRL EditorButton3[EditorButtonMax3];
static struct INPUTTEXTBUTTONCTRL EditorButton4[EditorButtonMax4];
static struct INPUTTEXTBUTTONCTRL EditorButton5[EditorButtonMax5];
static struct INPUTTEXTBUTTONCTRL *EditorButton_ph[] = { EditorButton0, EditorButton1, EditorButton2, EditorButton3, EditorButton4, EditorButton5 };
//�����͗p��{�{�^��
const int EditorBaseButtonMax = 9;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
static int EditorBaseButtonKosuu;//�ŏI�{�^���̗v�f�ԍ��i���[�h���Ɏ擾�ł��邩�炱���ł͎w�肵�Ȃ��j�i�{�^���������o���Ƃ��Ɏg�p����j
static struct INPUTTEXTBUTTONCTRL EditorBaseButton[EditorBaseButtonMax] = { 0 };


////////////////////���@�ց@���@�́@��@�`�@��////////////////////
////////////////////���@�L�[�{�[�h���͂Ɋւ���֐��@��////////////////////
//�}�E�X�̓��͏��
int gpUpdateMouse(int *Mouse_g, int *MouseX, int *MouseY) {
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) Mouse_g[MOUSE_INPUT_LEFT]++;	else Mouse_g[MOUSE_INPUT_LEFT] = 0;
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) Mouse_g[MOUSE_INPUT_RIGHT]++;	else Mouse_g[MOUSE_INPUT_RIGHT] = 0;
	GetMousePoint(MouseX, MouseY);// �}�E�X�̈ʒu���擾

	return 0;
}

//�S�ẴL�[�̓��͏�ԁi�����ꂽ�t���[�����j���X�V����֐�
int gpUpdateKey(int *Key_g) {//�S�ẴL�[�̓��͏�ԁi�����ꂽ�t���[�����j���X�V����֐�
	char tmpKey[256]; // �L�[�̓��͏�ԁi������Ă��Ȃ��F0�C������Ă���F1�j
	GetHitKeyStateAll(tmpKey); // 256��ނ̃L�[�̓��͏�Ԃ�z��@tempKye�@�ɓ����
	for (int i = 0; i < 256; i++) {////��256��ނ̃L�[�̓��͏�Ԃ��Ăяo�����̒l�ɔ��f�i������Ă���F�v���X1�C������Ă��Ȃ��F0�Ƀ��Z�b�g�j��////
		if (tmpKey[i] != 0) Key_g[i]++;// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����i�܂�l��1�Ȃ�j�P�����Z
		else Key_g[i] = 0;// ������Ă��Ȃ����0�ɂ���
	}
	return 0;	////�S�ẴL�[�̓��͏�Ԃ��Ăяo�����̒l�ɔ��f�i������Ă���F�v���X1�C������Ă��Ȃ��F0�Ƀ��Z�b�g�j��////
}
int gpUpdateJoypad(int *Joypad_g) {	////�����ꂼ��̃{�^���̓��͏�Ԃ�Joypad�̒l�ɔ��f�i������Ă���F�v���X1�C������Ă��Ȃ��F0�Ƀ��Z�b�g�j��////
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1) != 0) Joypad_g[1]++;	else Joypad_g[1] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_2) != 0) Joypad_g[2]++;	else Joypad_g[2] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0) Joypad_g[3]++;	else Joypad_g[3] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4) != 0) Joypad_g[4]++;	else Joypad_g[4] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) != 0) Joypad_g[5]++;	else Joypad_g[5] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) != 0) Joypad_g[6]++;	else Joypad_g[6] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_7) != 0) Joypad_g[7]++;	else Joypad_g[7] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8) != 0) Joypad_g[8]++;	else Joypad_g[8] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_9) != 0) Joypad_g[9]++;	else Joypad_g[9] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_10) != 0) Joypad_g[10]++;	else Joypad_g[10] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_11) != 0) Joypad_g[11]++;	else Joypad_g[11] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_12) != 0) Joypad_g[12]++;	else Joypad_g[12] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_13) != 0) Joypad_g[13]++;	else Joypad_g[13] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_14) != 0) Joypad_g[14]++;	else Joypad_g[14] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0) Joypad_g[15]++;	else Joypad_g[15] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0) Joypad_g[16]++;	else Joypad_g[16] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0) Joypad_g[17]++;	else Joypad_g[17] = 0;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) != 0) Joypad_g[18]++;	else Joypad_g[18] = 0;
	return 0;	////���ꂼ��̃{�^���̓��͏�Ԃ��Ăяo�����̒l�ɔ��f�i������Ă���F�v���X1�C������Ă��Ȃ��F0�Ƀ��Z�b�g�j��////
}




int ShowMsgDsignedBox(int LocationX, int LocationY, int Width,
	const char *Title, int TitleColor, int TitleBackColor, const char *Message, int MsgColor, int MsgBackColor
)
{
	struct AREACONTROL MsgBox = { 0 };
	MsgBox.Width = Width;
	MsgBox.Height = (SystemFontSize + 5 + 20) * 2;//5��TitleArea.Padding�B20��DisplayArea.Padding�B
	if (LocationX == -1) MsgBox.Location[0] = (WindowWidth - Width) / 2;//LocationX��-1�Ȃ��ʂ̍��E�Z���^�[�Ƀ{�b�N�X��z�u����
	else MsgBox.Location[0] = LocationX;
	if (LocationY == -1) MsgBox.Location[1] = (WindowHeight - MsgBox.Height) / 2;//LocationY��-1�Ȃ��ʂ̏㉺�Z���^�[�Ƀ{�b�N�X��z�u����
	else MsgBox.Location[1] = LocationY;
	ShowArea(&MsgBox, 1);

	struct AREACONTROL TitleArea = { 0 };
	TitleArea.ParentArea_p = &MsgBox;
	for (int i = 0; i < 4; i++) TitleArea.Padding[i] = 5;
	TitleArea.Width = MsgBox.Width;
	TitleArea.Height = TitleArea.Padding[1] + TitleArea.Padding[3] + SystemFontSize;
	TitleArea.BackColor = TitleBackColor;
	ShowArea(&TitleArea, 1);
	DrawStringInArea(0, 0, &TitleArea, Title, TitleColor);

	struct AREACONTROL DisplayArea = { 0 };
	DisplayArea.ParentArea_p = &MsgBox;
	for (int i = 0; i < 4; i++) DisplayArea.Padding[i] = 20;
	DisplayArea.Location[1] = TitleArea.Height;
	DisplayArea.Width = MsgBox.Width;
	DisplayArea.Height = DisplayArea.Padding[1] + DisplayArea.Padding[3] + SystemFontSize;
	DisplayArea.BackColor = MsgBackColor;
	ShowArea(&DisplayArea, 1);
	DrawStringInArea(0, 0, &DisplayArea, Message, MsgColor);

	return 0;
}


////////�G�摜���N���b�N�����Ƃ��̏���
BOOL GetOpenFileNameT(const TCHAR* initialdir_h, TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft) {
	TCHAR filepath[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FilePath_h�ɑ�����Ȃ�
	TCHAR filetitle[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FileTitle_h�ɑ�����Ȃ�
	//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��C�f�B���N�g���͌��̂܂�
	OPENFILENAME o;
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
									//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	o.lpstrInitialDir = _TEXT(initialdir_h);	//	�����t�H���_�[
	o.lpstrFile = filepath;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = filetitle;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y

	o.lpstrFilter = _TEXT("PNG�t�@�C��(*.png)\0*.png\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");
	o.lpstrDefExt = _TEXT("png");
	o.lpstrTitle = _TEXT("�摜�̎w��");
	o.nFilterIndex = 1;
	if (int aaa = GetOpenFileName(&o)) {//GetOpenFileName(&o)�̓��[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�A�����łȂ���� 0 ���Ԃ�
		//���t�@�C���p�X�Ɩ��t�@�C�������擾
		strcpy(FilePath_h, filepath); strcpy(FileTitle_h, filetitle);
		return 1;//���[�U�[�� OK �{�^������������0 �ȊO�i���ۂ͂P�j��Ԃ�
	}
	else {
		return 0;////���[�U�[�� OK �{�^���������Ȃ�������O��Ԃ�
	}
}
static
int CALLBACK SHBrowseProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	if (uMsg == BFFM_INITIALIZED && lpData)
	{
		//  �f�t�H���g�őI��������p�X�̎w��
		SendMessage(hWnd, BFFM_SETSELECTION, TRUE, lpData);
	}
	return 0;
}

static
void SHFree(ITEMIDLIST* pidl)
{
	IMalloc*  pMalloc;
	SHGetMalloc(&pMalloc);
	if (pMalloc)
	{
		pMalloc->Free(pidl);
		pMalloc->Release();
	}
}

BOOL GetOpenDirectoryName(LPCTSTR lpszDefaultFolder, LPTSTR lpszBuffer, DWORD dwBufferSize)//HWND hwndOwner, 
{
	BROWSEINFO  bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	//bi.hwndOwner = hwndOwner;
	bi.lpfn = SHBrowseProc;	//  �R�[���o�b�N�֐����w��
	bi.lParam = (LPARAM)lpszDefaultFolder;	//  �f�t�H���g�őI�������Ă����t�H���_���w��
	bi.lpszTitle = _T("�t�H���_��I�����Ă�������");	//  �^�C�g���̎w��

	ITEMIDLIST*  pidl = SHBrowseForFolder(&bi);	//  �t�H���_�_�C�A���O�̋N��
	if (pidl)
	{
		//  �I�����ꂽ�t�H���_�����擾
		TCHAR  szSelectedFolder[_MAX_PATH];
		SHGetPathFromIDList(pidl, szSelectedFolder);
		SHFree(pidl);
		if ((DWORD)_tcslen(szSelectedFolder) < dwBufferSize)
		{
			_tcsncpy_s(lpszBuffer, dwBufferSize, szSelectedFolder, _TRUNCATE);//��P�����F�I�������t�H���_�[
																			  //  �t�H���_���I�����ꂽ
			return TRUE;
		}
	}
	//  �t�H���_�͑I������Ȃ�����
	return FALSE;
}
////////�_�C�A���O�̏����Ǝ��s
BOOL GetOpenFileNameACM(const TCHAR *initialdir_h, TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft) {
	TCHAR filepath[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FilePath_h�ɑ�����Ȃ�
	TCHAR filetitle[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FileTitle_h�ɑ�����Ȃ�
	//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��C�f�B���N�g���͌��̂܂�
	OPENFILENAME o;
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
	//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	//strcat(initialdir_h, "\\���");//\\���DataFile
	o.lpstrInitialDir = _TEXT(initialdir_h);	//	�����t�H���_�[
	o.lpstrFile = filepath;			//	�擾�����t���p�X��ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t���p�X��ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = filetitle;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	//o.lpstrFilter = _TEXT("TEXT�t�@�C��(*.txt)\0*.txt;*.csv\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");//�H�H�H(*.txt;*.csv)�̂Ƃ���́A�{���ɂ���ŗǂ��́H�K���ɂ�����炤�܂�����������������m�F�v
	//o.lpstrDefExt = _TEXT("txt");
	o.lpstrFilter = _TEXT("ACM�t�@�C��(*.acm)\0*.acm\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");//�H�H�H(*.acm;*.csv)�̂Ƃ���́A�{���ɂ���ŗǂ��́H�K���ɂ�����炤�܂�����������������m�F�v
	o.lpstrDefExt = _TEXT("acm");
	o.lpstrTitle = _TEXT("�t�@�C�����J��");
	o.nFilterIndex = 1;
	if (int aaa = GetOpenFileName(&o)) {//GetOpenFileName(&o)�̓��[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�A�����łȂ���� 0 ���Ԃ�
		//���t�@�C���p�X�Ɩ��t�@�C�������擾
		strcpy(FilePath_h, filepath); strcpy(FileTitle_h, filetitle);
		return 1;//���[�U�[�� OK �{�^������������0 �ȊO�i���ۂ͂P�j��Ԃ�
	}
	else return 0;////���[�U�[�� OK �{�^���������Ȃ�������O��Ԃ�
}
BOOL GetOpenFileNameACK(const TCHAR *initialdir_h, TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft) {
	TCHAR filepath[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FilePath_h�ɑ�����Ȃ�
	TCHAR filetitle[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FileTitle_h�ɑ�����Ȃ�
	//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��C�f�B���N�g���͌��̂܂�
	OPENFILENAME o;
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
	//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	//strcat(initialdir_h, "\\���");//\\���DataFile
	o.lpstrInitialDir = _TEXT(initialdir_h);	//	�����t�H���_�[
	o.lpstrFile = filepath;			//	�擾�����t���p�X��ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t���p�X��ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = filetitle;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFilter = _TEXT("ACK�t�@�C��(*.ack)\0*.ack\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");
	o.lpstrDefExt = _TEXT("ack");
	o.lpstrTitle = _TEXT("�t�@�C�����J��");
	o.nFilterIndex = 1;
	if (GetOpenFileName(&o)) {//GetOpenFileName(&o)�̓��[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�A�����łȂ���� 0 ���Ԃ�
		//���t�@�C���p�X�Ɩ��t�@�C�������擾
		strcpy(FilePath_h, filepath); strcpy(FileTitle_h, filetitle);
		return 1;//���[�U�[�� OK �{�^������������0 �ȊO�i���ۂ͂P�j��Ԃ�
	}
	else return 0;////���[�U�[�� OK �{�^���������Ȃ�������O��Ԃ�
}
BOOL GetOpenFileNameACP(const TCHAR *initialdir_h, TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft) {
	TCHAR filepath[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FilePath_h�ɑ�����Ȃ�
	TCHAR filetitle[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FileTitle_h�ɑ�����Ȃ�
	//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��C�f�B���N�g���͌��̂܂�
	OPENFILENAME o;
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
	//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	//strcat(initialdir_h, "\\���");//\\���DataFile
	o.lpstrInitialDir = _TEXT(initialdir_h);	//	�����t�H���_�[
	o.lpstrFile = filepath;			//	�擾�����t���p�X��ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t���p�X��ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = filetitle;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFilter = _TEXT("ACP�t�@�C��(*.acp)\0*.acp\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");
	o.lpstrDefExt = _TEXT("acp");
	o.lpstrTitle = _TEXT("�t�@�C�����J��");
	o.nFilterIndex = 1;
	if (GetOpenFileName(&o)) {//GetOpenFileName(&o)�̓��[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�A�����łȂ���� 0 ���Ԃ�
		//���t�@�C���p�X�Ɩ��t�@�C�������擾
		strcpy(FilePath_h, filepath); strcpy(FileTitle_h, filetitle);
		return 1;//���[�U�[�� OK �{�^������������0 �ȊO�i���ۂ͂P�j��Ԃ�
	}
	else return 0;////���[�U�[�� OK �{�^���������Ȃ�������O��Ԃ�
}




BOOL GetOpenFileNameCsv(const TCHAR *initialdir_h, TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft) {
	TCHAR filepath[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FilePath_h�ɑ�����Ȃ�
	TCHAR filetitle[MAX_PATH] = { _T('\0') };//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FileTitle_h�ɑ�����Ȃ�
	//GetOpenFileName�́C�_�C�A���O��OK�������Ȃ������Ƃ��C�f�B���N�g���͌��̂܂�
	OPENFILENAME o;
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
									//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��

									//strcat(initialdir_h, "\\���");//\\���DataFile
	o.lpstrInitialDir = _TEXT(initialdir_h);	//	�����t�H���_�[
	o.lpstrFile = filepath;			//	�擾�����t���p�X��ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t���p�X��ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = filetitle;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFilter = _TEXT("CSV�t�@�C��(*.csv)\0*.csv\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");//�H�H�H(*.txt;*.csv)�̂Ƃ���́A�{���ɂ���ŗǂ��́H�K���ɂ�����炤�܂�����������������m�F�v
	o.lpstrDefExt = _TEXT("csv");
	o.lpstrTitle = _TEXT("�t�@�C�����J��");
	o.nFilterIndex = 1;

	if (int aaa = GetOpenFileName(&o)) {//GetOpenFileName(&o)�̓��[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�A�����łȂ���� 0 ���Ԃ�
		strcpy(FilePath_h, filepath); strcpy(FileTitle_h, filetitle);
		return 1;//���[�U�[�� OK �{�^������������0 �ȊO�i���ۂ͂P�j��Ԃ�
	}
	else {
		return 0;////���[�U�[�� OK �{�^���������Ȃ�������O��Ԃ�
	}
}

BOOL GetImgFileName(const TCHAR* initialdir_h, TCHAR* file, TCHAR* filetitle, const int mf, const int mft, int FileType) {
	OPENFILENAME o;
	file[0] = _T('\0');
	filetitle[0] = _T('\0');
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
									//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��

									//strcat(initialdir_h, "\\���");//\\���DataFile
	o.lpstrInitialDir = _TEXT(initialdir_h);	//	�����t�H���_�[
	o.lpstrFile = file;			//	�擾�����t���p�X��ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t���p�X��ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = filetitle;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	if (FileType == 0) {
		o.lpstrFilter = _TEXT("�摜�t�@�C��(png,jpg,bmp,dds,ARGB,tga)\0*.png;*.jpg;*.bmp;*.dds;*.ARGB;*.tga\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");//�H�H�H(*.txt;*.csv)�̂Ƃ���́A�{���ɂ���ŗǂ��́H�K���ɂ�����炤�܂�����������������m�F�v
		o.lpstrDefExt = _TEXT("txt");
	}
	else {//FileType == 1
		o.lpstrFilter = _TEXT("�����t�@�C��(mp3)\0*.mp3\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");//�H�H�H(*.txt;*.csv)�̂Ƃ���́A�{���ɂ���ŗǂ��́H�K���ɂ�����炤�܂�����������������m�F�v
		o.lpstrDefExt = _TEXT("mp3");
	}

	o.lpstrTitle = _TEXT("�t�@�C�����J��");
	o.nFilterIndex = 1;
	return GetOpenFileName(&o);
}
/*
//���b�Z�[�W�t�@�C���C���t�@�C���I��p
int FileOpen(char* ActiveDirectory_h, TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft) {
	TCHAR filepath[MAX_PATH] = { _T('\0') };//GetOpenFileNameText�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FilePath_h�ɑ�����Ȃ�
	TCHAR filetitle[MAX_PATH] = { _T('\0') };//GetOpenFileNameText�́C�_�C�A���O��OK�������Ȃ������Ƃ��J���ɂȂ邽�߁C����FileTitle_h�ɑ�����Ȃ�
	//GetOpenFileNameText�́C�_�C�A���O��OK�������Ȃ������Ƃ��C�f�B���N�g���͌��̂܂�

	//���݂̃f�B���N�g���̊m�F
	char DrectoryCheck[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, DrectoryCheck);//�`�F�b�N�p
	if (GetOpenFileNameText(ActiveDirectory_h, filepath, filetitle, mf, mft)) {//�_�C�A���O�Ń��[�U�[��OK���������i�܂�߂�l��0�ȊO�j
		//���t�@�C���p�X�Ɩ��t�@�C�������擾
		strcpy(FilePath_h, filepath); strcpy(FileTitle_h, filetitle);
		//���f�B���N�g�����擾
		GetCurrentDirectory(MAX_PATH, ActiveDirectory_h);//���f�B���N�g�����擾�i�I�������t�@�C����������f�B���N�g���j
		//�擾�����f�B���N�g������̑��΃p�X���擾
		PathRelativePathTo(FilePath_h, ActiveDirectory_h, FILE_ATTRIBUTE_DIRECTORY, FilePath_h, FILE_ATTRIBUTE_ARCHIVE);//��΃p�X�i��S�����j���瑊�΃p�X�i��P�����j���擾
		return 1;
	}
	else return 0;

}
*/



////////////�����X�^�[�摜�̕ύX�i�O�񃂃��X�^�[�I���_�C�A���O�I�����̃f�B���N�g����Directory�Ɋm�ۂ��Ă���j
int MonsterImgChange(char* MonsterDir_h, char* MonsterImgPath_h, int* MonsterImg_p, int* monsterwide_p, int* monsterhight_p) {
	//���݂̃f�B���N�g���̎擾
	//static char DirectorySelectKeep[MAX_PATH];//�O��̃����X�^�[�摜��I�������f�B���N�g��
	//�_�C�A���O�J�n���̃f�B���N�g���̊m��
	//const char *Dir_h;
	//if (*DirectorySelectKeep) Dir_h = DirectorySelectKeep;//�O��̑I�������f�B���N�g��������΁C������g��
	//else Dir_h = MonsterDir_h;//�Ȃ���΁C�����Ŏw�肳�ꂽ�f�B���N�g�����g��

	//���_�C�A���O�Ńt�@�C���p�X���擾
	char FileTitle[MAX_PATH];//�_�~�[�̈���
	if (GetOpenFileNameT(MonsterDir_h, MonsterImgPath_h, FileTitle, MAX_PATH, MAX_PATH)) {//�_�C�A���O�ɂ��摜�t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
		//�t�@�C�����̎擾�ɐ��������Ƃ�
		//GetCurrentDirectory(MAX_PATH, DirectorySelectKeep);//���݂̃f�B���N�g���̋L�^
		*MonsterImg_p = LoadGraph(MonsterImgPath_h);//�擾������΃p�X�Ń��[�h
		GetGraphSize(*MonsterImg_p, monsterwide_p, monsterhight_p); //�����X�^�[�̉摜�̏c���T�C�Y���擾����monsterwide�Cmonsterhight�ɏ����o��
		PathRelativePathTo(MonsterImgPath_h, MonsterDir_h, FILE_ATTRIBUTE_DIRECTORY, MonsterImgPath_h, FILE_ATTRIBUTE_ARCHIVE);//��΃p�X�i��S�����j���瑊�΃p�X�i��P�����j���擾�i�����ł͓����ϐ����g���j
		return 1;
	}
	else return 0;
	//���݂̃f�B���N�g���̊m�F
	//char DrectoryCheck[MAX_PATH];
	//GetCurrentDirectory(MAX_PATH, DrectoryCheck);//�`�F�b�N�p
}



////////////�_�C�A���O�Ŗ��t�@�C���̃��[�h////////////
int EditorModeChecker(int *EditorMode_p, char *FilePath_h) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
	//���݂̃f�B���N�g���̊m�F
	char DrectoryCheck[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, DrectoryCheck);//�`�F�b�N�p

	char Kakuchoshi[5] = {0};//
	int mojisuu = strlen(FilePath_h);
	Kakuchoshi[0] = FilePath_h[mojisuu - 3];
	Kakuchoshi[1] = FilePath_h[mojisuu - 2];
	Kakuchoshi[2] = FilePath_h[mojisuu - 1];


	if (strcmp(Kakuchoshi, "acm") == 0) *EditorMode_p = 0;//�O�F���b�Z�[�W�ҏW���[�h
	else if (strcmp(Kakuchoshi, "ack") == 0) *EditorMode_p = 1;//�P�F���ҏW���[�h
	else if (strcmp(Kakuchoshi, "acp") == 0) *EditorMode_p = 2;//�Q�F�p�b�h�ҏW���[�h
	else return -2;//�ǂ̃��[�h�ɂ��Y�����Ȃ�

	/*
	//���b�Z�[�W�^�C�v�̃��[�h
	char MessageType[100];
	FILE *fp = fopen(FilePath_h, "r");//�e�L�X�g�t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ��i�Y���t�@�C�������݂��Ȃ��j
		return -1;//�Y���t�@�C���Ȃ�
	}
	char buff;
	char textbuff[MAX_PATH];//
	//////
	for (int k = 0; buff = fgetc(fp); k++) {
		if (buff == ',' || buff == '\n' || buff == EOF) {
			textbuff[k] = '\0';
			break;
		}
		textbuff[k] = buff;
	}
	strcpy(MessageType, textbuff);
	fclose(fp);//�t�@�C�������
			   //////////////////////
	if (strcmp(MessageType, "Message") == 0) *EditorMode_p = 0;//�O�F���b�Z�[�W�ҏW���[�h
	else if (strcmp(MessageType, "Mondai") == 0) *EditorMode_p = 1;//�P�F���ҏW���[�h
	else if (strcmp(MessageType, "AreaN") == 0) *EditorMode_p = 2;//�Q�F�p�b�h�ҏW���[�h
	else return -2;//�ǂ̃��[�h�ɂ��Y�����Ȃ�
	*/

	///////////////////
	return 0;//����
}
//���ݒ�̃Z�[�u�i�t�H���g�C�t�H���g�摜�C�^�O�ݒ�̃Z�[�u�j
int SaveJoypadSetPath(const TCHAR* file_h) {
	if (strcmp(FileTitle_Joypad_rw, "�Ȃ�") == 0) {//�V�K�쐬���Ȃ�
		return -2;
	}
	FILE *fp = fopen(file_h, "w");//�e�L�X�g�t�@�C�����J��//�t�@�C�����Ȃ���ΐV�K�쐬
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return -1;
	}
	fputs("Dir_Joypad_rw,", fp); fputs(Dir_Joypad_rw, fp); fputs("\n", fp); //�W���C�p�b�h�̃f�B���N�g���̕ۑ�
	fputs("FileTitle_Joypad_rw,", fp); fputs(FileTitle_Joypad_rw, fp); fputs("\n", fp); //�W���C�p�b�h�̃t�@�C�����̕ۑ�

	fclose(fp);//�t�@�C�������
	return 0;
}

//���ݒ�̃Z�[�u�i�t�H���g�C�t�H���g�摜�C�^�O�ݒ�̃Z�[�u�j
int SaveFontTagSetPath(const TCHAR* file_h) {
	if (strcmp(FileTitle_Font_rw, "�Ȃ�") == 0){//�V�K�쐬���Ȃ�
		return -2;
	}
	FILE *fp = fopen(file_h, "w");//�e�L�X�g�t�@�C�����J��//�t�@�C�����Ȃ���ΐV�K�쐬
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return -1;
	}
	fputs("Dir_FontSet_rw,", fp); fputs(Dir_FontSet_rw, fp); fputs("\n", fp); //�t�H���g�Z�b�g�̃f�B���N�g���̕ۑ�
	fputs("FileTitle_Font_rw,", fp); fputs(FileTitle_Font_rw, fp); fputs("\n", fp); //�t�H���g�Z�b�g�̃t�@�C�����̕ۑ�

	fputs("Dir_FontImgSet_rw,", fp); fputs(Dir_FontImgSet_rw, fp); fputs("\n", fp); //�t�H���g�摜�Z�b�g�̃f�B���N�g���̕ۑ�
	fputs("FileTitle_FontImg_rw,", fp); fputs(FileTitle_FontImg_rw, fp); fputs("\n", fp); //�t�H���g�摜�Z�b�g�̃t�@�C�����̕ۑ�

	fputs("Dir_TagSet_rw,", fp); fputs(Dir_TagSet_rw, fp); fputs("\n", fp); //�^�O�Z�b�g�̃f�B���N�g���̕ۑ�
	fputs("FileTitle_Tag_rw,", fp); fputs(FileTitle_Tag_rw, fp); fputs("\n", fp); //�^�O�Z�b�g�̃t�@�C�����̕ۑ�

	fputs("Dir_AppImg_rw,", fp); fputs(Dir_AppImg_rw, fp); fputs("\n", fp); //�A�v�����L�摜�̃f�B���N�g���̕ۑ�

	fputs("Dir_AppSound_rw,", fp); fputs(Dir_AppSound_rw, fp); fputs("\n", fp); //�A�v�����L�����̃f�B���N�g���̕ۑ�

	fclose(fp);//�t�@�C�������
	return 0;
}
//�����b�Z�[�W�{�b�N�X�R���g���[���̃Z�[�u
int SaveMsgBoxForm(const TCHAR *file_h, struct MsgBoxForm *MsgBoxForm_p, struct MsgBoxForm_RGB_SoundPath *MsgBoxForm_RGB_SoundPath_p, int MsgBoxForm_Kosuu) {
	FILE *fp = fopen(file_h, "w");//�e�L�X�g�t�@�C�����J��//�t�@�C�����Ȃ���ΐV�K�쐬
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return -1;
	}
	char textbuff[100];
	for (int i = 0; i < MsgBoxForm_Kosuu; i++) {
		//�J�n�s�i����������Ă��Ȃ��ƁC���[�h���ɁC����ȏ�t�H�[�����Ȃ��Ɣ��f����Ă��܂��j
		fputs("*** MsgBoxForm", fp);
		_itoa(i, textbuff, 10);
		fputs(textbuff, fp); //�t�H���g�Z�b�g�̃t�@�C�����̕ۑ�
		fputs(" ***\n", fp); //���s������
		//MaxLine�̃Z�[�u
		fputs("MaxLine,", fp); //�t�H���g�Z�b�g�̃t�@�C�����̕ۑ�
		_itoa(MsgBoxForm_p[i].MaxLine, textbuff, 10);
		fputs(textbuff, fp); //�t�H���g�Z�b�g�̃t�@�C�����̕ۑ�
		fputs("\n", fp); //���s������
		//Margin[4]�̃Z�[�u
		fputs("Margin[4]", fp); //�t�H���g�Z�b�g�̃t�@�C�����̕ۑ�
		for (int c = 0; c < 4; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_p[i].Margin[c], textbuff, 10);
			fputs(textbuff, fp); //�t�H���g�Z�b�g�̃t�@�C�����̕ۑ�
		}
		fputs("\n", fp); //���s������
		//Padding[4]�̃Z�[�u
		fputs("Padding[4]", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 4; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_p[i].Padding[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������

		//BorderColorRGB[3]�̃Z�[�u
		fputs("BorderColorRGB[3]", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_RGB_SoundPath_p[i].BorderColorRGB[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
		//BorderThickness�̃Z�[�u
		fputs("BorderThickness,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].BorderThickness, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//BorderType�̃Z�[�u
		fputs("BorderType,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].BorderType, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//BackColorRGB[3]�̃Z�[�u
		fputs("BackColorRGB[3]", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_RGB_SoundPath_p[i].BackColorRGB[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
		//BackGroundTransparency�̃Z�[�u
		fputs("BackGroundTransparency,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].BackTransparency, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//ActiveTagColorRGB�̃Z�[�u
		fputs("ActiveTagColorRGB[3]", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_RGB_SoundPath_p[i].ActiveTagColorRGB[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
		//ActiveTagColorTransparency�̃Z�[�u
		fputs("ActiveTagColorTransparency,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].ActiveTagColorTransparency, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//ActiveMathColorRGB��
		fputs("ActiveMathColorRGB[3]", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_RGB_SoundPath_p[i].ActiveMathColorRGB[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
		//ActiveMathColorTransparency�̃Z�[�u
		fputs("ActiveMathColorTransparency,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].ActiveMathColorTransparency, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//FontColorRGB�̃Z�[�u
		fputs("FontColorRGB[3]", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxForm_p[i].FontColorRGB[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
		//Leading�̂̃Z�[�u
		fputs("Leading,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].Leading, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//BlinkSpeed�̃Z�[�u
		fputs("BlinkSpeed,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].BlinkSpeed, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//OutputSpeed�̃Z�[�u
		fputs("OutputSpeed,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].OutputSpeed, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//ScrollSpeed�̃Z�[�u
		fputs("ScrollSpeed,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].ScrollSpeed, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//Option�̃Z�[�u
		fputs("Option,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxForm_p[i].Option, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//Sound_Message�i�p�J�p�J����X�N���[�����j�̃Z�[�u
		fputs("MessageSound,", fp);//���ږ��̕ۑ�
		fputs(MsgBoxForm_RGB_SoundPath_p[i].MessageSoundPath, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//Sound_Move�i�J�[�\���̈ړ����j�̃Z�[�u
		fputs("ConfirmSound,", fp);//���ږ��̕ۑ�
		fputs(MsgBoxForm_RGB_SoundPath_p[i].BackDelSoundPath, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//Sound_Push�i�ҋ@���i�����I���E���t�j�̃{�^�������j�̃Z�[�u
		fputs("BackDelSound,", fp);//���ږ��̕ۑ�
		fputs(MsgBoxForm_RGB_SoundPath_p[i].ConfirmSoundPath, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
	}
	fclose(fp);//�t�@�C�������
	return 0;
}
//�����b�Z�[�W�{�b�N�X�t�H�[���̃Z�[�u
int SaveMsgBoxCtrl(const TCHAR *file_h, struct MsgBoxCtrl *MsgBoxCtrl_p, int MsgBoxCtrl_Kosuu, int *MsgBoxFormNumber_h) {
	FILE *fp = fopen(file_h, "w");//�e�L�X�g�t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ��i�Y������t�@�C�������݂��Ȃ��j
		return -1;
	}
	char textbuff[100];
	for (int i = 0; i < MsgBoxCtrl_Kosuu; i++) {
		fputs("�Ƃ΂�", fp); //�Ƃ΂��s�̕ۑ�
		fputs("\n", fp); //���s������
		//MsgBoxFormNumber�̃Z�[�u
		fputs("MsgBoxFormNumber,", fp); //���ږ��̕ۑ�
		_itoa(MsgBoxFormNumber_h[i], textbuff, 10);
		fputs(textbuff, fp); //�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//Location[2]�̃Z�[�u
		fputs("Location[2]", fp); //���ږ��̕ۑ�
		for (int c = 0; c < 2; c++) {
			fputs(",", fp); //�J���}������
			_itoa(MsgBoxCtrl_p[i].Location[c], textbuff, 10);
			fputs(textbuff, fp); //�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
		//Width�̃Z�[�u
		fputs("Width,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxCtrl_p[i].Width, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
		//Height�Z�[�u
		fputs("Height,", fp);//���ږ��̕ۑ�
		_itoa(MsgBoxCtrl_p[i].Height, textbuff, 10);
		fputs(textbuff, fp);//�f�[�^�̕ۑ�
		fputs("\n", fp); //���s������
	}
	fclose(fp);//�t�@�C�������
	return 0;
}




////////���O��t���ĕۑ��_�C�A���O�̏����Ǝ��s
BOOL GetSaveFileNameACM(const TCHAR* InitialDir_h, TCHAR* File_h, TCHAR* FileTitle_h, const int mf, const int mft) {
	OPENFILENAME o;
	File_h[0] = _T('\0');
	FileTitle_h[0] = _T('\0');
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
									//o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	o.lpstrInitialDir = _TEXT(InitialDir_h);	//	�����t�H���_�[
	o.lpstrFile = File_h;			//	�擾�����t���p�X��ۑ�����o�b�t�@
	o.nMaxFile = mf;				//	�擾�����t���p�X��ۑ�����o�b�t�@�T�C�Y
	o.lpstrFileTitle = FileTitle_h;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFileTitle = mft;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFilter = _TEXT("ACM�t�@�C��(*.acm)\0*.acm\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");
	o.lpstrDefExt = _TEXT("acm");
	o.lpstrTitle = _TEXT("���O��t���ĕۑ�");
	o.nFilterIndex = 1;
	o.Flags = OFN_OVERWRITEPROMPT;//�㏑���̊m�F���b�Z�[�W��\������
	return GetSaveFileName(&o);
}

////////���̕ۑ�
int SaveMondai(const TCHAR* FilePath_h, const struct Kadai* Mondai_p) {
	FILE *fp = fopen(FilePath_h, "w");//�e�L�X�g�t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return -1;
	}
	char textbuff[20];
	fputs("Mondai", fp); //�����X�^�[�h�c�̃Z�[�u
	fputs("\n", fp); //���s������
	_itoa(Mondai_p->monsterID, textbuff, 10);//�����X�^�[ID�𕶎���ɕϊ�
	fputs(textbuff, fp); //�����X�^�[�h�c�̃Z�[�u
	fputs("\n", fp); //���s������
	fputs(Mondai_p->daimon, fp); //���̃Z�[�u
	fputs("\n", fp); //���s������
	fputs(Mondai_p->daimonseikai, fp); //��␳���̃Z�[�u
	fputs("\n", fp); //���s������
	for (int i = 0; Mondai_p->syoumon[i][0] != '\0' && Mondai_p->syoumonseikai[i][0] != '\0' && i < SYOUMON_MAX; i++) {
		fputs(Mondai_p->syoumon[i], fp); //����̃Z�[�u
		fputs("\n", fp); //���s������
		fputs(Mondai_p->syoumonseikai[i], fp); //���␳���̃Z�[�u
		fputs("\n", fp); //���s������
	}
	fclose(fp);//�t�@�C�������
	return 0;
}
////////���@���O�����ĕۑ��i�_�C�A���O�{���̃Z�[�u�j
int SaveAsNewMondai(TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft, const struct Kadai *Mondai_p) {
	if (GetSaveFileNameACM(LocalDir, FilePath_h, FileTitle_h, mf, mft)) {
		SaveMondai(FilePath_h, Mondai_p);//�_�C�A���O�Ő؂�ւ�����f�B���N�g���Ńt�@�C�����J��
	}
	return 0;
}
////////���@�㏑���ۑ��i�ۑ��܂��͖��O��t���ĕۑ��j
int OverwriteMondai(TCHAR *FilePath_h, TCHAR *FileTitle_h, const int mf, const int mft, const struct Kadai *Mondai_p) {
	//SetCurrentDirectory(LocalDir);//�f�B���N�g����ύX����B��΃p�X�ŊǗ����Ă��邩������s�v���Ǝv���B
	if (strcmp(FileTitle_h, "����")) SaveMondai(FilePath_h, Mondai_p);////�g���q�Ȃ��́u����v�̂Ƃ��ȊO�͏㏑���ۑ�
	else SaveAsNewMondai(FilePath_h, FileTitle_h, mf, mft, Mondai_p);//�g���q�Ȃ��́u����v�́C���O��t���ĕۑ�
	return 0;
}
////////���b�Z�[�W�̕ۑ�
int SaveMessage(const char* File_h, const char* Message_h, const int TagKosuu) {
	if (File_h==nullptr) return -2;
	FILE *fp = fopen(File_h, "w");//
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return -1;
	}
	fputs("Message", fp); //�����X�^�[�h�c�̃Z�[�u
	fputs(",", fp); //�����X�^�[�h�c�̃Z�[�u
	char textbuff[4];
	_itoa(TagKosuu, textbuff, 10);
	fputs(textbuff, fp); //�����X�^�[�h�c�̃Z�[�u
	fputs("\n", fp); //���s������
	fputs(Message_h, fp); //���̃Z�[�u
	fputs("\n", fp); //���s������
	fclose(fp);//�t�@�C�������
	return 0;
}
////////���b�Z�[�W�@���O�����ĕۑ��i�_�C�A���O�{���̃Z�[�u�j
int SaveAsNewMessage(CHAR* FilePath_h, TCHAR* FileTitle_h, const int mf, const int mft, const char* Message_h, const int TagNumMax) {

	if (GetSaveFileNameACM(LocalDir, FilePath_h, FileTitle_h, mf, mft)) {//�_�C�A���O�ɂ��t�@�C�����̎擾
		SaveMessage(FilePath_h, Message_h, TagNumMax);//�_�C�A���O�Ő؂�ւ�����f�B���N�g���Ńt�@�C�����J��
	}
	return 0;
}
////////���b�Z�[�W�@�㏑���ۑ��i�ۑ��܂��͖��O��t���ĕۑ��j
int OverwriteMessage(TCHAR* FilePath_h, TCHAR* FileTitle_h, const int mf, const int mft, const char* Message_h, const int TagNumMax) {
	//SetCurrentDirectory(LocalDir);//�f�B���N�g����ύX����
	if (strcmp(FileTitle_h, "����")) SaveMessage(FilePath_h, Message_h, TagNumMax);////�g���q�Ȃ��́u����v�̂Ƃ��ȊO�͏㏑���ۑ�
	else SaveAsNewMessage(FilePath_h, FileTitle_h, mf, mft, Message_h, TagNumMax);//�g���q�Ȃ��́u����v�́C���O��t���ĕۑ�
	return 0;
}

////////�����X�^�[�e�[�u���̃Z�[�u
int SaveMonster(const char* FilePath_h, struct Monster *Monster, const int Monster_Kosuu, int IssuedMoonsterID_p, const char(*ColumnTitle)[MONSTER_COLUMNTITLEFIELDMAX + 1], const int Column_Kosuu, const char(*MonsterImgPath)[MAX_PATH]) {
	//SetCurrentDirectory(LocalDir);//�f�B���N�g����ύX����
	//SetCurrentDirectory(".\\Monster");//�f�B���N�g����ύX����
	//���݂̃f�B���N�g���̊m�F
	//char DrectoryCheck[MAX_PATH];
	//GetCurrentDirectory(MAX_PATH, DrectoryCheck);//�`�F�b�N�p

	FILE *fp = fopen(FilePath_h, "w");//�e�L�X�g�t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return -1;
	}
	char textbuff[20];
	fputs("���s�ςݍő�ID", fp);//�J�����O�̃^�C�g���i�����X�^�[ID�j�̏�������
	fputs(",", fp);//�J���}�̏�������
	_itoa(IssuedMoonsterID_p, textbuff, 10);//�����X�^�[ID�𕶎���ɕϊ�
	fputs(textbuff, fp);//�J�����O�̃^�C�g���i�����X�^�[ID�j�̏�������
	fputs("\n", fp);//���s�����̏�������

	//���J�����^�C�g���̏�������
	fputs(ColumnTitle[0], fp);//�J�����O�̃^�C�g���i�����X�^�[ID�j�̏�������
	fputs(",", fp);//�J���}�̏�������
	fputs("���O", fp);//�����X�^�[���̃^�C�g���̏�������
	fputs(",", fp);//�J���}�̏�������
	fputs("�摜", fp);//�摜�p�X�̃^�C�g���̏�������
	fputs(",", fp);//�J���}�̏�������
	for (int i = 1; i < Column_Kosuu; i++) {//�J�����P�`�ŏI�J�����̃^�C�g���̏�������
		fputs(ColumnTitle[i], fp);//�J�����^�C�g�����Ԃ̏�������
		if (i < Column_Kosuu - 1) fputs(",", fp);//�J���}�̏�������
	}
	fputs("\n", fp);//���s�����̏�������

	//���J�����̏�������
	for (int k = 0; k < Monster_Kosuu; k++) {
		//�J�����O�i�����X�^�[ID)�̃Z�[�u

		if (Monster[k].Column[0] == 0)break;//�J�����O���J���̂Ƃ��͏������݃��[�v���甲����191105
		/////�ʂ̔z����Z�[�u��
		_itoa(Monster[k].Column[0], textbuff, 10);//�����X�^�[ID�𕶎���ɕϊ�
		fputs(textbuff, fp);//�����X�^�[���Ԃ̃J�����O�̏�������
		fputs(",", fp);//�J���}�̏�������

		fputs(Monster[k].Name, fp);//�����X�^�[���Ԃ̃����X�^�[���̏�������
		fputs(",", fp);//�J���}�̏�������
		fputs(MonsterImgPath[k], fp);//�����X�^�[���Ԃ̃����X�^�[�摜�p�X�̏�������
		fputs(",", fp);//�J���}�̏�������
		for (int i = 1; i < Column_Kosuu; i++) {
			_itoa(Monster[k].Column[i], textbuff, 10);//�J�����𕶎���ɕϊ�
			fputs(textbuff, fp);//�����X�^�[���Ԃ̃J�������Ԃ̏�������
			if (i < Column_Kosuu - 1) fputs(",", fp);//�J���}�̏�������
		}
		fputs("\n", fp);//���s�����̏�������
	}
	fclose(fp);//�t�@�C�������
	return 0;
}

//�G�f�B�^�[�̐ݒ�i�w�i�F�C�w�i�摜�j�̃Z�[�u
int SaveEditorSettings(const TCHAR* file_h, AREACONTROL *Area_p, int(*BorderColorRGB)[3], int (*BackColorRGB)[3], TCHAR (*BackImg_Path_p)[MAX_PATH], int AreaKosuu) {
	//SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	//���݂̃f�B���N�g���̊m�F
	//char DrectoryCheck[MAX_PATH];
	//GetCurrentDirectory(MAX_PATH, DrectoryCheck);//�`�F�b�N�p
	//�t�@�C���̏�������
	FILE *fp = fopen(file_h, "w");//�e�L�X�g�t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ��i�Y������t�@�C�������݂��Ȃ��j
		return -1;
	}
	char textbuff[MAX_PATH] = { 0 };
	for (int AreaN = 0; AreaN < AreaKosuu; AreaN++) {
		//���ږ��̏�������
		fputs("����̐F", fp); //���ږ��̕ۑ�
		//�w�i�F�̏�������
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(BorderColorRGB[AreaN][c], textbuff, 10);
			fputs(textbuff, fp); //�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������

		//���ږ��@����̈ʒu�̏�������
		fputs("����̈ʒu", fp);//���ږ��̕ۑ�
		for (int c = 0; c < 2; c++) {
			fputs(",", fp); //�J���}������
			_itoa(Area_p[AreaN].Padding[c], textbuff, 10);
			fputs(textbuff, fp);//�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������
	//���ږ��̏�������
		fputs("�w�i�F", fp); //���ږ��̕ۑ�
		//�w�i�F�̏�������
		for (int c = 0; c < 3; c++) {
			fputs(",", fp); //�J���}������
			_itoa(BackColorRGB[AreaN][c], textbuff, 10);
			fputs(textbuff, fp); //�f�[�^�̕ۑ�
		}
		fputs("\n", fp); //���s������

		//���ږ��̏�������
		fputs("�w�i�摜,", fp);
		//�p�X�̏�������
		fputs(BackImg_Path_p[AreaN], fp);
		fputs("\n", fp); //���s������
	}
	fclose(fp);//�t�@�C�������
	return 0;
}
//�G�f�B�^�[�̐ݒ�i�w�i�F�C�w�i�摜�j�̃��[�h
int LoadEditorSettings(const TCHAR* FilePath_h, int(*BorderColorRGB)[3], int(*BackColorRGB)[3], TCHAR(*BackImg_Path_p)[MAX_PATH], AREACONTROL *Area_p, int AreaKosuu) {//�E�̂悤�ɔz��ɂ���Ə��������ł��Ȃ��H��int BGI_ColorRGB[][3], TCHAR BGI_Path_p[][MAX_PATH], 
	//��΃p�X�i��S�����j���瑊�΃p�X�i��P�����j���擾

	char buff;
	//�t�@�C���̏�������
	FILE *fp = fopen(FilePath_h, "r");//�e�L�X�g�t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ��i�Y������t�@�C�������݂��Ȃ��j
		return -1;
	}
	char textbuff[MAX_PATH] = { 0 };
	for (int AreaN = 0; AreaN < AreaKosuu; AreaN++) {
		//���ږ��̎擾
		for (int k = 0; buff = fgetc(fp); k++) {//���ږ� ����̐F ���΂�
			if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
		}
		//����̐F�̎擾
		for (int c = 0; c < 3; c++) {//BackColorRGB[0]�CBackColorRGB[1]�CBackColorRGB[3]�̃��[�h
			for (int k = 0; buff = fgetc(fp); k++) {
				if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
				textbuff[k] = buff;
			}
			//����̐F��ϐ�BorderColorRGB�Ɏ擾
			BorderColorRGB[AreaN][c] = atoi(textbuff);
		}
		//����̐F��ϐ�BorderColor�Ɏ擾
		if (BorderColorRGB[AreaN][0] >= 0) Area_p[AreaN].BorderColor = GetColor(BorderColorRGB[AreaN][0], BorderColorRGB[AreaN][1], BorderColorRGB[AreaN][2]);

		//���ږ��̎擾
		//Padding�̃��[�h
		for (int k = 0; buff = fgetc(fp); k++) {//���ږ�Padding[4]���΂�
			if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
		}
		for (int c = 0; c < 2; c++) {//Padding[0]�CPadding[1]
			for (int k = 0; buff = fgetc(fp); k++) {//Padding[0]�̃��[�h
				if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
				textbuff[k] = buff;
			}
			Area_p[AreaN].Padding[c] = atoi(textbuff);
		}



		//���ږ��̎擾
		for (int k = 0; buff = fgetc(fp); k++) {//���ږ�BackColorRGB[3]��΂�
			if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
		}
		//BackColorRGB�̎擾
		for (int c = 0; c < 3; c++) {//BackColorRGB[0]�CBackColorRGB[1]�CBackColorRGB[3]�̃��[�h
			for (int k = 0; buff = fgetc(fp); k++) {
				if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
				textbuff[k] = buff;
			}
			//�w�i�FRGB�̎擾
			BackColorRGB[AreaN][c] = atoi(textbuff);
		}
		//�w�i�F�n���h���̎擾
		if (BackColorRGB[AreaN][0] >= 0) Area_p[AreaN].BackColor = GetColor(BackColorRGB[AreaN][0], BackColorRGB[AreaN][1], BackColorRGB[AreaN][2]);

		//���ږ��̎擾
		for (int k = 0; buff = fgetc(fp); k++) {
			if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
			textbuff[k] = buff;
		}
		//������̎擾
		for (int k = 0; buff = fgetc(fp); k++) {
			if (buff == ',' || buff == '\n' || buff == EOF) { textbuff[k] = '\0'; break; }
			textbuff[k] = buff;
		}
		//�w�i�摜�p�X�̎擾
		strcpy(BackImg_Path_p[AreaN], textbuff);
		//�w�i�摜�n���h���̎擾
		if (textbuff[0] != '\0') Area_p[AreaN].BackImg = LoadGraph(BackImg_Path_p[AreaN]);
	}






	fclose(fp);//�t�@�C�������
	return 0;
}

struct MonsterTable
{
	int tablewaku[4];
	int yousono[4];
	int ID[4];//���e�̕\��
	int name[4];//���e�̕\��
	int gazou[4];
	int kougeki[4];//���e�̕\��
	int syuuki[4];//���e�̕\��
	int maryokuspeed[4];//���e�̕\��
	int frame[4];//���e�̕\��
	int mahouID[4];//���e�̕\��
	int mahousuuchi[4];//���e�̕\��
	int keikenchi[4];
	int coin[4];
};
struct MonsterTableAll
{
	int tablewaku[4];
	int yousono[4];
	int name[4];//���e�̕\��
	int gazou[4];
	int column[MONSTER_COLUMNMAX][4];

	int nametitle[4];//���e�̕\��
	int columntitle[MONSTER_COLUMNMAX][4];//x1,y1,x2,y2
};

//�A�N�e�B�u�ȍ��ڂ̓��͊m��@����с@���ځC����C���␳���̃A�N�e�B�u��Ԃ̃��Z�b�g
int activereset_T(struct Monster *Monster_p, int* activezokusei, int* activemonster, const int InputHandle) {
	if (InputHandle != NULL) {
		if (*activezokusei == 0) {//ID�̑��
			Monster_p[*activemonster].Column[0] = GetKeyInputNumber(InputHandle);	//ID�̕�������擾����i���͒��ł����͌�ł��g����֐��j
		}
		else if (*activezokusei == -20) GetKeyInputString(Monster_p[*activemonster].Name, InputHandle);	//�����X�^�[���̕�������擾����i���͒��ł����͌�ł��g����֐��j
		//else if (*activezokusei == -30) *ColumnKosuu = GetKeyInputNumber(InputHandle);	//�J�����̌��̕�������擾����i���͒��ł����͌�ł��g����֐��j
		for (int i = 1; i < MONSTER_COLUMNMAX; i++) {
			if (*activezokusei == i) Monster_p[*activemonster].Column[i] = GetKeyInputNumber(InputHandle);//�Y���J�����̕��������
		}
	}
	DeleteKeyInput(InputHandle);//�L�[���̓f�[�^�̍폜
	SetKeyInputStringColor2(DX_KEYINPSTRCOLOR_NORMAL_STR, white);//�L�[���͒��f�[�^�̕`�掞�̕����F��ύX
	SetKeyInputStringColor2(DX_KEYINPSTRCOLOR_NORMAL_CURSOR, white);//�L�[���͒��f�[�^�̕`�掞�̃J�[�\���̐F��ύX

	*activezokusei = -1; *activemonster = -1;//�����C�����X�^�[�̃A�N�e�B�u����U���Z�b�g�i�\�������Ɏg���ϐ��j
	return 0;
}
//�A�N�e�B�u�ȍ��ڂ̓��͊m��@����с@���ځC����C���␳���̃A�N�e�B�u��Ԃ̃��Z�b�g
int activereset_C(int* activezokusei, int InputHandle, char columntitlebuff[][MONSTER_COLUMNTITLEFIELDMAX + 1]) {
	for (int i = 0; i < MONSTER_COLUMNMAX; i++) {
		if (InputHandle != NULL && *activezokusei == i) {
			GetKeyInputString(columntitlebuff[i], InputHandle);//�Y���J�����̕��������
		}
	}
	DeleteKeyInput(InputHandle);//�L�[���̓f�[�^�̍폜
	*activezokusei = -1;//�����C�����X�^�[�̃A�N�e�B�u����U���Z�b�g�i�\�������Ɏg���ϐ��j
	return 0;
}

int tablesyokika(int x, int y, struct MonsterTable* monstertable_p, int kosuu) {

	for (int i = 0; i < kosuu; i++) {
		//�����ʒu�̎w��
		(monstertable_p + i)->yousono[0] = x + 1;
		(monstertable_p + i)->yousono[2] = x + 1 + 50;
		(monstertable_p + i)->yousono[1] = y + 1 + 88 * i;
		(monstertable_p + i)->yousono[3] = y + 1 + 88 * i + 88;
		(monstertable_p + i)->gazou[0] = (monstertable_p + i)->yousono[2];
		(monstertable_p + i)->gazou[2] = (monstertable_p + i)->yousono[2] + 88;
		(monstertable_p + i)->gazou[1] = (monstertable_p + i)->yousono[1];
		(monstertable_p + i)->gazou[3] = (monstertable_p + i)->yousono[1] + 88;
		(monstertable_p + i)->ID[0] = (monstertable_p + i)->gazou[2];
		(monstertable_p + i)->ID[2] = (monstertable_p + i)->gazou[2] + 300;
		(monstertable_p + i)->ID[1] = (monstertable_p + i)->gazou[1];
		(monstertable_p + i)->ID[3] = (monstertable_p + i)->gazou[1] + 22;
		(monstertable_p + i)->name[0] = (monstertable_p + i)->gazou[2];
		(monstertable_p + i)->name[2] = (monstertable_p + i)->gazou[2] + 300;
		(monstertable_p + i)->name[1] = (monstertable_p + i)->ID[3];
		(monstertable_p + i)->name[3] = (monstertable_p + i)->ID[3] + 22;
		(monstertable_p + i)->kougeki[0] = (monstertable_p + i)->gazou[2];
		(monstertable_p + i)->kougeki[2] = (monstertable_p + i)->gazou[2] + 50;
		(monstertable_p + i)->kougeki[1] = (monstertable_p + i)->name[3];
		(monstertable_p + i)->kougeki[3] = (monstertable_p + i)->name[3] + 22;
		(monstertable_p + i)->syuuki[0] = (monstertable_p + i)->kougeki[2];
		(monstertable_p + i)->syuuki[2] = (monstertable_p + i)->kougeki[2] + 50;
		(monstertable_p + i)->syuuki[1] = (monstertable_p + i)->name[3];
		(monstertable_p + i)->syuuki[3] = (monstertable_p + i)->name[3] + 22;
		(monstertable_p + i)->maryokuspeed[0] = (monstertable_p + i)->syuuki[2];
		(monstertable_p + i)->maryokuspeed[2] = (monstertable_p + i)->syuuki[2] + 50;
		(monstertable_p + i)->maryokuspeed[1] = (monstertable_p + i)->name[3];
		(monstertable_p + i)->maryokuspeed[3] = (monstertable_p + i)->name[3] + 22;
		(monstertable_p + i)->frame[0] = (monstertable_p + i)->maryokuspeed[2];
		(monstertable_p + i)->frame[2] = (monstertable_p + i)->maryokuspeed[2] + 50;
		(monstertable_p + i)->frame[1] = (monstertable_p + i)->name[3];
		(monstertable_p + i)->frame[3] = (monstertable_p + i)->name[3] + 22;
		(monstertable_p + i)->mahouID[0] = (monstertable_p + i)->frame[2];
		(monstertable_p + i)->mahouID[2] = (monstertable_p + i)->frame[2] + 50;
		(monstertable_p + i)->mahouID[1] = (monstertable_p + i)->name[3];
		(monstertable_p + i)->mahouID[3] = (monstertable_p + i)->name[3] + 22;
		(monstertable_p + i)->mahousuuchi[0] = (monstertable_p + i)->mahouID[2];
		(monstertable_p + i)->mahousuuchi[2] = (monstertable_p + i)->mahouID[2] + 50;
		(monstertable_p + i)->mahousuuchi[1] = (monstertable_p + i)->name[3];
		(monstertable_p + i)->mahousuuchi[3] = (monstertable_p + i)->name[3] + 22;
		(monstertable_p + i)->keikenchi[0] = (monstertable_p + i)->gazou[2];
		(monstertable_p + i)->keikenchi[2] = (monstertable_p + i)->gazou[2] + 250;
		(monstertable_p + i)->keikenchi[1] = (monstertable_p + i)->mahousuuchi[3];
		(monstertable_p + i)->keikenchi[3] = (monstertable_p + i)->mahousuuchi[3] + 22;
		(monstertable_p + i)->coin[0] = (monstertable_p + i)->keikenchi[2];
		(monstertable_p + i)->coin[2] = (monstertable_p + i)->keikenchi[2] + 50;
		(monstertable_p + i)->coin[1] = (monstertable_p + i)->mahousuuchi[3];
		(monstertable_p + i)->coin[3] = (monstertable_p + i)->mahousuuchi[3] + 22;
		(monstertable_p + i)->tablewaku[0] = x;
		(monstertable_p + i)->tablewaku[2] = (monstertable_p + i)->coin[2] + 1;
		(monstertable_p + i)->tablewaku[1] = y + 88 * i;
		(monstertable_p + i)->tablewaku[3] = y + 2 + 88 * i + 88;
	}

	return 0;

}

int monstertableallsyokika(int x, int y, struct MonsterTableAll* monstertableall_p, int kosuu) {

	for (int i = 0; i < kosuu; i++) {
		(monstertableall_p + i)->tablewaku[0] = x;
		if (i == 0) (monstertableall_p + i)->tablewaku[1] = y;
		else (monstertableall_p + i)->tablewaku[1] = (monstertableall_p + i - 1)->tablewaku[3];

		//�����ʒu�̎w��
		(monstertableall_p + i)->yousono[0] = (monstertableall_p + i)->tablewaku[0] + 1;//
		(monstertableall_p + i)->yousono[2] = (monstertableall_p + i)->tablewaku[0] + 1 + 37;//
		(monstertableall_p + i)->yousono[1] = (monstertableall_p + i)->tablewaku[1] + 1;// +88 * i;
		(monstertableall_p + i)->yousono[3] = (monstertableall_p + i)->tablewaku[1] + 1 + 88;// + 88 * i
		(monstertableall_p + i)->gazou[0] = (monstertableall_p + i)->yousono[2];
		(monstertableall_p + i)->gazou[2] = (monstertableall_p + i)->yousono[2] + 88;
		(monstertableall_p + i)->gazou[1] = (monstertableall_p + i)->yousono[1];
		(monstertableall_p + i)->gazou[3] = (monstertableall_p + i)->yousono[3];
		(monstertableall_p + i)->columntitle[0][0] = (monstertableall_p + i)->gazou[2];
		(monstertableall_p + i)->columntitle[0][2] = (monstertableall_p + i)->gazou[2] + 68;
		(monstertableall_p + i)->columntitle[0][1] = (monstertableall_p + i)->gazou[1];
		(monstertableall_p + i)->columntitle[0][3] = (monstertableall_p + i)->gazou[1] + 22;
		(monstertableall_p + i)->column[0][0] = (monstertableall_p + i)->columntitle[0][2];
		(monstertableall_p + i)->column[0][2] = (monstertableall_p + i)->columntitle[0][2] + 286;
		(monstertableall_p + i)->column[0][1] = (monstertableall_p + i)->columntitle[0][1];
		(monstertableall_p + i)->column[0][3] = (monstertableall_p + i)->columntitle[0][3];
		(monstertableall_p + i)->nametitle[0] = (monstertableall_p + i)->gazou[2];
		(monstertableall_p + i)->nametitle[2] = (monstertableall_p + i)->gazou[2] + 68;
		(monstertableall_p + i)->nametitle[1] = (monstertableall_p + i)->columntitle[0][3];
		(monstertableall_p + i)->nametitle[3] = (monstertableall_p + i)->columntitle[0][3] + 22;
		(monstertableall_p + i)->name[0] = (monstertableall_p + i)->nametitle[2];
		(monstertableall_p + i)->name[2] = (monstertableall_p + i)->nametitle[2] + 286;
		(monstertableall_p + i)->name[1] = (monstertableall_p + i)->nametitle[1];
		(monstertableall_p + i)->name[3] = (monstertableall_p + i)->nametitle[3];


		(monstertableall_p + i)->columntitle[1][0] = (monstertableall_p + i)->gazou[2];
		(monstertableall_p + i)->columntitle[1][2] = (monstertableall_p + i)->gazou[2] + 68;
		(monstertableall_p + i)->columntitle[1][1] = (monstertableall_p + i)->name[3];
		(monstertableall_p + i)->columntitle[1][3] = (monstertableall_p + i)->name[3] + 22;

		(monstertableall_p + i)->column[1][0] = (monstertableall_p + i)->columntitle[1][2];
		(monstertableall_p + i)->column[1][2] = (monstertableall_p + i)->columntitle[1][2] + 50;
		(monstertableall_p + i)->column[1][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[1][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[2][0] = (monstertableall_p + i)->column[1][2];
		(monstertableall_p + i)->columntitle[2][2] = (monstertableall_p + i)->column[1][2] + 68;
		(monstertableall_p + i)->columntitle[2][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->columntitle[2][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->column[2][0] = (monstertableall_p + i)->columntitle[2][2];
		(monstertableall_p + i)->column[2][2] = (monstertableall_p + i)->columntitle[2][2] + 50;
		(monstertableall_p + i)->column[2][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[2][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[3][0] = (monstertableall_p + i)->column[2][2];
		(monstertableall_p + i)->columntitle[3][2] = (monstertableall_p + i)->column[2][2] + 68;
		(monstertableall_p + i)->columntitle[3][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->columntitle[3][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->column[3][0] = (monstertableall_p + i)->columntitle[3][2];
		(monstertableall_p + i)->column[3][2] = (monstertableall_p + i)->columntitle[3][2] + 50;
		(monstertableall_p + i)->column[3][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[3][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[4][0] = (monstertableall_p + i)->column[3][2];
		(monstertableall_p + i)->columntitle[4][2] = (monstertableall_p + i)->column[3][2] + 68;
		(monstertableall_p + i)->columntitle[4][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->columntitle[4][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->column[4][0] = (monstertableall_p + i)->columntitle[4][2];
		(monstertableall_p + i)->column[4][2] = (monstertableall_p + i)->columntitle[4][2] + 50;
		(monstertableall_p + i)->column[4][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[4][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[5][0] = (monstertableall_p + i)->column[4][2];
		(monstertableall_p + i)->columntitle[5][2] = (monstertableall_p + i)->column[4][2] + 68;
		(monstertableall_p + i)->columntitle[5][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->columntitle[5][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->column[5][0] = (monstertableall_p + i)->columntitle[5][2];
		(monstertableall_p + i)->column[5][2] = (monstertableall_p + i)->columntitle[5][2] + 50;
		(monstertableall_p + i)->column[5][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[5][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[6][0] = (monstertableall_p + i)->column[5][2];
		(monstertableall_p + i)->columntitle[6][2] = (monstertableall_p + i)->column[5][2] + 68;
		(monstertableall_p + i)->columntitle[6][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->columntitle[6][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->column[6][0] = (monstertableall_p + i)->columntitle[6][2];
		(monstertableall_p + i)->column[6][2] = (monstertableall_p + i)->columntitle[6][2] + 50;
		(monstertableall_p + i)->column[6][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[6][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[7][0] = (monstertableall_p + i)->column[6][2];
		(monstertableall_p + i)->columntitle[7][2] = (monstertableall_p + i)->column[6][2] + 68;
		(monstertableall_p + i)->columntitle[7][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->columntitle[7][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->column[7][0] = (monstertableall_p + i)->columntitle[7][2];
		(monstertableall_p + i)->column[7][2] = (monstertableall_p + i)->columntitle[7][2] + 50;
		(monstertableall_p + i)->column[7][1] = (monstertableall_p + i)->columntitle[1][1];
		(monstertableall_p + i)->column[7][3] = (monstertableall_p + i)->columntitle[1][3];

		(monstertableall_p + i)->columntitle[8][0] = (monstertableall_p + i)->gazou[2];
		(monstertableall_p + i)->columntitle[8][2] = (monstertableall_p + i)->gazou[2] + 68;
		(monstertableall_p + i)->columntitle[8][1] = (monstertableall_p + i)->column[1][3];
		(monstertableall_p + i)->columntitle[8][3] = (monstertableall_p + i)->column[1][3] + 22;

		(monstertableall_p + i)->column[8][0] = (monstertableall_p + i)->columntitle[8][2];
		(monstertableall_p + i)->column[8][2] = (monstertableall_p + i)->columntitle[8][2] + 50;
		(monstertableall_p + i)->column[8][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[8][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->columntitle[9][0] = (monstertableall_p + i)->column[8][2];
		(monstertableall_p + i)->columntitle[9][2] = (monstertableall_p + i)->column[8][2] + 68;
		(monstertableall_p + i)->columntitle[9][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->columntitle[9][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->column[9][0] = (monstertableall_p + i)->columntitle[9][2];
		(monstertableall_p + i)->column[9][2] = (monstertableall_p + i)->columntitle[9][2] + 50;
		(monstertableall_p + i)->column[9][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[9][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->columntitle[10][0] = (monstertableall_p + i)->column[9][2];
		(monstertableall_p + i)->columntitle[10][2] = (monstertableall_p + i)->column[9][2] + 68;
		(monstertableall_p + i)->columntitle[10][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->columntitle[10][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->column[10][0] = (monstertableall_p + i)->columntitle[10][2];
		(monstertableall_p + i)->column[10][2] = (monstertableall_p + i)->columntitle[10][2] + 50;
		(monstertableall_p + i)->column[10][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[10][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->columntitle[11][0] = (monstertableall_p + i)->column[10][2];
		(monstertableall_p + i)->columntitle[11][2] = (monstertableall_p + i)->column[10][2] + 68;
		(monstertableall_p + i)->columntitle[11][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->columntitle[11][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->column[11][0] = (monstertableall_p + i)->columntitle[11][2];
		(monstertableall_p + i)->column[11][2] = (monstertableall_p + i)->columntitle[11][2] + 50;
		(monstertableall_p + i)->column[11][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[11][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->columntitle[12][0] = (monstertableall_p + i)->column[11][2];
		(monstertableall_p + i)->columntitle[12][2] = (monstertableall_p + i)->column[11][2] + 68;
		(monstertableall_p + i)->columntitle[12][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->columntitle[12][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->column[12][0] = (monstertableall_p + i)->columntitle[12][2];
		(monstertableall_p + i)->column[12][2] = (monstertableall_p + i)->columntitle[12][2] + 50;
		(monstertableall_p + i)->column[12][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[12][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->columntitle[13][0] = (monstertableall_p + i)->column[12][2];
		(monstertableall_p + i)->columntitle[13][2] = (monstertableall_p + i)->column[12][2] + 68;
		(monstertableall_p + i)->columntitle[13][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->columntitle[13][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->column[13][0] = (monstertableall_p + i)->columntitle[13][2];
		(monstertableall_p + i)->column[13][2] = (monstertableall_p + i)->columntitle[13][2] + 50;
		(monstertableall_p + i)->column[13][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[13][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->columntitle[14][0] = (monstertableall_p + i)->column[13][2];
		(monstertableall_p + i)->columntitle[14][2] = (monstertableall_p + i)->column[13][2] + 68;
		(monstertableall_p + i)->columntitle[14][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->columntitle[14][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->column[14][0] = (monstertableall_p + i)->columntitle[14][2];
		(monstertableall_p + i)->column[14][2] = (monstertableall_p + i)->columntitle[14][2] + 50;
		(monstertableall_p + i)->column[14][1] = (monstertableall_p + i)->columntitle[8][1];
		(monstertableall_p + i)->column[14][3] = (monstertableall_p + i)->columntitle[8][3];

		(monstertableall_p + i)->tablewaku[2] = (monstertableall_p + i)->column[14][2] + 1;
		(monstertableall_p + i)->tablewaku[3] = (monstertableall_p + i)->column[14][3] + 1;
	}

	return 0;

}


int EditMonster(char *FilePath_Monster_h, struct Monster *Monster_p, int *Monster_Kosuu_p, int *MaxMonsterID_p, char(*ColumnTitle_h)[MONSTER_COLUMNTITLEFIELDMAX + 1], int* Column_Kosuu_p, char(*MonsterImgPath_h)[MAX_PATH], int BackImg

) {//
	/////���ϐ��̐錾�Ə������̎n�܂聫////////////���ϐ��̐錾�Ə������̎n�܂聫////////////���ϐ��̐錾�Ə������̎n�܂聫////////////���ϐ��̐錾�Ə������̎n�܂聫//////
	if (*FilePath_Monster_h == '\0') return -1;//�t�@�C�������Ȃ���΂����ɔ�����

	//�������ScreenFlip����C�e���[�h�̂O�t���[����ScreenFlip�܂ł̑҂����ԁi�t�@�C���̃��[�h�Ȃǁj�ɕ\��������́�
	//�i���ꂪ�Ȃ��Ɗe���[�h���甲���Ă����Ƃ��ɁC�Ȃ���ScreenFlip����Ă��ēr���������o����Ă��܂��j
	const static char Msg[] = "���҂���������";
	const static int MsgWidth = GetDrawStringWidth(Msg, strlen(Msg));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);
	//SetCurrentDirectory(AppDir);
	//static int ImgHandle = LoadGraph(".//025.jpg");//���[�h���؂�ւ��Ƃ��i�t�@�C�����J�����Ƃ��j�Ɉ�u�\�������@�摜�͉��̐ݒ�Ȃ̂ŕς����ق����ǂ�
	//DrawGraph(0, 0, ImgHandle, TRUE);
	DrawString((WindowWidth - MsgWidth) / 2, (WindowHeight - SystemFontSize) / 2, Msg, white);
	ScreenFlip();

	//���e���[�h�̂O�t���[����ScreenFlip�ŕ\��������́�
	DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);
	/////////////////

	//���c�[���o�[
	static struct AREACONTROL Toolbar = { 0 };
	for (int i = 0; i < 4; i++) Toolbar.Padding[i] = 1;
	Toolbar.Width = WindowWidth;
	Toolbar.Height = 28;
	Toolbar.BackColor = GetColor(102, 153, 204);//204, 204, 204

	//���c�[���{�^���t�H�[��
	static struct BUTTONFORM ToolBForm = { 0 };
	for (int i = 0; i < 4; i++) ToolBForm.Margin[i] = 1;
	ToolBForm.CursorColor = GetColor(255, 255, 204);
	//���c�[���{�^��B
	SetCurrentDirectory(AppDir);
	const int ToolBKosuu = 4;//�{�^���z��̌��@���@�z��v�f���iMax�͂Ȃ��j
	static struct BUTTONCONTROL ToolB[ToolBKosuu] = { 0 };

	strcpy(ToolB[0].String, "���ҏW���[�h�ɖ߂�");
	if (ToolB[0].WaitingImg == -1) {
		ToolB[0].WaitingImg = LoadGraph(".\\System\\Fixed\\back24.png");
		ToolB[0].CursorImg = LoadGraph(".\\System\\Fixed\\back24b.png");
		ToolB[0].PushedImg = ToolB[0].CursorImg;
	}
	strcpy(ToolB[1].String, "�����X�^�[�̏㏑���ۑ�");
	if (ToolB[1].WaitingImg == -1) {
		ToolB[1].WaitingImg = LoadGraph(".\\System\\Fixed\\save24.png");
		ToolB[1].CursorImg = LoadGraph(".\\System\\Fixed\\save24b.png");
		ToolB[1].PushedImg = ToolB[1].CursorImg;
	}
	strcpy(ToolB[2].String, "���ڂ̐ݒ�");
	if (ToolB[2].WaitingImg == -1) {
		ToolB[2].WaitingImg = LoadGraph(".\\System\\Fixed\\setclumn24.png");
		ToolB[2].CursorImg = LoadGraph(".\\System\\Fixed\\setclumn24b.png");
		ToolB[2].PushedImg = ToolB[2].CursorImg;
	}
	strcpy(ToolB[3].String, "�V���������X�^�[�̒ǉ�");
	if (ToolB[3].WaitingImg == -1) {
		ToolB[3].WaitingImg = LoadGraph(".\\System\\Fixed\\addmonster24.png");
		ToolB[3].CursorImg = LoadGraph(".\\System\\Fixed\\addmonster24b.png");
		ToolB[3].PushedImg = ToolB[3].CursorImg;
	}


	for (int BtnN = 0; BtnN < ToolBKosuu; BtnN++) {
		ToolB[BtnN].ParentArea_p = &Toolbar;
		if (BtnN > 0) ToolB[BtnN].Location[0] = -111111;
		ToolB[BtnN].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolB[BtnN].ButtonForm_p = &ToolBForm;
	}

	//////////////////
	//���f�B�X�v���C�G���A
	static struct AREACONTROL DisplayArea = { 0 };
	DisplayArea.Location[1] = 28;
	for (int i = 0; i < 4; i++) DisplayArea.Padding[i] = 23;//�����������X�^�[�e�[�u���̕���953������E�̎����̂�����1000-23-953��24�B
	DisplayArea.Width = WindowWidth;
	DisplayArea.Height = WindowHeight - 24 - 24;//WindowHeight = 24 + 750 + 24
	DisplayArea.BackImg = BackImg;

	//���X�e�[�^�X�o�[
	static struct AREACONTROL Statusbar = { 0 };
	Statusbar.Width = WindowWidth;
	Statusbar.Height = 24;//������v���̂���Location[1]����ɏ�����
	Statusbar.Location[1] = WindowHeight - Statusbar.Height;
	for (int i = 0; i < 4; i++) Statusbar.Padding[i] = 5;
	Statusbar.BackColor = GetColor(240, 240, 240);

	int toolline_color = GetColor(153, 153, 153);
	int toolcursol_color = GetColor(255, 255, 204);

	////�V�X�e����ԂɊւ���ϐ��̐錾�Ə�����////
	int activezokusei = -1;//�A�N�e�B�u�ȑ����i-1�F�A�N�e�B�u�Ȃ��j
	int activemonster = -1;//�A�N�e�B�u�ȃ����X�^�[�i-1�F�A�N�e�B�u�Ȃ��j

	int windowflag = 0;
	int Rot = 0;// �}�E�X�z�C�[���̉�]�ʂ̍��v�l
				//int haikeigazouH = LoadGraph("�w�i�摜/658ea9657de693c4c60e35dc40af5b18.png"); //�ҏW�p�摜�̓ǂݍ���1000*750
	int kugirisen = 0;//����\�����J�n������؂���i�K�����[�v�O�Ő錾�j

					  /////���͂̏����Ɋւ���ϐ��̐錾�Ə�����////////////////////////////
	int InputHandle;//�������͎��Ɏg���L�[���̓n���h��
	//�_�~�[�œ���Ă����i�e�J�������N���b�N���ɃN���b�N�O�̃J�����̓��͂����肷��̂ŁC����̃N���b�N���ɃL�[�n���h���Ȃ��ƃG���[�ƂȂ邽�߁j

	//�J�����̔z�񐔂̕������iMONSTER_FIELDMAX�j��8�����C����Ɋe�J�������Ƃɓ��͕������ɐ���������Ă���̂Œ���
	InputHandle = MakeKeyInput(8, TRUE, TRUE, TRUE);//�L�[���̓n���h���̐ݒ�  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�


	int handlesettei[MONSTER_COLUMNMAX][4];//�L�[���̓n���h���̐ݒ�l������z��  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�
	for (int i = 0; i < MONSTER_COLUMNMAX; i++) { handlesettei[i][0] = 3; handlesettei[i][1] = FALSE; handlesettei[i][2] = TRUE, handlesettei[i][3] = TRUE; }//3�������l�p
	handlesettei[0][0] = 5; handlesettei[0][3] = FALSE;//�����X�^�[ID�p�i3�����p�̈ꕔ���������j
	handlesettei[5][0] = 4; handlesettei[5][3] = FALSE;//���@ID�p�i3�����p�̈ꕔ���������j
	int handlesettei_name[4] = { MONSTERNAME_FIELDSISE, TRUE, FALSE, FALSE };//�����X�^�[���p
	int ColumnKosuubuff = 0;
	char ColumnTitle_buff[MONSTER_COLUMNMAX][MONSTER_COLUMNTITLEFIELDMAX + 1] = { 0 };//�R�����^�C�g�����ꎞ�擾����z��

					   //	TCHAR Directory_MonsterTable[MAX_PATH] = { "monster" };//�����X�^�[�e�[�u��������f�B���N�g���i�����_�ŊJ���Ă����肪����f�B���N�g���j�ɂ��邪�A�Ƃ肠�������̓����X�^�[�t�H���_�𑊑΃p�X�Ŏw��


	const int tablesuuMax = 7;
	int tablesuu;
	struct MonsterTableAll monstertableall[tablesuuMax];
	int monsterwide[MONSTER_MAX] = { 0 };	int monsterhight[MONSTER_MAX] = { 0 };//�����X�^�[�̉摜�̏c���T�C�Y���擾���邽�߂̕ϐ�
	///////////////////////////////��
	char FileTitle_Monster[MAX_PATH] = { 0 };
	static char directory_Monster_buff[MAX_PATH] = { 0 };//�����s�v�@�@�O��g�p�������b�Z�[�W�v���p�e�B�̃p�X�i�O��Ɠ����Ȃ�ݒ�C�w�i�摜�C�v���p�e�B�����[�h���Ȃ��j
	char MonsterDir[MAX_PATH];

	SetCurrentDirectory(AppDir);
	char Undefined_MonsterName[100] = { "����`" };
	int Undefined_MonsterImg = LoadGraph(".\\System\\Fixed\\undefined_monster.png");
	int Undefined_MonsterImgWide;
	int Undefined_MonsterImgHeight;
	GetGraphSize(Undefined_MonsterImg, &Undefined_MonsterImgWide, &Undefined_MonsterImgHeight); //�����X�^�[�̉摜�̏c���T�C�Y���擾����Undefined_MonsterImgWide�Cmonsterhight�ɏ����o��

	if (FilePath_Monster_h[0] != '\0') {
		//�f�B���N�g���̎擾�i�t�@�C�����̑O��\\�̈ʒu��T���j
		strcpy(MonsterDir, FilePath_Monster_h);
		int mojisuu = strlen(MonsterDir);
		int count;
		for (count = 1; MonsterDir[mojisuu - count] != '\\' && count < MAX_PATH; count++);//
		MonsterDir[mojisuu - count] = '\0';


		GetTitleFromPath(FileTitle_Monster, FilePath_Monster_h);//���΃t�@�C���p�X����t�@�C�������擾�i����ł͕K�����܂����t�@�C�����ƂȂ�j

		////////�����X�^�[�e�[�u�����̌���
		tablesuu = *Monster_Kosuu_p;
		if (tablesuu > tablesuuMax) tablesuu = tablesuuMax;//�e�[�u�������ő�e�[�u�����i7�j�܂łƂ���i���Ȃ��Ƃ��̓����X�^�[�̌��ƈ�v�B�����Ă���Ƃ��͍ő�e�[�u�����B�j
		monstertableallsyokika(DisplayArea.Location[0] + DisplayArea.Padding[0], DisplayArea.Location[1] + DisplayArea.Padding[1], monstertableall, tablesuuMax);//tablesuu


		//////�����X�^�[�̉摜�n���h���Əc���T�C�Y�̎擾
		for (int i = 0; i < *Monster_Kosuu_p; i++) {//��ʓ��̃����X�^�[���������X�^�[�摜�p�X���擾
			GetGraphSize(Monster_p[i].Img, &monsterwide[i], &monsterhight[i]); //�����X�^�[�̉摜�̏c���T�C�Y���擾����monsterwide�Cmonsterhight�ɏ����o��
		}


	}
	//�^�C�g���o�[�̃e�L�X�g�̍X�V
	char Titlebar_text[MAX_PATH];
	strcpy(Titlebar_text, ApplicationTitle);//�A�v���P�[�V����������
	strcat(Titlebar_text, " - �����X�^�[�ҏW���[�h - ");//�t�@�C������A��
	strcat(Titlebar_text, FileTitle_Monster);//�t�@�C������A��
	SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������

	//////���ϐ��̐錾�Ə����l�̎擾�̏I����////////////���ϐ��̐錾�Ə����l�̎擾�̏I����////////////���ϐ��̐錾�Ə����l�̎擾�̏I����////////////���ϐ��̐錾�Ə����l�̎擾�̏I����//////
	//////////�������X�^�[�ҏW���C�����[�v�̎n�܂聫////////////////////���ҏW���C�����[�v�̎n�܂聫///////////////////���ҏW���C�����[�v�̎n�܂聫///////////////////���ҏW���C�����[�v�̎n�܂聫/////////
	for (int frameH = 0; !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !MathgpUpdateMouse() && !MathgpUpdateKey(); frameH++) {//�}�E�X
		//������������ҋ@
		SleepToFitFPS(FPS);

		if (windowflag == 0)Rot -= GetMouseWheelRotVol(); //�O�񂩂�̃}�E�X�z�C�[���̉�]�̑����ʂ����Z�iGetMouseWheelRotVol�͉��ɉ�]�����̒l�j
		//////�i�P�j��ʕ\������
		//�c�[���o�[
		ShowArea(&Toolbar, 1);
		int ClickedNo = -1;//�N���b�N���ꂽ�{�^���ԍ�
		////�@�c�[���o�[B�@////
		//���c�[���{�^��
		int ToolB_PushType = 0; int ToolB_Prev = -2; int ToolB_Next = -2;
		if (ShowButton(ToolB, ToolBKosuu, &ClickedNo, ToolB_PushType, ToolB_Prev, ToolB_Next) == 1) {// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
			//�߂�
			if (ClickedNo == 0) {
				if (windowflag == 0) return 0;//�����X�^�[�ҏW���[�h���甲����
			}
			//�����X�^�[�̕ۑ�
			else if (ClickedNo == 1) {
				activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
				//�������X�^�[�̂h�c���̕��בւ�
				char charbuff[MAX_PATH] = { 0 }; //�摜�t�@�C��

				int intbuff;
				struct Monster MinsterBuff;
				for (int i = 0; i < *Monster_Kosuu_p; i++) {
					for (int j = *Monster_Kosuu_p - 1; j > i; j--) {
						if (Monster_p[j - 1].Column[0] > Monster_p[j].Column[0] && Monster_p[j].Column[0] != 0) {

							MinsterBuff = Monster_p[j];
							Monster_p[j] = Monster_p[j - 1];
							Monster_p[j - 1] = MinsterBuff;

							strcpy(charbuff, MonsterImgPath_h[j]);//�摜�p�X�̕��בւ�
							strcpy(MonsterImgPath_h[j], MonsterImgPath_h[j - 1]);
							strcpy(MonsterImgPath_h[j - 1], charbuff);

							intbuff = monsterwide[j];
							monsterwide[j] = monsterwide[j - 1];
							monsterwide[j - 1] = intbuff;

							intbuff = monsterhight[j];
							monsterhight[j] = monsterhight[j - 1];
							monsterhight[j - 1] = intbuff;
						}
					}
				}
				////�����X�^�[�̃Z�[�u�i�t�@�C���p�X���J���Ȃ炷���ɔ����邩�牽���N����Ȃ��j
				SaveMonster(FilePath_Monster_h, Monster_p, *Monster_Kosuu_p, *MaxMonsterID_p, ColumnTitle_h, *Column_Kosuu_p, MonsterImgPath_h);	//////////
			}
			//���ڂ̐ݒ�
			else if (ClickedNo == 2) {
				//if (windowflag == 0) {
				Toolbar.Active = 0;
				for (int i = 0; i < MONSTER_COLUMNMAX; i++) strcpy(ColumnTitle_buff[i], ColumnTitle_h[i]);//OK�������܂ł͂�ColumnTitle_buff�g�p
				ColumnKosuubuff = *Column_Kosuu_p;//OK�������܂ł͂�ColumnKosuubuff�g�p
				windowflag = 1;//�ݒ�̃|�b�v�A�b�v�̕\��
				DisplayArea.Active = 0;//�܂��͂Q�@�@�@�i-�P�F��\���@�O�F�g�p�s��ԁi�{�^���̃^�C�g���𔖂��\�����Ė������j�@�P�F�ҋ@��ԁi�{�^���̕\���E�����j�@�Q�F�{�^����\�����邪�������j

			//}
			}
			//�����X�^�[�̒ǉ�
			else if (ClickedNo == 3) {
				activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
				if (*Monster_Kosuu_p < MONSTER_MAX) {//
					struct Monster MonsterClear = { 0 };
					Monster_p[*Monster_Kosuu_p] = MonsterClear;
					Monster_p[*Monster_Kosuu_p].Column[0] = *MaxMonsterID_p + 1;
					*MaxMonsterID_p += 1;

					MonsterImgPath_h[*Monster_Kosuu_p][0] = '\0';
					monsterwide[*Monster_Kosuu_p] = 0;
					monsterhight[*Monster_Kosuu_p] = 0;
					*Monster_Kosuu_p += 1;//�����X�^�[�����P���₷

					tablesuu = *Monster_Kosuu_p;//
					if (tablesuu > tablesuuMax) tablesuu = tablesuuMax;//�e�[�u����
					Rot = *Monster_Kosuu_p - tablesuu;
				}

			}
		}

		////////////////////////////////
		//���f�B�X�v���G���A
		ShowArea(&DisplayArea, 1);

		//���X�e�[�^�X�o�[
		ShowArea(&Statusbar, 1);
		//
					///
		static int StatusNumber = 0;//�p�b�h���[�h�̃X�e�[�^�X�o�[�̕\�����e��ύX�i�R���g���[���{S�j
		if (ActiveMath::Key[KEY_INPUT_S] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {//
			StatusNumber += 1;//
			if (StatusNumber == 2) StatusNumber = 0;
		}
		if (StatusNumber == 0) {
			DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "MonsterDir: %s", MonsterDir);//�����X�^�[�f�B���N�g��
		}
		else if (StatusNumber == 1) {
			DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�t�@�C���p�X: %s", FilePath_Monster_h);//�t�@�C���p�X
		}

																							  //////////���t�@�C����������Ȃ珈�����Ȃ������̏�[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��
		//���e�[�u��																					  ////�N������C�A�v���͕����Ƀt�@�C���̂ݕ����Ƃ��B�����������X�^�[�̕ҏW�ł͌��󂻂̏󋵂ɂȂ�Ȃ����C����̂��߂ɂ��̂悤�ɂ��Ă����B//////
		if (FilePath_Monster_h[0] != '\0') {
			if (Rot < 0) Rot = 0;//�}�E�X�̉�]�ʂ�0��菬�����Ȃ�Ȃ��悤��
			else if (Rot > *Monster_Kosuu_p - tablesuu) Rot = *Monster_Kosuu_p - tablesuu;//�}�E�X�̉�]�ʂ��傫���Ȃ�߂��Ȃ��悤��
			//���`��\�̈�̎w��
			SetDrawArea(0, kugirisen + 3, 1024, 1000);//�`��\�̈�����肷��@����̃X�N���[���̂���
			for (int i = 0; i < tablesuu; i++) {
				//���e�[�u���S�̘̂g
				DrawBox(monstertableall[i].column[0][2], monstertableall[i].column[0][1], monstertableall[i].tablewaku[2], monstertableall[i].name[3], gray, false);//�g�̕⊮
				DrawBox(monstertableall[i].tablewaku[0], monstertableall[i].tablewaku[1], monstertableall[i].tablewaku[2], monstertableall[i].tablewaku[3], gray, false);//�S�̘g
				DrawBox(monstertableall[i].tablewaku[0] + 1, monstertableall[i].tablewaku[1] + 1, monstertableall[i].tablewaku[2] - 1, monstertableall[i].tablewaku[3] - 1, gray, false);//�S�̘g
				//���v�f�ԍ��̕\��
				DrawBox(monstertableall[i].yousono[0], monstertableall[i].yousono[1], monstertableall[i].yousono[2], monstertableall[i].yousono[3], gray, false);//�����X�^�[�v�f�ԍ��̘g
				DrawFormatString(monstertableall[i].yousono[0] + 4, monstertableall[i].yousono[1] + 4, white, "%d", Rot + i);//�e�[�u���v�f�ԍ��̕\��
				//�������X�^�[�摜
				if (windowflag == 0) {
					if (monstertableall[i].gazou[0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertableall[i].gazou[2] && monstertableall[i].gazou[1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertableall[i].gazou[3]) {//�摜�͈͓̔��̂Ƃ�
						if (*MonsterImgPath_h[Rot + i] != '\0') ActiveMath::CursorOverString_p = MonsterImgPath_h[Rot + i];//�}�E�X�I�[�o�[�����{�^����String���Ȃ��Ă��C�|�C���^�[��MouseOverString_p�ɏ�������

						if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
							activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
							activemonster = Rot + i;//�e�[�u���̍s�ԍ����擾
							MonsterImgChange(MonsterDir, MonsterImgPath_h[activemonster], &Monster_p[activemonster].Img, &monsterwide[activemonster], &monsterhight[activemonster]);
						}
					}
				}
				//�\��
				/*�֐���������C�X�N���[���Ȃǂŗ̈悪�d�Ȃ����肵����C//���`��\�̈�̊m���//�������X�^�[�摜�@�́C�����������ɂ���
				//�����̈�̎擾
				RECT DrawAreaBuff;
				GetDrawArea(&DrawAreaBuff);
				int Range[4] = { DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom };//�����̈���擾���邽�߂̔z��
				//�������o���\�̈��ݒ�@�@���̕`��\�̈�� ���� �����X�^�[�摜�̗̈��
				Overlap(Range, monstertableall[i].gazou);//
				//���`��\�̈�̊m��
				SetDrawArea(Range[0], Range[1], Range[2], Range[3]);
				//�������X�^�[�摜
				int centerX = monstertableall[i].gazou[0] + 44; int centerY = monstertableall[i].gazou[1] + 44;////�����X�^�[�摜�̘g�̒��S
				int Rate = 3;//������2/3�̑傫���ŕ\���i���S���獶�E��1/3�̈ʒu�j
				DrawExtendGraph(centerX - monsterwide[Rot + i] / Rate, centerY - monsterhight[Rot + i] / Rate, centerX + monsterwide[Rot + i] / Rate, centerY + monsterhight[Rot + i] / Rate, MonsterImg[Rot + i], true);  //�����X�^�[�摜��`�悷��
				//���`��\�̈�����ɖ߂�
				SetDrawArea(DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom);
				*/

				//���`��\�̈�̊m��
				SetDrawArea(monstertableall[i].gazou[0], monstertableall[i].gazou[1], monstertableall[i].gazou[2], monstertableall[i].gazou[3]);
				//�������X�^�[�摜
				int centerX = monstertableall[i].gazou[0] + 44; int centerY = monstertableall[i].gazou[1] + 44;////�����X�^�[�摜�̘g�̒��S
				int Rate = 3;//������2/3�̑傫���ŕ\���i���S���獶�E��1/3�̈ʒu�j
				if(Monster_p[Rot + i].Img != -1) DrawExtendGraph(centerX - monsterwide[Rot + i] / Rate, centerY - monsterhight[Rot + i] / Rate, centerX + monsterwide[Rot + i] / Rate, centerY + monsterhight[Rot + i] / Rate, Monster_p[Rot + i].Img, true);  //�����X�^�[�摜��`�悷��
				else DrawExtendGraph(centerX - Undefined_MonsterImgWide / Rate, centerY - Undefined_MonsterImgHeight / Rate, centerX + Undefined_MonsterImgWide / Rate, centerY + Undefined_MonsterImgHeight / Rate, Undefined_MonsterImg, true);  //�����X�^�[�摜��`�悷��

				SetDrawArea(DisplayArea.Nest[0], DisplayArea.Nest[1], DisplayArea.Nest[2], DisplayArea.Nest[3]);


				DrawBox(monstertableall[i].gazou[0], monstertableall[i].gazou[1], monstertableall[i].gazou[2], monstertableall[i].gazou[3], gray, false);//�����X�^�[�摜�̘g
				//���J�����O�i�����X�^�[�h�c�j�l�̕ύX�͕s��
				//�\��
				int titlecolor2 = GetColor(0, 51, 102);
				int titlecolor = GetColor(0, 102, 153);
				DrawBox(monstertableall[i].columntitle[0][0], monstertableall[i].columntitle[0][1], monstertableall[i].column[0][2], monstertableall[i].column[0][3], gray, false);////�J�����O�i�h�c)�^�C�g���ƃJ�����O�i�h�c�j�̘A���g
				DrawBox(monstertableall[i].columntitle[0][0] + 1, monstertableall[i].columntitle[0][1] + 1, monstertableall[i].columntitle[0][2] - 1, monstertableall[i].columntitle[0][3] - 1, titlecolor2, true);//�J�����O�i�h�c�j�^�C�g���̔w�i
				DrawString(monstertableall[i].columntitle[0][0] + 4, monstertableall[i].columntitle[0][1] + 4, ColumnTitle_h[0], white);//�J�����O�i�h�c�j�^�C�g���̕\��
				if (activezokusei == 0 && activemonster == Rot + i) {//�J�����O�i�h�c)�̓���activemonster - Rot
					DrawKeyInputString(monstertableall[i].column[0][0] + 4, monstertableall[i].column[0][1] + 4, InputHandle);//�L�[���͒��f�[�^�̕`��
					if (CheckKeyInput(InputHandle) != 0) {//���͂��I�����Ă���Ƃ�
						activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�G���^�[�Ŋm�莞�j
					}
				}
				else  DrawFormatString(monstertableall[i].column[0][0] + 4, monstertableall[i].column[0][1] + 4, white, "%d", Monster_p[Rot + i].Column[0]);//�J�����O�i�h�c�j�̕\��
				//�������X�^�[��
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1 && windowflag == 0) {
					if (monstertableall[i].name[0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertableall[i].name[2] && monstertableall[i].name[1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertableall[i].name[3]) {//���Ԃ̃����X�^�[���͈͓̔��̂Ƃ�
						activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
						activezokusei = -20;//�����X�^�[�����A�N�e�B�u�ɂ���i�\�������Ɏg���ϐ��j
						activemonster = Rot + i;//�e�[�u���̍s�ԍ����擾
												///////�V�����n���h���̍쐬
						SetKeyInputCursorBrinkTime(643);// �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
						SetKeyInputCursorBrinkFlag(true);// �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
						InputHandle = MakeKeyInput(handlesettei_name[0], handlesettei_name[1], handlesettei_name[2], handlesettei_name[3]);//�L�[���̓n���h���̐ݒ�  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�
						SetActiveKeyInput(InputHandle);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
						SetKeyInputString(Monster_p[activemonster].Name, InputHandle);//�L�[���̓f�[�^�Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
					}
				}
				//�\��
				DrawBox(monstertableall[i].nametitle[0], monstertableall[i].nametitle[1], monstertableall[i].name[2], monstertableall[i].name[3], gray, false);//�����X�^�[���^�C�g���ƃ����X�^�[���̘A���g
				DrawBox(monstertableall[i].nametitle[0] + 1, monstertableall[i].nametitle[1] + 1, monstertableall[i].nametitle[2] - 1, monstertableall[i].nametitle[3] - 1, titlecolor2, true);//�����X�^�[���^�C�g���̔w�i
				DrawString(monstertableall[i].nametitle[0] + 4, monstertableall[i].nametitle[1] + 4, "���O", white);//�����X�^�[���^�C�g���̕\��
				if (activezokusei == -20 && activemonster == Rot + i) {//0�F�����X�^�[���̓���activemonster - Rot
					DrawKeyInputString(monstertableall[i].name[0] + 4, monstertableall[i].name[1] + 4, InputHandle);//�L�[���͒��f�[�^�̕`��
					if (CheckKeyInput(InputHandle) != 0) {
						activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�G���^�[�Ŋm�莞�j
					}
				}
				else {
					if (Monster_p[Rot + i].Name[0] != '\0') DrawFormatString(monstertableall[i].name[0] + 4, monstertableall[i].name[1] + 4, white, "%s", Monster_p[Rot + i].Name);//�����X�^�[���̕\��
					else DrawFormatString(monstertableall[i].name[0] + 4, monstertableall[i].name[1] + 4, white, "%s", Undefined_MonsterName);//�����X�^�[���̕\��
				}
				//���J�����P�`15��
				for (int k = 1; k < 15; k++) {
					////////�J�������Ԗځi�P�`15)�̃{�b�N�X�����N���b�N�����Ƃ��̏���
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1 && *Column_Kosuu_p > k && windowflag == 0) {
						if (monstertableall[i].column[k][0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertableall[i].column[k][2] && monstertableall[i].column[k][1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertableall[i].column[k][3]) {//���Ԃ̃J�����i���Ԗځj�͈͓̔��̂Ƃ�
							activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
							activezokusei = k;//�J�����i���Ԗځj���A�N�e�B�u�ɂ���i�\�������Ɏg���ϐ��j
							activemonster = Rot + i;//�e�[�u���̍s�ԍ����擾
													///////�V�����n���h���̍쐬
							SetKeyInputCursorBrinkTime(643);// �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
							SetKeyInputCursorBrinkFlag(true);// �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
							InputHandle = MakeKeyInput(handlesettei[k][0], handlesettei[k][1], handlesettei[k][2], handlesettei[k][3]);//�L�[���̓n���h���̐ݒ�  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�
							SetActiveKeyInput(InputHandle);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
							SetKeyInputNumber(Monster_p[activemonster].Column[k], InputHandle);//�L�[���̓f�[�^�Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
						}
					}
					//�\��
					DrawBox(monstertableall[i].columntitle[k][0], monstertableall[i].columntitle[k][1], monstertableall[i].column[k][2], monstertableall[i].column[k][3], gray, false);//�J�����i���Ԗځj�^�C�g���ƃJ�����i���Ԗځj�̘A���g
					if (*Column_Kosuu_p > k) {
						DrawBox(monstertableall[i].columntitle[k][0] + 1, monstertableall[i].columntitle[k][1] + 1, monstertableall[i].columntitle[k][2] - 1, monstertableall[i].columntitle[k][3] - 1, titlecolor, true);//�J�����i���Ԗځj�^�C�g���̔w�i
						DrawFormatString(monstertableall[i].columntitle[k][0] + 4, monstertableall[i].columntitle[k][1] + 4, white, "%s", ColumnTitle_h[k]);//�J�����i���Ԗځj�^�C�g���̕\��
						if (activezokusei == k && activemonster == Rot + i) {//�J�����i���Ԗځj�̓���activemonster - Rot
							DrawKeyInputString(monstertableall[i].column[k][0] + 4, monstertableall[i].column[k][1] + 4, InputHandle);//�L�[���͒��f�[�^�̕`��
							if (CheckKeyInput(InputHandle) != 0) {
								activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�G���^�[�Ŋm�莞�j
							}
						}
						else DrawFormatString(monstertableall[i].column[k][0] + 4, monstertableall[i].column[k][1] + 4, white, "%d", Monster_p[Rot + i].Column[k]);//�J�����i���Ԗځj�̕\��
					}
				}
				//////////////////////////////
				//int button1[4]; button1[0] = monstertableall[i].columntitle[4][0] + 3; button1[1] = monstertableall[i].column[0][1] + 12;  button1[2] = monstertableall[i].column[4][2] - 1;  button1[3] = monstertableall[i].name[3] - 12;


				//�������X�^�[�e�[�u���̃c�[���o�[�G���A
				static struct AREACONTROL S_Toolbar = { 0 };
				S_Toolbar.ParentArea_p = &DisplayArea;
				S_Toolbar.Location[0] = monstertableall[i].columntitle[4][0] - DisplayArea.Nest[0];//������ - DisplayArea.Nest[0]�̓����X�^�[�e�[�u�����f�B�X�v���C�G���A�ɑ�������s�v
				S_Toolbar.Location[1] = monstertableall[i].column[0][1] - DisplayArea.Nest[1];//������ - DisplayArea.Nest[1]�̓����X�^�[�e�[�u�����f�B�X�v���C�G���A�ɑ�������s�v
				for (int i = 0; i < 4; i++) S_Toolbar.Margin[i] = 10;
				for (int i = 0; i < 4; i++) S_Toolbar.Padding[i] = 1;
				S_Toolbar.Width = 975 - 503 - 22;//953
				S_Toolbar.Height = 28;//�P�s��22
				S_Toolbar.BackTransparency = 80;
				S_Toolbar.BackColor = GetColor(128, 128, 128);//204, 204, 204
				//�������X�^�[�e�[�u���̃c�[���{�^���t�H�[��
				static struct BUTTONFORM S_ToolForm = { 0 };
				for (int i = 0; i < 4; i++) S_ToolForm.Margin[i] = 1;
				S_ToolForm.CursorColor = GetColor(255, 255, 204);

				//�������X�^�[�e�[�u���̃c�[���{�^��
				SetCurrentDirectory(AppDir);
				const int S_ToolKosuu = 3;//�{�^���z��̌��@���@�z��v�f���iMax�͂Ȃ��j
				static struct BUTTONCONTROL S_Tool[S_ToolKosuu] = { 0 };

				strcpy(S_Tool[0].String, "�V���������X�^�[�̑}��");
				if (S_Tool[0].WaitingImg == -1) {
					S_Tool[0].WaitingImg = LoadGraph(".\\System\\Fixed\\addmonster24.png");
					S_Tool[0].CursorImg = LoadGraph(".\\System\\Fixed\\addmonster24b.png");
					S_Tool[0].PushedImg = S_Tool[0].CursorImg;
				}
				strcpy(S_Tool[1].String, "�N���A�[");
				if (S_Tool[1].WaitingImg == -1) {
					S_Tool[1].WaitingImg = LoadGraph(".\\System\\Fixed\\clear24.png");
					S_Tool[1].CursorImg = LoadGraph(".\\System\\Fixed\\clear24b.png");
					S_Tool[1].PushedImg = S_Tool[1].CursorImg;
				}
				strcpy(S_Tool[2].String, "�폜");
				if (S_Tool[2].WaitingImg == -1) {
					S_Tool[2].WaitingImg = LoadGraph(".\\System\\Fixed\\delete24.png");
					S_Tool[2].CursorImg = LoadGraph(".\\System\\Fixed\\delete24b.png");
					S_Tool[2].PushedImg = S_Tool[2].CursorImg;
				}

				for (int b = 0; b < S_ToolKosuu; b++) {
					S_Tool[b].ParentArea_p = &S_Toolbar;
					if (b > 0) S_Tool[b].Location[0] = -111111;
					S_Tool[b].Padding[0] = 6; S_Tool[b].Padding[1] = 3; S_Tool[b].Padding[2] = 6; S_Tool[b].Padding[3] = 3;//
					S_Tool[b].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
					S_Tool[b].ButtonForm_p = &S_ToolForm;
				}

				ShowArea(&S_Toolbar, 1);
				int S_Tool_PushType = 0; int S_Tool_Prev = -2; int S_Tool_Next = -2;// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)


				if (ShowButton(S_Tool, S_ToolKosuu, &ClickedNo, S_Tool_PushType, S_Tool_Prev, S_Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
					//���}���{�^��
					if (ClickedNo == 0) {//�v���r���[ && S_Tool[0].Nest[3] > DisplayArea2.Nest[1]
						activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
						activemonster = Rot + i;//�e�[�u���̍s�ԍ����擾
						if (*Monster_Kosuu_p < MONSTER_MAX) {//
							//activemonster�ȍ~���P�s���炷
							for (int m = *Monster_Kosuu_p - 1; m >= activemonster; m--) {//monstersuu - 1�̓����X�^�[�̍Ō�̗v�f�ԍ�
								Monster_p[m + 1] = Monster_p[m];

								strcpy(MonsterImgPath_h[m + 1], MonsterImgPath_h[m]);
								monsterhight[m + 1] = monsterhight[m];
								monsterwide[m + 1] = monsterwide[m];
							}
							//activemonster�̍s��������
							struct Monster MonsterClear = { 0 };
							Monster_p[activemonster] = MonsterClear;
							Monster_p[activemonster].Column[0] = *MaxMonsterID_p + 1;
							*MaxMonsterID_p += 1;

							MonsterImgPath_h[activemonster][0] = '\0';
							monsterwide[activemonster] = 0;
							monsterhight[activemonster] = 0;

							*Monster_Kosuu_p += 1;//�����X�^�[�����P���₷

							tablesuu = *Monster_Kosuu_p;
							if (tablesuu > tablesuuMax) tablesuu = tablesuuMax;//�e�[�u������
						}
					}
					//���N���A�[�{�^��
					else if (ClickedNo == 1) {//�}�� && S_Tool[1].Nest[3] > DisplayArea2.Nest[1]
						activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
						activemonster = Rot + i;//�e�[�u���̍s�ԍ����擾
						Monster_p[activemonster].Name[0]='\0';//�����X�^�[���@30���{�I�[
						MonsterImgPath_h[activemonster][0] = '\0';//�����X�^�[�̉摜�p�X
						Monster_p[activemonster].Img = -1;//�����X�^�[�摜�n���h���̎擾
						monsterwide[activemonster] = 0;
						monsterhight[activemonster] = 0;
						//�J�����P�`14�̏�����
						for (int n = 1; n < 15; n++) {//�����X�^�[ID�@4���{�I�[ �@ID�̓N���A�[���Ȃ�
							Monster_p[activemonster].Column[n] = 0;//�J�����P�`14�̏�����
						}
					}
					//���폜�{�^��
					else if (ClickedNo == 2) {//�}�� && S_Tool[1].Nest[3] > DisplayArea2.Nest[1]
						activereset_T(Monster_p, &activezokusei, &activemonster, InputHandle);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
						activemonster = Rot + i;//�e�[�u���̍s�ԍ����擾

						//activemonster�̍s���c����
						for (int m = activemonster; m < *Monster_Kosuu_p; m++) {//*Monster_Kosuu_p�͍ŏI�s�̒ǉ��p�X�y�[�X�̗v�f�ԍ�
							Monster_p[m] = Monster_p[m + 1];
							strcpy(MonsterImgPath_h[m], MonsterImgPath_h[m + 1]);
							monsterhight[m] = monsterhight[m + 1];
							monsterwide[m] = monsterwide[m + 1];
						}
						*Monster_Kosuu_p -= 1;//�����X�^�[�����P���炷
						tablesuu = *Monster_Kosuu_p;
						if (tablesuu > tablesuuMax) tablesuu = tablesuuMax;
					}
				}



				/////////////////////////////////////


			}
			//���`��\�̈�����ɖ߂�
			SetDrawArea(0, 0, 1024, 1000); //�`��\�̈�����ɖ߂��@�c768�`�c980�܂ł̓e�X�g�p
												   /////////���t�@�C����������Ȃ珈�����Ȃ������̉��[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��
		}
		////////���e�[�u���̕\���̏I��

		////�N������C�A�v���͕����Ƀt�@�C���̂ݕ����Ƃ��B�����������X�^�[�̕ҏW�ł͌��󂻂̏󋵂ɂȂ�Ȃ����C����̂��߂ɂ��̂悤�ɂ��Ă����B//////

		if (windowflag == 1) {//�F�ݒ�|�b�v�A�b�v
							  ////�|�b�v�A�b�v�E�B���h�E�̕\��
			static int wakuseniro = GetColor(185, 205, 229);
			int popupwin[4] = { DisplayArea.Nest[0], DisplayArea.Nest[1] + 200, popupwin[0] + 1000, popupwin[1] + 200 };//�|�b�v�A�b�v�E�B���h�E�̘g�̐錾�Ə�����
			DrawBox(popupwin[0], popupwin[1], popupwin[2], popupwin[3], wakuseniro, true); //�|�b�v�A�b�v�E�B���h�E�̘g�̕\��
			DrawBox(popupwin[0] + 5, popupwin[1] + 10 + SystemFontSize, popupwin[2] - 5, popupwin[3] - 5, black, true);//�|�b�v�A�b�v�E�B���h�E�̕\��
			DrawString(popupwin[0] + 5, popupwin[1] + 5, "�J�����̐ݒ�", black);//�|�b�v�A�b�v�E�B���h�E�̃^�C�g���̕\��
			int columnsetteibox[15][4] = { popupwin[0] + 65, popupwin[1] + 10 + 16 + SystemFontSize * 3, popupwin[0] + 220, popupwin[1] + 10 + 16 + SystemFontSize * 5 };
			MonsterTableAll monstertablepop;
			monstertableallsyokika(popupwin[0] + 19, popupwin[1] + 10 + SystemFontSize * 2, &monstertablepop, 1);

			///////�i�R�j�����X�^�[�e�[�u��
			//����
			//////�g�̕⊮�ƑS�̘g
			DrawBox(monstertablepop.column[0][2], monstertablepop.column[0][1], monstertablepop.tablewaku[2], monstertablepop.name[3], gray, false);//�g�̕⊮
			DrawBox(monstertablepop.tablewaku[0], monstertablepop.tablewaku[1], monstertablepop.tablewaku[2], monstertablepop.tablewaku[3], gray, false);//�S�̘g
			DrawBox(monstertablepop.tablewaku[0] + 1, monstertablepop.tablewaku[1] + 1, monstertablepop.tablewaku[2] - 1, monstertablepop.tablewaku[3] - 1, gray, false);//�S�̘g

			//////////�����X�^�[�e�[�u���̕\��
			//�e�[�u���̕\��
			DrawBox(monstertablepop.yousono[0], monstertablepop.yousono[1], monstertablepop.yousono[2], monstertablepop.yousono[3], gray, false);//�����X�^�[�v�f�ԍ��̘g


																																				 //�\��
			DrawBox(monstertablepop.gazou[0], monstertablepop.gazou[1], monstertablepop.gazou[2], monstertablepop.gazou[3], gray, false);//�����X�^�[�摜�̘g

			//�������X�^�[�摜
			int centerX = monstertablepop.gazou[0] + 44; int centerY = monstertablepop.gazou[1] + 44;////�����X�^�[�摜�̘g�̒��S
			int Rate = 3;//������2/3�̑傫���ŕ\���i���S���獶�E��1/3�̈ʒu�j
			DrawExtendGraph(centerX - Undefined_MonsterImgWide / Rate, centerY - Undefined_MonsterImgHeight / Rate, centerX + Undefined_MonsterImgWide / Rate, centerY + Undefined_MonsterImgHeight / Rate, Undefined_MonsterImg, true);  //�����X�^�[�摜��`�悷��

																																											   //�\��
			int titlecolor2 = GetColor(0, 51, 102);
			int titlecolor = GetColor(0, 102, 153);
			//�J����0�̃J�������i�����X�^�[ID�j�̃N���b�N
			if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
				if (monstertablepop.columntitle[0][0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertablepop.columntitle[0][2] && monstertablepop.columntitle[0][1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertablepop.columntitle[0][3]) {//ID�͈͓̔��̂Ƃ�
					activereset_C(&activezokusei, InputHandle, ColumnTitle_buff);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
					activezokusei = 0;//�J�����O�iID�j���A�N�e�B�u�ɂ���i�\�������Ɏg���ϐ��j
									  ///////�V�����n���h���̍쐬
					SetKeyInputCursorBrinkTime(643);// �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
					SetKeyInputCursorBrinkFlag(true);// �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
					InputHandle = MakeKeyInput(MONSTER_COLUMNTITLEFIELDMAX, true, false, false);//�L�[���̓n���h���̐ݒ�  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�
					SetActiveKeyInput(InputHandle);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
					SetKeyInputString(ColumnTitle_buff[0], InputHandle);//�L�[���̓f�[�^�Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
				}
			}
			//�\��
			DrawBox(monstertablepop.columntitle[0][0], monstertablepop.columntitle[0][1], monstertablepop.column[0][2], monstertablepop.column[0][3], gray, false);//�J�����O�iID�j�^�C�g���ƃJ�����i���Ԗځj�̘A���g
			if (*Column_Kosuu_p > 0) {
				DrawBox(monstertablepop.columntitle[0][0] + 1, monstertablepop.columntitle[0][1] + 1, monstertablepop.columntitle[0][2] - 1, monstertablepop.columntitle[0][3] - 1, titlecolor2, true);//�J�����O�iID�j�^�C�g���̔w�i
				if (activezokusei == 0) {//�J�����O�iID�j�̓���
					DrawKeyInputString(monstertablepop.columntitle[0][0] + 4, monstertablepop.columntitle[0][1] + 4, InputHandle);//�L�[���͒��f�[�^�̕`��
					if (CheckKeyInput(InputHandle) != 0) {
						activereset_C(&activezokusei, InputHandle, ColumnTitle_buff);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�G���^�[�Ŋm�莞�j
					}
				}
				else DrawFormatString(monstertablepop.columntitle[0][0] + 4, monstertablepop.columntitle[0][1] + 4, white, "%s", ColumnTitle_buff[0]);//�J�����O�iID�Ԗځj�̕\��
			}

			DrawBox(monstertablepop.nametitle[0], monstertablepop.nametitle[1], monstertablepop.name[2], monstertablepop.name[3], gray, false);//�����X�^�[���^�C�g���ƃ����X�^�[���̘A���g
			DrawBox(monstertablepop.nametitle[0] + 1, monstertablepop.nametitle[1] + 1, monstertablepop.nametitle[2] - 1, monstertablepop.nametitle[3] - 1, titlecolor2, true);//�����X�^�[���^�C�g���̔w�i
			DrawString(monstertablepop.nametitle[0] + 4, monstertablepop.nametitle[1] + 4, "���O", white);//�����X�^�[���^�C�g���̕\��
			int pinknobutton = GetColor(204, 153, 153); int graynobutton = GetColor(153, 153, 153); int gray204204153 = GetColor(204, 204, 153);
			//�J����1�`14�̃J�������̃N���b�N
			for (int k = 1; k < 15; k++) {
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					if (monstertablepop.columntitle[k][0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertablepop.columntitle[k][2] && monstertablepop.columntitle[k][1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertablepop.columntitle[k][3]) {//���OID�͈͓̔��̂Ƃ�
						activereset_C(&activezokusei, InputHandle, ColumnTitle_buff);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
						activezokusei = k;//�J�����i���Ԗځj���A�N�e�B�u�ɂ���i�\�������Ɏg���ϐ��j
										  ///////�V�����n���h���̍쐬
						SetKeyInputCursorBrinkTime(643);// �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
						SetKeyInputCursorBrinkFlag(true);// �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
						InputHandle = MakeKeyInput(MONSTER_COLUMNTITLEFIELDMAX, true, false, false);//�L�[���̓n���h���̐ݒ�  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�
						SetActiveKeyInput(InputHandle);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
						SetKeyInputString(ColumnTitle_buff[k], InputHandle);//�L�[���̓f�[�^�Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
					}
				}
				//�\��
				DrawBox(monstertablepop.columntitle[k][0], monstertablepop.columntitle[k][1], monstertablepop.column[k][2], monstertablepop.column[k][3], gray, false);//�J�����i���Ԗځj�^�C�g���ƃJ�����i���Ԗځj�̘A���g
				if (ColumnKosuubuff > k) {
					if (activezokusei == k) {//�J�����i���Ԗځj�̓���
						DrawKeyInputString(monstertablepop.columntitle[k][0] + 4, monstertablepop.columntitle[k][1] + 4, InputHandle);//�L�[���͒��f�[�^�̕`��
						if (CheckKeyInput(InputHandle) != 0) {
							activereset_C(&activezokusei, InputHandle, ColumnTitle_buff);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�G���^�[�Ŋm�莞�j
						}
					}
					else DrawFormatString(monstertablepop.columntitle[k][0] + 4, monstertablepop.columntitle[k][1] + 4, white, "%s", ColumnTitle_buff[k]);//�J�����i���Ԗځj�̕\��
				}
				else DrawBox(monstertablepop.columntitle[k][0] + 1, monstertablepop.columntitle[k][1] + 1, monstertablepop.columntitle[k][2] - 1, monstertablepop.columntitle[k][3] - 1, gray204204153, true);//�J�����i���Ԗځj�^�C�g���̔w�i
			}
			//�J����1�`14�̃X�C�b�`�̃N���b�N
			for (int k = 1; k < 15; k++) {
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					if (monstertablepop.column[k][0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertablepop.column[k][2] && monstertablepop.column[k][1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertablepop.column[k][3]) {//���OID�͈͓̔��̂Ƃ�
						activereset_C(&activezokusei, InputHandle, ColumnTitle_buff);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�m�肹���Ƀ{�b�N�X���ړ����Ă����Ƃ��̂��߂ɕK�v�j
						if (ColumnKosuubuff < k + 1) {//�N���b�N�����{�^�����I�t�Ȃ�C�N���b�N�����{�^���܂ł��I���ɂ���
							ColumnKosuubuff = k + 1;//�J�����i���Ԗځj���A�N�e�B�u�ɂ���i�\�������Ɏg���ϐ��j
							activezokusei = k;//�J�����i���Ԗځj���A�N�e�B�u�ɂ���i�\�������Ɏg���ϐ��j
											  ///////�V�����n���h���̍쐬
							SetKeyInputCursorBrinkTime(643);// �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
							SetKeyInputCursorBrinkFlag(true);// �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
							InputHandle = MakeKeyInput(MONSTER_COLUMNTITLEFIELDMAX, true, false, false);//�L�[���̓n���h���̐ݒ�  [0]������  [1]ESC�L�[�ɂ��L�����Z���@�\�̗L���@[2]���p�����̂݁@[3]���l�����̂�
							SetActiveKeyInput(InputHandle);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
							SetKeyInputString(ColumnTitle_buff[k], InputHandle);//�L�[���̓f�[�^�Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����


						}
						else ColumnKosuubuff = k;//�N���b�N�����{�^�����I���Ȃ�C�N���b�N�����{�^���ȍ~���I�t�ɂ���
					}
				}
				//�\��
				if (ColumnKosuubuff > k) {

					DrawBox(monstertablepop.column[k][0] + 1, monstertablepop.column[k][1] + 1, monstertablepop.column[k][2] - 1, monstertablepop.column[k][3] - 1, pinknobutton, true);//�J�����i���Ԗځj�^�C�g���̔w�i
					DrawString(monstertablepop.column[k][0] + 14, monstertablepop.column[k][1] + 5, "ON", black);
				}
				else {

					DrawBox(monstertablepop.column[k][0] + 1, monstertablepop.column[k][1] + 1, monstertablepop.column[k][2] - 1, monstertablepop.column[k][3] - 1, graynobutton, true);//�J�����i���Ԗځj�^�C�g���̔w�i
					DrawString(monstertablepop.column[k][0] + 11, monstertablepop.column[k][1] + 5, "OFF", black);
				}
			}


			////�n�j�{�^���̐錾�Ə�������////
			int ok[4] = { popupwin[0] + 750, monstertablepop.tablewaku[3] + SystemFontSize, ok[0] + 100, ok[1] + SystemFontSize + 10 };
			char oktext[] = { "OK" };
			//�m�肷��̏���
			if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
				if (ok[0] < ActiveMath::MouseX && ActiveMath::MouseX < ok[2] && ok[1] < ActiveMath::MouseY && ActiveMath::MouseY < ok[3]) {//�n�j�{�^���͈͓̔��̂Ƃ�
					activereset_C(&activezokusei, InputHandle, ColumnTitle_buff);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�Ȃǁi�G���^�[�Ŋm�莞�j
					for (int i = 0; i < MONSTER_COLUMNMAX; i++) strcpy(ColumnTitle_h[i], ColumnTitle_buff[i]);
					*Column_Kosuu_p = ColumnKosuubuff;
					windowflag = 0;
					Toolbar.Active = 1;

				}
			}
			//�n�j�{�^���̕\��
			DrawBox(ok[0], ok[1], ok[2], ok[3], gray, true); //�n�j�{�^���̕\��
			DrawFormatString(ok[0] + 36, ok[1] + 5, black, oktext); //�����̕\��
																	////�L�����Z���{�^���̐錾�Ə�������////
			int cancel[4] = { ok[2] + SystemFontSize, ok[1], cancel[0] + 100, ok[3] };
			char canceltext[] = { "�L�����Z��" };
			//�L�����Z���̏���
			if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
				if (cancel[0] < ActiveMath::MouseX && ActiveMath::MouseX < cancel[2] && cancel[1] < ActiveMath::MouseY && ActiveMath::MouseY < cancel[3]) {//�L�����Z���͈͓̔��̂Ƃ�
					windowflag = 0;
					//ToolbarA.Active = 1;
					Toolbar.Active = 1;
					DisplayArea.Active = 1;

				}
			}
			//�L�����Z���{�^���̕\��
			DrawBox(cancel[0], cancel[1], cancel[2], cancel[3], gray, true); //�L�����Z���{�^���̕\��
			DrawFormatString(cancel[0] + 15, cancel[1] + 5, black, canceltext); //�����̕\��



		}
		//�J�[�\���I�[�o�[
		static const int BackColor = GetColor(230, 255, 230);//R:255 G:255 B:204
		int LocationX = ActiveMath::MouseX; int LocationY = ActiveMath::MouseY + 20;
		Math_CursorOver(LocationX, LocationY, 2, black, BackColor, NULL);//Math_ButtonTitleShow(const int LocationX, const int LocationY, const int Padding, const int StringColor, const int BackColor, const int Type)


	}
	//////////�������X�^�[�ҏW���C�����[�v�̏I��聪//////////////////�������X�^�[�ҏW���C�����[�v�̏I��聪//////////�������X�^�[�ҏW���C�����[�v�̏I��聪///////////�������X�^�[�ҏW���C�����[�v�̏I��聪/////////
	return 0;
}

int Untitled(Kadai* mondai, int* syoumonsuu_p, char* monster_gazou_zero, int* monsterno_p, int* GazouHandle_p, int* monsterwide_p, int* monsterhight_p) {
	struct Kadai Mondai_Clear = { 0 };
	*mondai = Mondai_Clear;//���̏�����
						   ////���֘A�̕ϐ��@�錾�Ə�����////////////
	*syoumonsuu_p = 1;//���␔�i���ۂ̌��j�͂P���ŏ�
	*monsterno_p = 0;//0�F�����X�^�[�e�[�u�����ł̗v�f�ԍ�
	*GazouHandle_p = LoadGraph(monster_gazou_zero); //�摜�n���h�����擾
	GetGraphSize(*GazouHandle_p, monsterwide_p, monsterhight_p); //�����X�^�[�̉摜�̏c���T�C�Y���擾����monsterwide�Cmonsterhight�ɏ����o��
	return 0;
}


//���C��␳���C����C���␳���̃A�N�e�B�u�v���p�e�B�C�A�N�e�B�u�ȏ���ԍ��C���␳��ԍ��̃��Z�b�g�@
int ActiveClear(struct MsgBoxCtrl* MsgBoxCtrl_p) {
	MsgBoxCtrl_p->Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
										  //MsgBoxCtrl_p->ActiveCharNo = -1;
										  //MsgBoxCtrl_p->ActiveTagNo = 0;
										  //MsgBoxCtrl_p->tag[0].oyawakuidou = 0;
	return 0;
}
int activereset(char** Message_p, struct MsgBoxCtrl* HMsgBoxHCtrl_D_p, struct MsgBoxCtrl* HMsgBoxHCtrl_DS, struct MsgBoxCtrl* HMsgBoxHCtrl_S, struct MsgBoxCtrl* HMsgBoxHCtrl_SS,
	int* activesyoumonH_p, int* activesyoumonseikaiH_p) {
	HMsgBoxHCtrl_D_p->Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
	HMsgBoxHCtrl_D_p->Tag[0].PositionM = -1;//tag[0].PositionM��ActiveCharNo�̑�p
	HMsgBoxHCtrl_D_p->Tag[0].LastNumInParsedMsg = 0;//tag[0].LastNumInParsedMsg��ActiveTagNo�Ƃ��đ�p

	HMsgBoxHCtrl_DS->Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
	HMsgBoxHCtrl_DS->Tag[0].PositionM = -1;//tag[0].PositionM��ActiveCharNo�̑�p
	HMsgBoxHCtrl_DS->Tag[0].LastNumInParsedMsg = 0;//tag[0].LastNumInParsedMsg��ActiveTagNo�Ƃ��đ�p


	if (*activesyoumonH_p >= 0) {
		//����̃��Z�b�g
		HMsgBoxHCtrl_S[*activesyoumonH_p].Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
		HMsgBoxHCtrl_S[*activesyoumonH_p].Tag[0].PositionM = -1;//tag[0].PositionM��ActiveCharNo�̑�p
		HMsgBoxHCtrl_S[*activesyoumonH_p].Tag[0].LastNumInParsedMsg = 0;//tag[0].LastNumInParsedMsg��ActiveTagNo�Ƃ��đ�p
		//�A�����ď��␳�������Z�b�g
		HMsgBoxHCtrl_SS[*activesyoumonH_p].Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
		HMsgBoxHCtrl_SS[*activesyoumonH_p].Tag[0].PositionM = -1;//tag[0].PositionM��ActiveCharNo�̑�p
		HMsgBoxHCtrl_SS[*activesyoumonH_p].Tag[0].LastNumInParsedMsg = 0;//tag[0].LastNumInParsedMsg��ActiveTagNo�Ƃ��đ�p
	}
	if (*activesyoumonseikaiH_p >= 0) {
		//�A�����ď�������Z�b�g
		HMsgBoxHCtrl_S[*activesyoumonseikaiH_p].Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
		HMsgBoxHCtrl_S[*activesyoumonseikaiH_p].Tag[0].PositionM = -1;//tag[0].PositionM��ActiveCharNo�̑�p
		HMsgBoxHCtrl_S[*activesyoumonseikaiH_p].Tag[0].LastNumInParsedMsg = 0;//tag[0].LastNumInParsedMsg��ActiveTagNo�Ƃ��đ�p
		//���␳���̃��Z�b�g
		HMsgBoxHCtrl_SS[*activesyoumonseikaiH_p].Tag[0].PositionP = -1;//tag[0].PositionP��ActiveElement�̑�p
		HMsgBoxHCtrl_SS[*activesyoumonseikaiH_p].Tag[0].PositionM = -1;//tag[0].PositionM��ActiveCharNo�̑�p
		HMsgBoxHCtrl_SS[*activesyoumonseikaiH_p].Tag[0].LastNumInParsedMsg = 0;//tag[0].LastNumInParsedMsg��ActiveTagNo�Ƃ��đ�p
	}
	*activesyoumonH_p = -1;
	*activesyoumonseikaiH_p = -1;//���C����C���␳���̃A�N�e�B�u����U���Z�b�g�i�\�������Ɏg���ϐ��j
	*Message_p = NULL;
	return 0;


}


struct SyoumonHyoujiH {
	int midashi[2];//[0]�J�n�ʒu���@[1]�J�n�ʒu��
	int syoumon[4];//�z��v�f�ix1�Cy1�Cx2�Cy2�j
				   //int syoumontext[20];//�z��v�f�ix1�Cy1�Cx2�Cy2�C���ӂꂽ�ʁC�����o���w���C�J�E���^�[�C���t���O�j�����o���w��[5]���P���Q�Ȃ珑���o���@(�O�F�����o���s�@�P�F�t���[�Y�����o���@�Q�F�����܂ŏ����o���ς݁j
	int seikai[4];//�z��v�f�ix1�Cy1�Cx2�Cy2�j
				  //int seikaitext[20];//�z��v�f�ix1�Cy1�Cx2�Cy2�C���ӂꂽ�ʁC�����o���w���C�J�E���^�[�C���t���O�j�����o���w��[5]���P���Q�Ȃ珑���o���@(�O�F�����o���s�@�P�F�t���[�Y�����o���@�Q�F�����܂ŏ����o���ς݁j
	int kaisetsu[4];
	int sounyuu[4];	int sounyuugazou1;	int sounyuugazou2;
	int sounyuuharitsuke[4];	int sounyuuharitsukegazou1;	int sounyuuharitsukegazou2;
	int cut[4];	int cutgazou1;	int cutgazou2;
	int copy[4];	int copygazou1;	int copygazou2;
	int irekae[4];	int irekaegazou1;	int irekaegazou2;
	int paste[4];	int pastegazou1;	int pastegazou2;
	int sakujyo[4];	int sakujyogazou1;	int sakujyogazou2;
	int clear[4];	int cleargazou1;	int cleargazou2;
	int preview[4];	int preview1;	int preview2;
	int count;
};

struct SyoumonSeikaiHyoujiH {
	int preview[4];	int preview1;	int preview2;
};

/*
int MsgBoxCtrlReset(struct MsgBoxCtrl* HMsgBoxHCtrl_D, struct MsgBoxCtrl* HMsgBoxHCtrl_DS, struct MsgBoxCtrl* HMsgBoxHCtrl_S_h, struct MsgBoxCtrl* HMsgBoxHCtrl_SS_h, int* MessageBox_h) {
static struct MsgBoxCtrl MsgBoxCtrl_Clear = { 0 };
//*HMsgBoxHCtrl_D = MsgBoxCtrl_Clear;
//*HMsgBoxHCtrl_DS = MsgBoxCtrl_Clear;
//for (int i = 0; i < SYOUMON_MAX; i++) {
//	*(HMsgBoxHCtrl_S_h + i) = MsgBoxCtrl_Clear;
//	*(HMsgBoxHCtrl_SS_h + i) = MsgBoxCtrl_Clear;
//}


//HMsgBoxHCtrl_D->OutputType = 1;//�o�̓^�C�v�i�O�F�l�̎擾�@�P�F��蕶�̓��͕\���@�Q�F�����̓��͕\���@�R�F��蕶�̓��͕\���i�J�[�\���Ȃ��j�@�U�F��蕶�̕\���@�V�F���b�Z�[�W�̕\���j
//HMsgBoxHCtrl_D->StartTagLength = 3;//<p>�̎��̕���
//HMsgBoxHCtrl_D->EndTagLength = 4;//</p>��'<'

//HMsgBoxHCtrl_D->ActiveElement = -1;//�A�N�e�B�u�v�f//�A�N�e�B�u�����Ȃ��i�����̓A�N�e�B�u�v�f�Ȃ��i�J�[�\�����\������Ȃ��j�B�{�b�N�X���N���b�N�����ʒu���珉�߂̒l���擾�j)
//HMsgBoxHCtrl_D->ClickMoji = -1;//�A�N�e�B�u����

//HMsgBoxHCtrl_D->MessageArea[0] = MessageBox_h[0] + 1 + systemfontsize;//���[
//HMsgBoxHCtrl_D->MessageArea[1] = MessageBox_h[1] + 1 + systemfontsize;//��[ //systemfontsize�̓R�}���h�������}�[�N�̂Ԃ�i��␳���C����C���␳���͏�̃{�b�N�X�̉��[�������p�����߁C�����o���O�ɓs�x���Z�j
//HMsgBoxHCtrl_D->MessageArea[2] = MessageBox_h[2] - 1 - systemfontsize;//�E�[
//HMsgBoxHCtrl_D->MessageArea[3] = MessageBox_h[3] - 1 + systemfontsize;//���[

//HMsgBoxHCtrl_D->Condition = 1;//

//*HMsgBoxHCtrl_DS = *HMsgBoxHCtrl_D; //��␳���v���p�e�B�̐ݒ�i���v���p�e�B�Ɠ����ɂ���j
//HMsgBoxHCtrl_DS->StartTagLength = 6;//�U�͏����l�����D���v���p�e�B���܂邲�ƃR�s�[��������Ē�`
//HMsgBoxHCtrl_DS->EndTagLength = 7;//�V�͏����l�����C���v���p�e�B���܂邲�ƃR�s�[��������Ē�`

for (int i = 0; i < SYOUMON_MAX; i++) {//����v���p�e�B�̐ݒ�
//(HMsgBoxHCtrl_S_h + i)->OutputType = 1;//�o�̓^�C�v�i�O�F�l�̎擾�@�P�F��蕶�̓��͕\���@�Q�F�����̓��͕\���@�R�F��蕶�̓��͕\���i�J�[�\���Ȃ��j�@�U�F��蕶�̕\���@�V�F���b�Z�[�W�̕\���j
//(HMsgBoxHCtrl_S_h + i)->StartTagLength = 3;
//(HMsgBoxHCtrl_S_h + i)->EndTagLength = 4;

//(HMsgBoxHCtrl_S_h + i)->ActiveElement = -1;//�A�N�e�B�u�v�f�Ȃ��i�����̓A�N�e�B�u�v�f�Ȃ��i�J�[�\�����\������Ȃ��j�B�{�b�N�X���N���b�N�����ʒu���珉�߂̒l���擾�j)
//(HMsgBoxHCtrl_S_h + i)->ClickMoji = -1;//�A�N�e�B�u����

HMsgBoxHCtrl_S_h[i] = *HMsgBoxHCtrl_D; //����v���p�e�B�̐ݒ�i���v���p�e�B�Ɠ����ɂ���j

//(HMsgBoxHCtrl_S_h + i)->MessageArea[0] = HMsgBoxHCtrl_D->MessageArea[0];//���[
//(HMsgBoxHCtrl_S_h + i)->MessageArea[2] = HMsgBoxHCtrl_D->MessageArea[2];//�E�[  ���L�Q�s�̏������ɂ�����
(HMsgBoxHCtrl_S_h + i)->MessageArea[0] = MessageBox_h[0] + 1 + systemfontsize;//���[
(HMsgBoxHCtrl_S_h + i)->MessageArea[2] = MessageBox_h[2] - 1 - systemfontsize;//�E�[

}
for (int i = 0; i < SYOUMON_MAX - 1; i++) {//����v���p�e�B�̐ݒ�
HMsgBoxHCtrl_S_h[i + 1] = HMsgBoxHCtrl_S_h[i];
}
for (int i = 0; i < SYOUMON_MAX; i++) {
HMsgBoxHCtrl_SS_h[i] = HMsgBoxHCtrl_S_h[i]; //���␳���v���p�e�B�̐ݒ�i����v���p�e�B�Ɠ����ɂ���j
(HMsgBoxHCtrl_SS_h + i)->StartTagLength = 6;//�U�͏����l�����C����v���p�e�B���܂邲�ƃR�s�[��������Ē�`
(HMsgBoxHCtrl_SS_h + i)->EndTagLength = 7;//�V�͏����l�����C����v���p�e�B���܂邲�ƃR�s�[��������Ē�`

}
return 0;
}*/
int MsgBoxCtrlReset_message(struct MsgBoxCtrl* MsgBoxCtrl, int* MessageDisplatArea_h) {
	//static struct MsgBoxCtrl MsgBoxCtrl_Clear = { 0 };
	//*MsgBoxCtrl = MsgBoxCtrl_Clear;

	//MsgBoxCtrl->OutputType = 1;//�o�̓^�C�v�i�O�F�l�̎擾�@�P�F��蕶�̓��͕\���@�Q�F�����̓��͕\���@�R�F��蕶�̓��͕\���i�J�[�\���Ȃ��j�@�U�F��蕶�̕\���@�V�F���b�Z�[�W�̕\���j
	//MsgBoxCtrl->StartTagLength = 3;//<p>�̎��̕���
	//MsgBoxCtrl->EndTagLength = 4;//</p>��'<'

	//MsgBoxCtrl->ActiveElement = -1;//�A�N�e�B�u�v�f//�A�N�e�B�u�����Ȃ��i�����̓A�N�e�B�u�v�f�Ȃ��i�J�[�\�����\������Ȃ��j�B�{�b�N�X���N���b�N�����ʒu���珉�߂̒l���擾�j)
	//MsgBoxCtrl->ClickMoji = -1;//�A�N�e�B�u����

	MsgBoxCtrl->Location[0] = MessageDisplatArea_h[0] + 1 + SystemFontSize;//���[
	MsgBoxCtrl->Location[1] = MessageDisplatArea_h[1] + 1 + SystemFontSize;//��[ //systemfontsize�̓R�}���h�������}�[�N�̂Ԃ�i��␳���C����C���␳���͏�̃{�b�N�X�̉��[�������p�����߁C�����o���O�ɓs�x���Z�j
	MsgBoxCtrl->Location[2] = MessageDisplatArea_h[2] - 1 - SystemFontSize;//�E�[
	MsgBoxCtrl->Location[3] = MessageDisplatArea_h[3] - 1 - SystemFontSize;//���[

	//MsgBoxCtrl->Condition = 1;//

	return 0;
}

//�v���r���[���[�h�̐ݒ�i�v���r���[���[�h�ŁC����̐F�C����̈ʒu�C�w�i�F�C�w�i�摜�̕ύX
//�����b�Z�[�W���[�h�͎����C�����I�Ƀv���r���[���[�h�ɐi�ނ̂ł��̊֐��@������̈ʒu�̓f�B�X�v���C�G���A�̍��p�f�B���O�ƉE�p�f�B���O�@
int SettingPreviewMode(const TCHAR *FilePath_h, struct AREACONTROL *DisplayArea_p, int(*BorderColorRGB_h)[3], int(*BackColorRGB_h)[3], char(*BackImgPath_h)[MAX_PATH], 
	int Area_Kosuu, int AreaNum, int *EditorSettingsFlag_p) {

	static struct AREACONTROL PropertyArea = { 0 };
	static struct BUTTONFORM PropertyBtnForm = { 0 };
	static int L0 = SystemFontSize * 0;
	static int L1 = SystemFontSize * 1.5;
	static int L2 = SystemFontSize * 3;
	static int L3 = SystemFontSize * 4.5;
	static int L4 = SystemFontSize * 6;

	const int PropertyBtn_Kosuu = 16;
	static struct BUTTONCONTROL PropertyBtn[PropertyBtn_Kosuu] = { 0 };
	static struct BUTTONFORM SaveUnSaveBtnForm = { 0 };
	const int SaveUnSaveBtn_Kosuu = 2;
	static struct BUTTONCONTROL SaveUnSaveBtn[SaveUnSaveBtn_Kosuu] = { 0 };

	static int BorderColorRGB_Copy[3];//RGB
	static int BackColorRGB_Copy[3];//RGB
	static char BackImgPath_Copy[MAX_PATH];//�p�X

	static int BorderColor_Copy;
	static int BackColor_Copy;
	static int BackImg_Copy;

	static int Padding_Copy[2];

	//�N���b�N����̂ݏ������i�Ⴄ���[�h�ł��g�p���邩��static�̐錾���ł͂Ȃ�*EditorSettingsFlag_p == 1�̂Ƃ��ɏ���������j
	//������///////////////////////////////
	if (*EditorSettingsFlag_p == 1) {
		*EditorSettingsFlag_p = 2;
		for (int i = 0; i < 3; i++) {
			BorderColorRGB_Copy[i] = BorderColorRGB_h[AreaNum][i];//RGB
			BackColorRGB_Copy[i] = BackColorRGB_h[AreaNum][i];//RGB
		}
		strcpy(BackImgPath_Copy, BackImgPath_h[AreaNum]);//�p�X

		BorderColor_Copy = DisplayArea_p[AreaNum].BorderColor;
		BackColor_Copy = DisplayArea_p[AreaNum].BackColor;
		BackImg_Copy = DisplayArea_p[AreaNum].BackImg;

		for (int i = 0; i < 2; i++) Padding_Copy[i] = DisplayArea_p[AreaNum].Padding[i];

		//���v���p�e�B�G���A
		PropertyArea.Width = 410;
		PropertyArea.Height = 130;
		PropertyArea.Location[0] = (WindowWidth - PropertyArea.Width) / 2;
		PropertyArea.Location[1] = (WindowHeight - PropertyArea.Height) / 2;
		for (int i = 0; i < 4; i++) PropertyArea.Padding[i] = 10;
		PropertyArea.BackColor = GetColor(112, 128, 144);//NULL;// 
		PropertyArea.Active = 1;
		//���v���p�e�B�{�^���t�H�[��
		PropertyBtnForm.BorderThickness = 1;
		PropertyBtnForm.BorderColor = GetColor(0, 102, 102);//255, 51, 51
		PropertyBtnForm.WaitingColor = GetColor(204, 204, 204);
		PropertyBtnForm.CursorColor = GetColor(255, 255, 204);
		PropertyBtnForm.PushedColor = GetColor(153, 0, 153);

		//���v���p�e�B�̃p�����[�^�ύX�{�^��
		for (int b = 0; b < PropertyBtn_Kosuu; b++) {
			PropertyBtn[b].ParentArea_p = &PropertyArea;
			PropertyBtn[b].ButtonForm_p = &PropertyBtnForm;
			PropertyBtn[b].Padding[0] = 6; PropertyBtn[b].Padding[1] = 5; PropertyBtn[b].Padding[2] = 6; PropertyBtn[b].Padding[3] = 5;//
			PropertyBtn[b].Width = SystemFontSize;
			PropertyBtn[b].Height = SystemFontSize / 2;
			PropertyBtn[b].Active = 1;//�s�v�H
		}
		//��BorderColorR
		int BtnNo = 0;//Up0
		int Width = GetDrawStringWidth("R()", strlen("R()")) + SystemFontSize * 2;
		PropertyBtn[BtnNo].Location[0] = 80 * 1 + Width;
		PropertyBtn[BtnNo].Location[1] = L0;
		BtnNo++;//Down1
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//BorderColorG
		BtnNo++;//Up2
		PropertyBtn[BtnNo].Location[0] = 80 * 2 + Width;
		PropertyBtn[BtnNo].Location[1] = L0;
		BtnNo++;//Down3
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//BorderColorB
		BtnNo++;//Up4
		PropertyBtn[BtnNo].Location[0] = 80 * 3 + Width;
		PropertyBtn[BtnNo].Location[1] = L0;
		BtnNo++;//Down5
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//��Padding[0]
		BtnNo++;//Up6
		PropertyBtn[BtnNo].Location[0] = 80 * 2 + Width;
		PropertyBtn[BtnNo].Location[1] = L1;
		BtnNo++;//Down7
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//Padding[1]
		BtnNo++;//Up8
		PropertyBtn[BtnNo].Location[0] = 80 * 3 + Width;
		PropertyBtn[BtnNo].Location[1] = L1;
		BtnNo++;//Down9
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//��BackColorR
		BtnNo++;//Up10
		PropertyBtn[BtnNo].Location[0] = 80 * 1 + Width;
		PropertyBtn[BtnNo].Location[1] = L2;
		BtnNo++;//Down11
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//BackColorG
		BtnNo++;//Up12
		PropertyBtn[BtnNo].Location[0] = 80 * 2 + Width;
		PropertyBtn[BtnNo].Location[1] = L2;
		BtnNo++;//Down13
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;
		//BackColorB
		BtnNo++;//Up14
		PropertyBtn[BtnNo].Location[0] = 80 * 3 + Width;
		PropertyBtn[BtnNo].Location[1] = L2;
		BtnNo++;//Down15
		PropertyBtn[BtnNo].Location[0] = -222222;
		PropertyBtn[BtnNo].Location[1] = -111111;

		//���ۑ��E�L�����Z���{�^���t�H�[��
		for (int i = 0; i < 4; i++) SaveUnSaveBtnForm.Margin[i] = 1;
		SaveUnSaveBtnForm.BorderThickness = 1;
		SaveUnSaveBtnForm.BorderColor = GetColor(0, 102, 102);//255, 51, 51
		SaveUnSaveBtnForm.WaitingColor = GetColor(204, 204, 204);
		SaveUnSaveBtnForm.CursorColor = GetColor(255, 255, 204);
		SaveUnSaveBtnForm.PushedColor = GetColor(153, 0, 153);

		//���ۑ��E�L�����Z���{�^��
		for (int b = 0; b < SaveUnSaveBtn_Kosuu; b++) {
			SaveUnSaveBtn[b].ParentArea_p = &PropertyArea;
			SaveUnSaveBtn[b].ButtonForm_p = &SaveUnSaveBtnForm;
			SaveUnSaveBtn[b].Padding[0] = -1; SaveUnSaveBtn[b].Padding[1] = -1; SaveUnSaveBtn[b].Padding[2] = 6; SaveUnSaveBtn[b].Padding[3] = 5;//
			SaveUnSaveBtn[b].Width = 100;
			SaveUnSaveBtn[b].Height = 24;
			SaveUnSaveBtn[b].Active = 1;//�s�v�H
		}

		int SaveUnSaveBtnNo = 0;//�ϐ��ė��p
		//�ۑ�
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[0] = 390 - 200 - 3;//390=�v���p�e�B�G���A�̏����o���͈͂̉E�[�@200=�ۑ��E�L�����Z���{�^���̕��@3���ۑ��̃}�[�W��0�{�ۑ��̃}�[�W��2�{�L�����Z���̃}�[�W��0
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[1] = -PropertyBtnForm.Margin[1] + L4;
		strcpy(SaveUnSaveBtn[SaveUnSaveBtnNo].Title, "�ۑ�����");
		//�L�����Z��
		SaveUnSaveBtnNo++;
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[0] = -111111;
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[1] = -222222;
		strcpy(SaveUnSaveBtn[SaveUnSaveBtnNo].Title, "�L�����Z��");

	}

	//�\��///////////////////////////////
	//�v���p�e�B�G���A
	ShowArea(&PropertyArea, 1);//��2�����͂̓G���A�̌�������P

	//�p�����[�^�ύX�{�^��
	int PropertyBtn_PushType = 0; int PropertyBtn_Prev = -2; int PropertyBtn_Next = -2;
	int PropertyBtnClicked;
	int ClickedNo = -1;//�����ꂽ�{�^���ԍ�
	PropertyBtnClicked = ShowButton(PropertyBtn, PropertyBtn_Kosuu, &ClickedNo, PropertyBtn_PushType, PropertyBtn_Prev, PropertyBtn_Next);
	// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

	//�w�i�F�@�������u�Ԃ܂��͒�������
	if (PropertyBtnClicked == 1 || PropertyBtnClicked > 20) {
		if (0 <= ClickedNo && ClickedNo <= 5) {
			if (ClickedNo == 0 && BorderColorRGB_h[AreaNum][0] < 255) BorderColorRGB_h[AreaNum][0] += 1;
			else if (ClickedNo == 1 && BorderColorRGB_h[AreaNum][0] > -1) BorderColorRGB_h[AreaNum][0] -= 1;

			else if (ClickedNo == 2 && BorderColorRGB_h[AreaNum][1] < 255) BorderColorRGB_h[AreaNum][1] += 1;
			else if (ClickedNo == 3 && BorderColorRGB_h[AreaNum][1] > 0) BorderColorRGB_h[AreaNum][1] -= 1;

			else if (ClickedNo == 4 && BorderColorRGB_h[AreaNum][2] < 255) BorderColorRGB_h[AreaNum][2] += 1;
			else if (ClickedNo == 5 && BorderColorRGB_h[AreaNum][2] > 0) BorderColorRGB_h[AreaNum][2] -= 1;
			if (BorderColorRGB_h[AreaNum][0] >= 0) DisplayArea_p[AreaNum].BorderColor = GetColor(BorderColorRGB_h[AreaNum][0], BorderColorRGB_h[AreaNum][1], BorderColorRGB_h[AreaNum][2]);
			else DisplayArea_p[AreaNum].BorderColor = NULL;
		}

		else if (ClickedNo == 6) DisplayArea_p[AreaNum].Padding[0] += 1;
		else if (ClickedNo == 7 && DisplayArea_p[AreaNum].Padding[0] > 0) DisplayArea_p[AreaNum].Padding[0] -= 1;
		else if (ClickedNo == 8) DisplayArea_p[AreaNum].Padding[1] += 1;
		else if (ClickedNo == 9 && DisplayArea_p[AreaNum].Padding[1] > 0) DisplayArea_p[AreaNum].Padding[1] -= 1;

		if (10 <= ClickedNo && ClickedNo <= 15) {
			if (ClickedNo == 10 && BackColorRGB_h[AreaNum][0] < 255) BackColorRGB_h[AreaNum][0] += 1;
			else if (ClickedNo == 11 && BackColorRGB_h[AreaNum][0] > -1) BackColorRGB_h[AreaNum][0] -= 1;

			else if (ClickedNo == 12 && BackColorRGB_h[AreaNum][1] < 255) BackColorRGB_h[AreaNum][1] += 1;
			else if (ClickedNo == 13 && BackColorRGB_h[AreaNum][1] > 0) BackColorRGB_h[AreaNum][1] -= 1;

			else if (ClickedNo == 14 && BackColorRGB_h[AreaNum][2] < 255) BackColorRGB_h[AreaNum][2] += 1;
			else if (ClickedNo == 15 && BackColorRGB_h[AreaNum][2] > 0) BackColorRGB_h[AreaNum][2] -= 1;
			if (BackColorRGB_h[AreaNum][0] >= 0) DisplayArea_p[AreaNum].BackColor = GetColor(BackColorRGB_h[AreaNum][0], BackColorRGB_h[AreaNum][1], BackColorRGB_h[AreaNum][2]);
			else DisplayArea_p[AreaNum].BackColor = NULL;
		}

	}
	//�e�s�̏����o��
	DrawString(PropertyArea.Nest[0] + 80 * 0, PropertyArea.Nest[1] + L0, "����̐F", black);
	if (BorderColorRGB_h[AreaNum][0] < 0) DrawFormatString(PropertyArea.Nest[0] + 80 * 1, PropertyArea.Nest[1] + L0, black, "���F");
	else DrawFormatString(PropertyArea.Nest[0] + 80 * 1, PropertyArea.Nest[1] + L0, black, "R(%d)", BorderColorRGB_h[AreaNum][0]);
	DrawFormatString(PropertyArea.Nest[0] + 80 * 2, PropertyArea.Nest[1] + L0, black, "G(%d)", BorderColorRGB_h[AreaNum][1]);
	DrawFormatString(PropertyArea.Nest[0] + 80 * 3, PropertyArea.Nest[1] + L0, black, "B(%d)", BorderColorRGB_h[AreaNum][2]);

	DrawString(PropertyArea.Nest[0] + 80 * 0, PropertyArea.Nest[1] + L1, "����̈ʒu", black);
	DrawFormatString(PropertyArea.Nest[0] + 80 * 2, PropertyArea.Nest[1] + L1, black, "X(%d)", DisplayArea_p[AreaNum].Padding[0]);
	DrawFormatString(PropertyArea.Nest[0] + 80 * 3, PropertyArea.Nest[1] + L1, black, "Y(%d)", DisplayArea_p[AreaNum].Padding[1]);

	DrawString(PropertyArea.Nest[0] + 80 * 0, PropertyArea.Nest[1] + L2, "�w�i�F", black);
	if (BackColorRGB_h[AreaNum][0] < 0) DrawFormatString(PropertyArea.Nest[0] + 80 * 1, PropertyArea.Nest[1] + L2, black, "���F");
	else DrawFormatString(PropertyArea.Nest[0] + 80 * 1, PropertyArea.Nest[1] + L2, black, "R(%d)", BackColorRGB_h[AreaNum][0]);
	DrawFormatString(PropertyArea.Nest[0] + 80 * 2, PropertyArea.Nest[1] + L2, black, "G(%d)", BackColorRGB_h[AreaNum][1]);
	DrawFormatString(PropertyArea.Nest[0] + 80 * 3, PropertyArea.Nest[1] + L2, black, "B(%d)", BackColorRGB_h[AreaNum][2]);

	//�w�i�p�X
	static int SpotColor = GetColor(255, 255, 204);
	static int BackImgPath_x1 = PropertyArea.Nest[0] + GetDrawStringWidth("�w�i�摜", strlen("�w�i�摜"));
	static int BackImgPath_y1 = PropertyArea.Nest[1] + L3;
	int BackImgPath_Len = GetDrawStringWidth(BackImgPath_h[AreaNum], strlen(BackImgPath_h[AreaNum]));
	if (BackImgPath_x1 < ActiveMath::MouseX && ActiveMath::MouseX < BackImgPath_x1 + BackImgPath_Len + SystemFontSize && BackImgPath_y1 < ActiveMath::MouseY && ActiveMath::MouseY < BackImgPath_y1 + SystemFontSize) {
		//�X�|�b�g
		DrawBox(BackImgPath_x1, BackImgPath_y1, BackImgPath_x1 + BackImgPath_Len + SystemFontSize, BackImgPath_y1 + SystemFontSize, SpotColor, true);
		//�����ꂽ�Ƃ�
		if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
			char ImgFileTitle[MAX_PATH];
			char Dir[MAX_PATH];
			//�_�C�A���O����t�@�C�������擾
			strcpy(Dir, AppDir);
			strcat(Dir, "\\System\\BackImg");
			if (GetImgFileName(Dir, BackImgPath_h[AreaNum], ImgFileTitle, MAX_PATH, MAX_PATH, 0)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
				if (BackImgPath_h[AreaNum][0] != '\0') DisplayArea_p[AreaNum].BackImg = LoadGraph(BackImgPath_h[AreaNum]);
				//�t�@�C���擾�ɐ���������Dir����݂��t�@�C���̑��΃p�X���擾
				PathRelativePathTo(BackImgPath_h[AreaNum], AppDir, FILE_ATTRIBUTE_DIRECTORY, BackImgPath_h[AreaNum], FILE_ATTRIBUTE_ARCHIVE);
			}
			//�_�C�A���O�̃L�����Z���ŁC�p�X�ƃn���h�����폜
			else {
				DisplayArea_p[AreaNum].BackImg = -1;
			}
		}

	}
	DrawFormatString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L3, black, "�w�i�摜(%s)", BackImgPath_h[AreaNum]);

	//�ۑ��E�L�����Z���{�^��
	int PropertyOkCancelBtn_PushType = 0; int PropertyOkCancelBtn_Prev = -2; int PropertyOkCancelBtn_Next = -2;
	int  PropertyOkCancelBtnClicked;
	int PropertyOkCancelBtnClickedNo = -1;//�����ꂽ�{�^���ԍ�
	PropertyOkCancelBtnClicked = ShowButton(SaveUnSaveBtn, SaveUnSaveBtn_Kosuu, &PropertyOkCancelBtnClickedNo, PropertyOkCancelBtn_PushType, PropertyOkCancelBtn_Prev, PropertyOkCancelBtn_Next);
	// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

	//�{�^�����������u��
	if (PropertyOkCancelBtnClicked == 1) {
		//OK�{�^��
		if (PropertyOkCancelBtnClickedNo == 0) {
			//�w�i�F��RGB�C�w�i�p�X�̕ۑ�
			SetCurrentDirectory(AppDir);
			SaveEditorSettings(FilePath_h, DisplayArea_p, BorderColorRGB_h, BackColorRGB_h, BackImgPath_h, Area_Kosuu);//�X�^�C���Z�b�g�̕ۑ� &buff
			//�ݒ�G���A�̒�~
			*EditorSettingsFlag_p = 0;
			return 1;
		}
		//�L�����Z���{�^��
		else if (PropertyOkCancelBtnClickedNo == 1) {
			//�w�i�F��RGB�C�w�i�F�̃n���h���C�w�i�p�X�C�w�i�p�X�̃n���h�������ɖ߂�
			for (int i = 0; i < 3; i++) {
				BorderColorRGB_h[AreaNum][i] = BorderColorRGB_Copy[i];
				BackColorRGB_h[AreaNum][i] = BackColorRGB_Copy[i];
			}
			strcpy(BackImgPath_h[AreaNum], BackImgPath_Copy);//�p�X
			DisplayArea_p[AreaNum].BorderColor = BorderColor_Copy;
			DisplayArea_p[AreaNum].BackColor = BackColor_Copy;
			DisplayArea_p[AreaNum].BackImg = BackImg_Copy;
			for (int i = 0; i < 2; i++) DisplayArea_p[AreaNum].Padding[i] = Padding_Copy[i];

			//�ݒ�G���A�̒�~
			*EditorSettingsFlag_p = 0;
			return -1;
		}
	}
	return 0;

}

//�e���[�h�ŁC�w�i�F�C�w�i�摜�̕ύX�@�����b�Z�[�W���[�h�͎����C�����I�Ƀv���r���[���[�h�ɐi�ނ̂ł��̊֐��ł͂Ȃ�SettingPreviewMode���g��
int SettingEditorBack(struct AREACONTROL *DisplayArea_p, int(*BorderColorRGB_h)[3], int(*BackColorRGB_h)[3], char(*BackImgPath_h)[MAX_PATH], int Area_Kosuu, int *EditorSettingsFlag_p){

	static struct AREACONTROL PropertyArea = { 0 };
	static struct BUTTONFORM PropertyBtnForm = { 0 };

	const int PropertyBtn_Kosuu = 6;
	const int Area_Max = 4;

	static struct BUTTONCONTROL PropertyBtn[Area_Max][PropertyBtn_Kosuu] = { 0 };
	static struct BUTTONFORM SaveUnSaveBtnForm = { 0 };
	const int SaveUnSaveBtn_Kosuu = 2;
	static struct BUTTONCONTROL SaveUnSaveBtn[SaveUnSaveBtn_Kosuu] = { 0 };

	static int BackColorRGB_Copy[2][3];//RGB
	static char BackImgPath_Copy[2][MAX_PATH];//�p�X

	static int BackColor_Copy[2];
	static int BackImg_Copy[2];


	//�N���b�N����̂ݏ������i�Ⴄ���[�h�ł��g�p���邩��static�Ƃ���*EditorSettingsFlag_p == 1�̂Ƃ��ɏ���������j
	//������///////////////////////////////
	if (*EditorSettingsFlag_p == 1) {
		*EditorSettingsFlag_p = 2;
		if (Area_Kosuu > Area_Max) Area_Kosuu = Area_Max;//�G���A�̌����ő吔���傫����Ό����ő吔�ɕς���i�ő吔�𒴂��Ȃ��悤�ɂ��邽�߁j
		for (int AreaN = 0; AreaN < Area_Kosuu; AreaN++) {
			for (int i = 0; i < 3; i++) {
				BackColorRGB_Copy[AreaN][i] = BackColorRGB_h[AreaN][i];//RGB
			}
			strcpy(BackImgPath_Copy[AreaN], BackImgPath_h[AreaN]);//�p�X

			BackColor_Copy[AreaN] = DisplayArea_p[AreaN].BackColor;
			BackImg_Copy[AreaN] = DisplayArea_p[AreaN].BackImg;
		}
		//���v���p�e�B�G���A
		PropertyArea.Width = 410;
		PropertyArea.Height = 42 * Area_Kosuu + 44;//42(�Q�s)*�G���A�̌� + 24(�ۑ��{�^������)+10(��p�f�B���O)+10(���p�f�B���O)=128
		PropertyArea.Location[0] = (WindowWidth - PropertyArea.Width) / 2;
		PropertyArea.Location[1] = (WindowHeight - PropertyArea.Height) / 2;
		for (int i = 0; i < 4; i++) PropertyArea.Padding[i] = 10;
		PropertyArea.BackColor = GetColor(112, 128, 144);//NULL;// 
		PropertyArea.Active = 1;
		//���v���p�e�B�{�^���t�H�[��
		PropertyBtnForm.BorderThickness = 1;
		PropertyBtnForm.BorderColor = GetColor(0, 102, 102);//255, 51, 51
		PropertyBtnForm.WaitingColor = GetColor(204, 204, 204);
		PropertyBtnForm.CursorColor = GetColor(255, 255, 204);
		PropertyBtnForm.PushedColor = GetColor(153, 0, 153);

		//���v���p�e�B�̃p�����[�^�ύX�{�^��
		for (int AreaN = 0; AreaN < Area_Kosuu; AreaN++) {
			for (int b = 0; b < PropertyBtn_Kosuu; b++) {
				PropertyBtn[AreaN][b].ParentArea_p = &PropertyArea;
				PropertyBtn[AreaN][b].ButtonForm_p = &PropertyBtnForm;
				PropertyBtn[AreaN][b].Padding[0] = 6; PropertyBtn[AreaN][b].Padding[1] = 5; PropertyBtn[AreaN][b].Padding[2] = 6; PropertyBtn[AreaN][b].Padding[3] = 5;//
				PropertyBtn[AreaN][b].Width = SystemFontSize;
				PropertyBtn[AreaN][b].Height = SystemFontSize / 2;
				PropertyBtn[AreaN][b].Active = 1;//�s�v�H
			}
			//�p�����[�^�ύX�{�^���̈ʒu
			int line = SystemFontSize * 3 * AreaN;
			int Width = GetDrawStringWidth("R()", strlen("R()")) + SystemFontSize * 2;

			//BackColorR
			int BtnNo = 0;//Up0
			PropertyBtn[AreaN][BtnNo].Location[0] = 80 * 1 + Width;
			PropertyBtn[AreaN][BtnNo].Location[1] = line;
			BtnNo++;//Down1
			PropertyBtn[AreaN][BtnNo].Location[0] = -222222;
			PropertyBtn[AreaN][BtnNo].Location[1] = -111111;
			//BackColorG
			BtnNo++;//Up2
			PropertyBtn[AreaN][BtnNo].Location[0] = 80 * 2 + Width;
			PropertyBtn[AreaN][BtnNo].Location[1] = line;
			BtnNo++;//Down3
			PropertyBtn[AreaN][BtnNo].Location[0] = -222222;
			PropertyBtn[AreaN][BtnNo].Location[1] = -111111;
			//BackColorB
			BtnNo++;//Up4
			PropertyBtn[AreaN][BtnNo].Location[0] = 80 * 3 + Width;
			PropertyBtn[AreaN][BtnNo].Location[1] = line;
			BtnNo++;//Down5, 11
			PropertyBtn[AreaN][BtnNo].Location[0] = -222222;
			PropertyBtn[AreaN][BtnNo].Location[1] = -111111;
		}
		//���ۑ��E�L�����Z���{�^���t�H�[��
		SaveUnSaveBtnForm.Margin[0] = 1; SaveUnSaveBtnForm.Margin[2] = 1;
		SaveUnSaveBtnForm.BorderThickness = 1;
		SaveUnSaveBtnForm.BorderColor = GetColor(0, 102, 102);//255, 51, 51
		SaveUnSaveBtnForm.WaitingColor = GetColor(204, 204, 204);
		SaveUnSaveBtnForm.CursorColor = GetColor(255, 255, 204);
		SaveUnSaveBtnForm.PushedColor = GetColor(153, 0, 153);

		//���ۑ��E�L�����Z���{�^��
		for (int b = 0; b < SaveUnSaveBtn_Kosuu; b++) {
			SaveUnSaveBtn[b].ParentArea_p = &PropertyArea;
			SaveUnSaveBtn[b].ButtonForm_p = &SaveUnSaveBtnForm;
			SaveUnSaveBtn[b].Padding[0] = -1; SaveUnSaveBtn[b].Padding[1] = -1; SaveUnSaveBtn[b].Padding[2] = 6; SaveUnSaveBtn[b].Padding[3] = 5;//
			SaveUnSaveBtn[b].Width = 100;
			SaveUnSaveBtn[b].Height = 24;
			SaveUnSaveBtn[b].Active = 1;//�s�v�H
		}
		int SaveUnSaveBtnNo = 0;
		//�p�����[�^�ύX�{�^���̈ʒu
		int L4 = SystemFontSize * 3 * Area_Kosuu;

		//�ۑ�
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[0] = 390 - 200 - 3;//390=�v���p�e�B�G���A�̏����o���͈͂̉E�[�@200=�ۑ��E�L�����Z���{�^���̕��@3���ۑ��̃}�[�W��0�{�ۑ��̃}�[�W��2�{�L�����Z���̃}�[�W��0
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[1] = L4;
		strcpy(SaveUnSaveBtn[SaveUnSaveBtnNo].Title, "�ۑ�����");
		//�L�����Z��
		SaveUnSaveBtnNo++;
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[0] = -111111;
		SaveUnSaveBtn[SaveUnSaveBtnNo].Location[1] = -222222;
		strcpy(SaveUnSaveBtn[SaveUnSaveBtnNo].Title, "�L�����Z��");

	}
	//�\��///////////////////////////////
	//�v���p�e�B�G���A
	ShowArea(&PropertyArea, 1);//��2�����̓v���p�e�B�G���A�̌�������P
	for (int AreaN = 0; AreaN < Area_Kosuu; AreaN++) {
		//�p�����[�^�ύX�{�^��
		int PropertyBtn_PushType = 0; int PropertyBtn_Prev = -2; int PropertyBtn_Next = -2;
		int PropertyBtnClicked;
		int ClickedNo = -1;//�����ꂽ�{�^���ԍ�
		PropertyBtnClicked = ShowButton(PropertyBtn[AreaN], PropertyBtn_Kosuu, &ClickedNo, PropertyBtn_PushType, PropertyBtn_Prev, PropertyBtn_Next);
	// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

		//�w�i�F�@�������u�Ԃ܂��͒�������
		if (PropertyBtnClicked == 1 || PropertyBtnClicked > 20) {
			if (0 <= ClickedNo && ClickedNo <= 5) {
				if (ClickedNo == 0 && BackColorRGB_h[AreaN][0] < 255) BackColorRGB_h[AreaN][0] += 1;
				else if (ClickedNo == 1 && BackColorRGB_h[AreaN][0] > -1) BackColorRGB_h[AreaN][0] -= 1;
				else if (ClickedNo == 2 && BackColorRGB_h[AreaN][1] < 255) BackColorRGB_h[AreaN][1] += 1;
				else if (ClickedNo == 3 && BackColorRGB_h[AreaN][1] > 0) BackColorRGB_h[AreaN][1] -= 1;
				else if (ClickedNo == 4 && BackColorRGB_h[AreaN][2] < 255) BackColorRGB_h[AreaN][2] += 1;
				else if (ClickedNo == 5 && BackColorRGB_h[AreaN][2] > 0) BackColorRGB_h[AreaN][2] -= 1;
				if (BackColorRGB_h[AreaN][0] >= 0) DisplayArea_p[AreaN].BackColor = GetColor(BackColorRGB_h[AreaN][0], BackColorRGB_h[AreaN][1], BackColorRGB_h[AreaN][2]);
				else DisplayArea_p[AreaN].BackColor = NULL;
			}
		}
		//�e�s�̏����o��
		int line = SystemFontSize * 3 * AreaN;//�w�i�F�̍s�̈ʒu
		DrawFormatString(PropertyArea.Nest[0] + 80 * 0, PropertyArea.Nest[1] + line, black, "�w�i�F%d", AreaN + 1);
		if (BackColorRGB_h[AreaN][0] < 0) DrawFormatString(PropertyArea.Nest[0] + 80 * 1, PropertyArea.Nest[1] + line, black, "���F");
		else DrawFormatString(PropertyArea.Nest[0] + 80 * 1, PropertyArea.Nest[1] + line, black, "R(%d)", BackColorRGB_h[AreaN][0]);
		DrawFormatString(PropertyArea.Nest[0] + 80 * 2, PropertyArea.Nest[1] + line, black, "G(%d)", BackColorRGB_h[AreaN][1]);
		DrawFormatString(PropertyArea.Nest[0] + 80 * 3, PropertyArea.Nest[1] + line, black, "B(%d)", BackColorRGB_h[AreaN][2]);
	
		//�w�i�p�X
		static int SpotColor = GetColor(255, 255, 204);
		line = SystemFontSize * (3 * AreaN + 1.5);//�w�i�摜�̍s�̈ʒu
		static int BackImgPath_x1 = PropertyArea.Nest[0] + GetDrawStringWidth("�w�i�摜8", strlen("�w�i�摜8"));
		int BackImgPath_y1 = PropertyArea.Nest[1] + line;
		int BackImgPath_Len = GetDrawStringWidth(BackImgPath_h[AreaN], strlen(BackImgPath_h[AreaN]));
		if (BackImgPath_x1 < ActiveMath::MouseX && ActiveMath::MouseX < BackImgPath_x1 + BackImgPath_Len + SystemFontSize && BackImgPath_y1 < ActiveMath::MouseY && ActiveMath::MouseY < BackImgPath_y1 + SystemFontSize) {
			//�X�|�b�g
			DrawBox(BackImgPath_x1, BackImgPath_y1, BackImgPath_x1 + BackImgPath_Len + SystemFontSize, BackImgPath_y1 + SystemFontSize, SpotColor, true);
			//�����ꂽ�Ƃ�
			if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
				char ImgFileTitle[MAX_PATH];
				char Dir[MAX_PATH];
				//�_�C�A���O����t�@�C�������擾
				strcpy(Dir, AppDir);
				strcat(Dir, "\\System\\BackImg");
				if (GetImgFileName(Dir, BackImgPath_h[AreaN], ImgFileTitle, MAX_PATH, MAX_PATH, 0)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
					if (BackImgPath_h[AreaN][0] != '\0') DisplayArea_p[AreaN].BackImg = LoadGraph(BackImgPath_h[AreaN]);
					//�t�@�C���擾�ɐ���������Dir����݂��t�@�C���̑��΃p�X���擾
					PathRelativePathTo(BackImgPath_h[AreaN], AppDir, FILE_ATTRIBUTE_DIRECTORY, BackImgPath_h[AreaN], FILE_ATTRIBUTE_ARCHIVE);
				}
				//�_�C�A���O�̃L�����Z���ŁC�p�X�ƃn���h�����폜
				else {
					DisplayArea_p[AreaN].BackImg = -1;
				}
			}
		}
		DrawFormatString(PropertyArea.Nest[0], PropertyArea.Nest[1] + line, black, "�w�i�摜%d(%s)", AreaN + 1, BackImgPath_h[AreaN]);

	}
	
	//�ۑ��E�L�����Z���{�^��
	int PropertyOkCancelBtn_PushType = 0; int PropertyOkCancelBtn_Prev = -2; int PropertyOkCancelBtn_Next = -2;
	int PropertyOkCancelBtnClicked;
	int PropertyOkCancelBtnClickedNo = -1;//�����ꂽ�{�^���ԍ�
	PropertyOkCancelBtnClicked = ShowButton(SaveUnSaveBtn, SaveUnSaveBtn_Kosuu, &PropertyOkCancelBtnClickedNo, PropertyOkCancelBtn_PushType, PropertyOkCancelBtn_Prev, PropertyOkCancelBtn_Next);
	// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
	//�{�^�����������u��
	if (PropertyOkCancelBtnClicked == 1) {
		//�ۑ��{�^���i�e���[�h�ɖ߂��Ă��炻�ꂼ��̎���ɍ��킹�ĕۑ��j
		if (PropertyOkCancelBtnClickedNo == 0) {
			//�ݒ�G���A�̒�~
			*EditorSettingsFlag_p = 0;
			return 1;
		}
		//�L�����Z���{�^��
		else if (PropertyOkCancelBtnClickedNo == 1) {
			for (int AreaN = 0; AreaN < Area_Kosuu; AreaN++) {
				//�w�i�F��RGB�C�w�i�F�̃n���h���C�w�i�p�X�C�w�i�p�X�̃n���h�������ɖ߂�
				for (int i = 0; i < 3; i++) {
					BackColorRGB_h[AreaN][i] = BackColorRGB_Copy[AreaN][i];
				}
				strcpy(BackImgPath_h[AreaN], BackImgPath_Copy[AreaN]);
				DisplayArea_p[AreaN].BackColor = BackColor_Copy[AreaN];
				DisplayArea_p[AreaN].BackImg = BackImg_Copy[AreaN];
			}
			//�ݒ�G���A�̒�~
			*EditorSettingsFlag_p = 0;
			return -1;
		}
	}
	return 0;
}


//�ڍוҏW, *MsgBoxCtrl_p�͏�����ԁB*MsgBoxCtrl_p��*MsgBoxForm_p�Ɗ֘A�Â��Ă���B
int MessagePreviewMode(struct MsgBoxCtrl *MsgBoxCtrl_p, int MsgBoxCtrl_Kosuu, int MsgBoxCrlNumber, struct MsgBoxForm *MsgBoxForm_p, struct MsgBoxForm_RGB_SoundPath *MsgBoxForm_RGB_SoundPath_p, int MsgBoxForm_Kosuu, int *MsgBoxFormNumber_h,
	char *Message_h, int MsgSize, char *DisplayArea_Preview_FilePath_h, struct AREACONTROL *DisplayArea_p, int(*BorderColorRGB_h)[3], int(*BackColorRGB_h)[3], char(*BackImgPath_h)[MAX_PATH], int Area_Kosuu, int AreaNumber,
	char *FilePath_h, char *FileTitle_h, struct Kadai *mondai_p, int *EditorMode_p, int *ExitModeFlag_p
) {
	//�������ScreenFlip����C�e���[�h�̂O�t���[����ScreenFlip�܂ł̑҂����ԁi�t�@�C���̃��[�h�Ȃǁj�ɕ\��������́�
	//�i���ꂪ�Ȃ��Ɗe���[�h���甲���Ă����Ƃ��ɁC�Ȃ���ScreenFlip����Ă��ēr���������o����Ă��܂��j
	const static char Msg[] = "���҂���������";
	const static int MsgWidth = GetDrawStringWidth(Msg, strlen(Msg));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);
	DrawString((WindowWidth - MsgWidth) / 2, (WindowHeight - SystemFontSize) / 2, Msg, white);
	ScreenFlip();

	//���e���[�h�̂O�t���[����ScreenFlip�ŕ\��������́�
	DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);

	int InputHandleMath = MakeKeyInput(100, TRUE, FALSE, FALSE);//�V�����L�[���̓f�[�^�̍쐬  ESC�L�[�ɂ��L�����Z���@�\�̗L��TRUE�@���p�����݂̂̓���FALSE�@���l�����݂̂̓���FALSE
	//���p�b�h�}�l�[�W���[�ƃC���f�b�N�X�{�^���̃A�N�e�B�u�̃��Z�b�g
	struct PadManager PadManager;
	//�p�b�h�̏������i�I�����Ă���C���f�b�N�X�{�^����0�ԂɃ��Z�b�g�j
	for (int i = 0; i < EditorIndexKosuu; i++) EditorIndex[i].Active = 1;
	EditorIndex[0].Active = 2;
	//���c�[���o�[
	static struct AREACONTROL Toolbar[2] = { 0 };
	for (int AreaN = 0; AreaN < 2; AreaN++) {
		for (int i = 0; i < 4; i++) Toolbar[AreaN].Padding[i] = 1;
		Toolbar[AreaN].BackColor = GetColor(51, 102, 153);//204, 204, 204 R:51 G:102 B:153//102, 153, 204
		Toolbar[AreaN].Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
		Toolbar[AreaN].Location[0] = -111111;
		/////////
	}
	Toolbar[0].Width = 208;//140+0+0+
	Toolbar[0].Height = 28;//
	////
	Toolbar[1].Width = 416;// jjj 276;//
	Toolbar[1].Height = 28;

	//���X�e�[�^�X�o�[
	static struct AREACONTROL Statusbar = { 0 };
	Statusbar.Width = WindowWidth;
	Statusbar.Height = 24;//������v���̂���Location[1]����ɏ�����
	Statusbar.Location[1] = WindowHeight - Statusbar.Height;
	for (int i = 0; i < 4; i++) Statusbar.Padding[i] = 5;
	Statusbar.BackColor = GetColor(240, 240, 240);
	Statusbar.Active = 1;

	//���{�^��A�t�H�[��
	static struct BUTTONFORM ToolAForm = { 0 };
	for (int i = 0; i < 4; i++) ToolAForm.Margin[i] = 1;
	ToolAForm.CursorColor = GetColor(255, 255, 204);

	//���c�[���{�^��A
	const int ToolAKosuu = 3;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
	static struct BUTTONCONTROL ToolA[ToolAKosuu] = { 0 };
	strcpy(ToolA[0].Title, "�t�@�C��");
	strcpy(ToolA[1].Title, "�J�X�^�}�C�Y");
	strcpy(ToolA[2].Title, "�ݒ�");

	for (int BtnN = 0; BtnN < ToolAKosuu; BtnN++) {
		ToolA[BtnN].ParentArea_p = &Toolbar[0];
		ToolA[BtnN].Location[0] = -111111;
		for (int i = 0; i < 4; i++) ToolA[BtnN].Padding[i] = 5;
		ToolA[BtnN].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolA[BtnN].ButtonForm_p = &ToolAForm;
	}

	//���c�[���{�^���t�H�[��
	static struct BUTTONFORM ToolForm = { 0 };
	for (int i = 0; i < 4; i++) ToolForm.Margin[i] = 1;
	ToolForm.CursorColor = GetColor(255, 255, 204);

	//���c�[���{�^��
	SetCurrentDirectory(AppDir);
	const int ToolKosuu = 9;
	static struct BUTTONCONTROL Tool[ToolKosuu] = { 0 };
	int ToolN = 0;
	strcpy(Tool[ToolN].String, "�z�[����ʂɖ߂�");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\home24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\home24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�߂�");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\back24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\back24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�V�K�쐬");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\new24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\new24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�t�@�C�����J��");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\open24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\open24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�㏑���ۑ�");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\save24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\save24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�t�H�[���E�R���g���[��");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\view24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\view24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�Đ�");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\start24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\start24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "�ҏW");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\edit24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\edit24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}
	ToolN++;
	strcpy(Tool[ToolN].String, "ScrollMsg�{�^��");
	if (Tool[ToolN].WaitingImg == -1) {
		Tool[ToolN].WaitingImg = LoadGraph(".\\System\\Fixed\\push24.png");
		Tool[ToolN].CursorImg = LoadGraph(".\\System\\Fixed\\push24b.png");
		Tool[ToolN].PushedImg = Tool[ToolN].CursorImg;
	}

	/*�_�C�A���摜�ƃ^�C�g����\������Ƃ��i���͎g���Ă��Ȃ����C���Ŏg����悤�Ɍ��{�Ƃ��Ďc���Ă����j
	strcpy(Tool[6].Title, "�X�N���[��");
	if (Tool[6].DialImg == -1) {
		Tool[6].DialImg = LoadGraph(".\\System\\Fixed\\scroll24.png");
	}
	*/
	for (int i = 0; i < ToolKosuu; i++) {
		Tool[i].ParentArea_p = &Toolbar[1];
		Tool[i].ButtonForm_p = &ToolForm;					   ////////
		if (i > 0) Tool[i].Location[0] = -111111;
		Tool[i].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
	}					   ////////
	


	int EditorSettingsFlag = 0;
	//���f�B�X�v���C�G���A�i�e���[�h�Ń��[�h�������̂ɒǉ��Ŏw��j
	DisplayArea_p[AreaNumber].Location[1] = 84;//28+56
	DisplayArea_p[AreaNumber].Width = WindowWidth;
	DisplayArea_p[AreaNumber].Height = 690;//WindowHeight(798)-28-56-24
	DisplayArea_p[AreaNumber].Active = 1;

////////////////////////



		//�v���_�E�����X�g
	int ListStrLen;//�^�C�g���̕�����
	int ListStrWidth;//�^�C�g���̕�
	const int list_BackColor = GetColor(204, 204, 153);
	const int list_BorderColor = GetColor(153, 153, 102);
	const int List_CursorColor = GetColor(255, 255, 204);
	//���t�@�C���̃v���_�E�����X�g
	const int List0RowKosuu = 7;
	ListStrWidth = GetDrawStringWidth("�A�v���P�[�V�����̏I��", strlen("�A�v���P�[�V�����̏I��"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List0 = { 0 };
	List0.ParentButton_p = &ToolA[0];//�t�@�C���{�^��
	List0.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List0.Padding[i] = 2;
	List0.BackColor = list_BackColor;
	List0.BorderColor = list_BorderColor;
	List0.CursorColor = List_CursorColor;

	List0.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List0.RowKosuu = List0RowKosuu;
	for (int i = 0; i < 4; i++) List0.RowPadding[i] = 5;
	List0.RowWidth = ListStrWidth + List0.RowPadding[0] + List0.RowPadding[2];
	List0.RowHeight = SystemFontSize + List0.RowPadding[1] + List0.RowPadding[3];
	/////////
	List0.Width = List0.RowWidth + List0.Padding[0] + List0.Padding[2] + List0.BorderThickness * 2;
	List0.Height = List0.RowHeight * List0.RowKosuu + List0.Padding[1] + List0.Padding[3] + List0.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List0Row[List0RowKosuu] = { 0 };
	for (int i = 0; i < List0RowKosuu; i++) List0Row[i].List_p = &List0;//������
	strcpy(List0Row[0].Title, "�V�K�쐬");
	strcpy(List0Row[1].Title, "�t�@�C�����J��");
	strcpy(List0Row[2].Title, "�㏑���ۑ�");
	strcpy(List0Row[3].Title, "���O��t���ĕۑ�");
	strcpy(List0Row[4].Title, "�߂�");
	strcpy(List0Row[5].Title, "�z�[����ʂɖ߂�");
	strcpy(List0Row[6].Title, "�A�v���P�[�V�����̏I��");

	//���J�X�^�}�C�Y�̃v���_�E�����X�g
	const int List1RowKosuu = 6;
	ListStrWidth = GetDrawStringWidth("�t�H�[���ƃR���g���[���̕\��/��\��", strlen("�t�H�[���ƃR���g���[���̕\��/��\��"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List1 = { 0 };
	List1.ParentButton_p = &ToolA[1];//�t�@�C���{�^��
	List1.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List1.Padding[i] = 2;
	List1.BackColor = list_BackColor;
	List1.BorderColor = list_BorderColor;
	List1.CursorColor = List_CursorColor;
	List1.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List1.RowKosuu = List1RowKosuu;
	for (int i = 0; i < 4; i++) List1.RowPadding[i] = 5;
	List1.RowWidth = ListStrWidth + List1.RowPadding[0] + List1.RowPadding[2];
	List1.RowHeight = SystemFontSize + List1.RowPadding[1] + List1.RowPadding[3];
	/////////
	List1.Width = List1.RowWidth + List1.Padding[0] + List1.Padding[2] + List1.BorderThickness * 2;
	List1.Height = List1.RowHeight * List1.RowKosuu + List1.Padding[1] + List1.Padding[3] + List1.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List1Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List1RowKosuu; i++) List1Row[i].List_p = &List1;//������
	strcpy(List1Row[0].Title, "�X�^�C���̕ۑ�");
	strcpy(List1Row[1].Title, "�t�H���g�Z�b�g�̕ύX");
	strcpy(List1Row[2].Title, "�t�H���g�摜�Z�b�g�̕ύX");
	strcpy(List1Row[3].Title, "�^�O�Z�b�g�̕ύX");
	strcpy(List1Row[4].Title, "�W���C�p�b�h�̊��蓖�Ă̕ύX");
	strcpy(List1Row[5].Title, "�t�H�[���ƃR���g���[���̕\��/��\��");


	//���ݒ�̃v���_�E�����X�g
	const int List2RowKosuu = 1;
	ListStrWidth = GetDrawStringWidth("�G�f�B�^�[�̐ݒ�", strlen("�G�f�B�^�[�̐ݒ�"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List2 = { 0 };
	List2.ParentButton_p = &ToolA[2];//�t�@�C���{�^��
	List2.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List2.Padding[i] = 2;
	List2.BackColor = list_BackColor;
	List2.BorderColor = list_BorderColor;
	List2.CursorColor = List_CursorColor;
	List2.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List2.RowKosuu = List2RowKosuu;
	for (int i = 0; i < 4; i++) List2.RowPadding[i] = 5;
	List2.RowWidth = ListStrWidth + List2.RowPadding[0] + List2.RowPadding[2];
	List2.RowHeight = SystemFontSize + List2.RowPadding[1] + List2.RowPadding[3];
	/////////
	List2.Width = List2.RowWidth + List2.Padding[0] + List2.Padding[2] + List2.BorderThickness * 2;
	List2.Height = List2.RowHeight * List2.RowKosuu + List2.Padding[1] + List2.Padding[3] + List2.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List2Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List2RowKosuu; i++) List2Row[i].List_p = &List2;//������
	strcpy(List2Row[0].Title, "�G�f�B�^�[�̐ݒ�");



	//////////////////////////////





	//���v���p�e�B�G���A
	static struct AREACONTROL PropertyArea = { 0 };
	for (int i = 0; i < 4; i++) PropertyArea.Padding[i] = 10;
	PropertyArea.BackColor = GetColor(153, 153, 153);// = GetColor(112, 128, 144);//NULL;// 
	PropertyArea.BackTransparency = 50;
	PropertyArea.Active = 1;
	//���v���p�e�B�{�^���t�H�[��
	static struct BUTTONFORM PropertyBtnForm = { 0 };
	PropertyBtnForm.BorderThickness = 1;
	PropertyBtnForm.BorderColor = GetColor(0, 102, 102);//255, 51, 51
	PropertyBtnForm.WaitingColor = GetColor(204, 204, 204);
	PropertyBtnForm.CursorColor = GetColor(255, 255, 204);
	PropertyBtnForm.PushedColor = GetColor(153, 0, 153);


	//���v���p�e�B�m��{�^��
	int L1 = SystemFontSize * 0;
	int L2 = SystemFontSize * 1.5;
	int L3 = SystemFontSize * 3;
	int L4 = SystemFontSize * 4.5;
	int L5 = SystemFontSize * 6;
	int L6 = SystemFontSize * 7.5;
	int L7 = SystemFontSize * 9;
	int L8 = SystemFontSize * 10.5;
	int L9 = SystemFontSize * 12;
	int L10 = SystemFontSize * 13.5;
	int L11 = SystemFontSize * 15;
	int L12 = SystemFontSize * 16.5;
	int L13 = SystemFontSize * 18;
	int L14 = SystemFontSize * 19.5;
	int L15 = SystemFontSize * 21;
	int L16 = SystemFontSize * 22.5;
	int L17 = SystemFontSize * 24;
	int L18 = SystemFontSize * 25.5;
	int L19 = SystemFontSize * 27;
	int L20 = SystemFontSize * 28.5;
	int L21 = SystemFontSize * 30;

	const int PropertyBtn_Kosuu = 86;
	static struct BUTTONCONTROL PropertyBtn[PropertyBtn_Kosuu] = { 0 };
	for (int b = 0; b < PropertyBtn_Kosuu; b++) {
		PropertyBtn[b].ParentArea_p = &PropertyArea;
		PropertyBtn[b].ButtonForm_p = &PropertyBtnForm;

		PropertyBtn[b].Padding[0] = 6; PropertyBtn[b].Padding[1] = 5; PropertyBtn[b].Padding[2] = 6; PropertyBtn[b].Padding[3] = 5;//
		PropertyBtn[b].Width = SystemFontSize;
		PropertyBtn[b].Height = SystemFontSize / 2;
		PropertyBtn[b].Active = 1;//�s�v�H

	}

	int Width1 = GetDrawStringWidth("��(000)   ", strlen("��(000)   "));
	//Margin[0]
	int BtnNo = 0;
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L2;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Margin[1]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L2;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Margin[2]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L2;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Margin[3]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 4 + Width1;
	PropertyBtn[BtnNo].Location[1] = L2;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//Padding[0]
	BtnNo++;//Up10
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L3;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Padding[1]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L3;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Padding[2]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L3;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Padding[3]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 4 + Width1;
	PropertyBtn[BtnNo].Location[1] = L3;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//BorderColorR
	BtnNo++;//Up26
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L4;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//BorderColorG
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L4;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//BorderColorB
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L4;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	int Width2 = GetDrawStringWidth("�����x(50%) ", strlen("�����x(50%) "));
	//BorderThickness
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L5;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//BorderType���^�C�v��
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L5;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//BackColorR
	BtnNo++;//Up18
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L6;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//BackColorG
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L6;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//BackColorB
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L6;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//BackGroundTransparency
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 4 + Width2;
	PropertyBtn[BtnNo].Location[1] = L6;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;




	//ActiveTagColorR
	BtnNo++;//Up34
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L7;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//ActiveTagColorG
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L7;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//ActiveTagColorB
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L7;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//ActiveTagColorTransparency
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 4 + Width2;
	PropertyBtn[BtnNo].Location[1] = L7;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;


	//ActiveMathColorR
	BtnNo++;//Up42
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L8;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//ActiveMathColorG
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L8;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//ActiveMathColorB
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L8;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//ActiveMathColorTransparency
	BtnNo++;//Up48
	PropertyBtn[BtnNo].Location[0] = 120 * 4 + Width2;
	PropertyBtn[BtnNo].Location[1] = L8;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//FontColorR
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L9;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//FontColorG
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 2 + Width1;
	PropertyBtn[BtnNo].Location[1] = L9;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//FontColorB
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 * 3 + Width1;
	PropertyBtn[BtnNo].Location[1] = L9;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	int Width3 = GetDrawStringWidth("�_��(120��/��) ", strlen("�_��(120��/��) "));
	//Leading
	BtnNo++;//Up56
	PropertyBtn[BtnNo].Location[0] = 120 + Width3;
	PropertyBtn[BtnNo].Location[1] = L10;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	int Width4 = GetDrawStringWidth("�X�N���[��(000px/�b) ", strlen("�X�N���[��(000px/�b) "));
	//MaxLine
	BtnNo++;//Up2
	PropertyBtn[BtnNo].Location[0] = 480 + Width2;
	PropertyBtn[BtnNo].Location[1] = L10;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//BlinkSpeed
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 + Width3;
	PropertyBtn[BtnNo].Location[1] = L11;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//OutputSpeed
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 384;
	PropertyBtn[BtnNo].Location[1] = L11;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//ScrollSpeed
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 420 + Width4;
	PropertyBtn[BtnNo].Location[1] = L11;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;

	//Value5 Option�̉�����5����
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 420 + Width4;
	PropertyBtn[BtnNo].Location[1] = L12;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Value4 Option�̉�����4����
	int Width8 = GetDrawStringWidth("�܂�Ԃ�(1�����E����) ", strlen("�܂�Ԃ�(1�����E����) "));
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 + Width8;
	PropertyBtn[BtnNo].Location[1] = L13;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Value3 Option�̉�����3����
	int Width5 = GetDrawStringWidth("��~(4������) ", strlen("��~(4������) "));
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 420 + Width4;
	PropertyBtn[BtnNo].Location[1] = L13;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Value2 Option�̉�����2����
	int Width6 = GetDrawStringWidth("�J�n(4�{�b�N�X��) ", strlen("�J�n(4�{�b�N�X��) "));
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 + Width8;
	PropertyBtn[BtnNo].Location[1] = L14;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	int Width7 = GetDrawStringWidth("����(5�W���C�p�b�h) ", strlen("����(5�W���C�p�b�h) "));
	//Value1 Option�̉�����1����
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 420 + Width4;
	PropertyBtn[BtnNo].Location[1] = L14;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	///////////////////////////
	//Ctrl MsgBoxFormNumber
	BtnNo++;//Up74
	PropertyBtn[BtnNo].Location[0] = 120 + GetDrawStringWidth("MsgFormNo()", strlen("MsgFormNo()")) + SystemFontSize * 1;
	PropertyBtn[BtnNo].Location[1] = L19;
	BtnNo++;//Down75
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Ctrl  Location[0]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 120 + Width1;
	PropertyBtn[BtnNo].Location[1] = L20;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Ctrl  Location[1]
	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 240 + Width1;
	PropertyBtn[BtnNo].Location[1] = L20;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Ctrl  Width

	BtnNo++;//Up
	PropertyBtn[BtnNo].Location[0] = 360 + Width1;
	PropertyBtn[BtnNo].Location[1] = L20;
	BtnNo++;//Down
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//Ctrl  Height
	BtnNo++;//Up86
	PropertyBtn[BtnNo].Location[0] = 480 + Width1;
	PropertyBtn[BtnNo].Location[1] = L20;
	BtnNo++;//Down87
	PropertyBtn[BtnNo].Location[0] = -222222;
	PropertyBtn[BtnNo].Location[1] = -111111;
	//0�Ԃ����邩��S88�̃{�^��
	   	 
	//���[�h�̃e�L�X�g�̍X�V
	char AppMode_text[MAX_PATH];
	strcpy(AppMode_text, ApplicationTitle);//�A�v���P�[�V����������
	if (*EditorMode_p == 0) strcat(AppMode_text, " - ���b�Z�[�W�ҏW���[�h - ");//
	else if (*EditorMode_p == 1) strcat(AppMode_text, " - ���ҏW���[�h - ");
	else strcat(AppMode_text, " - �p�b�h�r���[�A - ");//if (*EditorMode_p == 2) 
	//�^�C�g���o�[�̃e�L�X�g�̍X�V
	char Titlebar_text[MAX_PATH];
	strcpy(Titlebar_text, AppMode_text);//�t�@�C������A��
	strcat(Titlebar_text, FileTitle_h);
	SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������

	//�����b�Z�[�W�t�H�[���ԍ��̎Z�o///////////////
	int MsgFormNo = MsgBoxFormNumber_h[MsgBoxCrlNumber];

	//�t�H�[���̒�����Option�̊e�ʂ������o���Ă���
	int Value1 = MsgBoxForm_p[MsgFormNo].Option % 10;
	int Value2 = MsgBoxForm_p[MsgFormNo].Option % 100 / 10;
	int Value3 = MsgBoxForm_p[MsgFormNo].Option % 1000 / 100;
	int Value4 = MsgBoxForm_p[MsgFormNo].Option % 10000 / 1000;
	int Value5 = MsgBoxForm_p[MsgFormNo].Option % 100000 / 10000;
	int OutputSpeed_Copy = MsgBoxForm_p[MsgFormNo].OutputSpeed;

	int MessageSound_Copy = MsgBoxForm_p[MsgFormNo].MessageSound;
	int BackDelSound_Copy = MsgBoxForm_p[MsgFormNo].BackDelSound;
	int ConfirmSound_Copy = MsgBoxForm_p[MsgFormNo].ConfirmSound;

	//�J�����g�f�B���N�g���̎w��
	SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��

	int MessageSound_edit = LoadSoundMem(".\\System\\Fixed\\swing1.mp3");
	int ConfirmSound_edit = LoadSoundMem(".\\System\\Fixed\\button67.mp3");
	int BackDelSound_edit = LoadSoundMem(".\\System\\Fixed\\swish1.mp3");

	int flag_mode = 1;//�P�F�ҏW���[�h�@�Q�F���s���[�h
	int flag_paramata = -1;//-1�F�p�����[�^��\���@�P�F�p�����[�^�\��

	//���b�Z�[�W�v���r���[�̃N���A���[�v
	int ParameterFlag = 0;
	while (!ProcessMessage()) {//!ProcessMessage()
		struct MsgBoxForm *Form_p = &MsgBoxForm_p[MsgFormNo];
		struct MsgBoxForm_RGB_SoundPath *Form_RGB_SoundPath_p = &MsgBoxForm_RGB_SoundPath_p[MsgFormNo];
		//���s�p��MsgBoxCtrl�������l�ɖ߂�
		struct MsgBoxCtrl MsgBoxCtrl = MsgBoxCtrl_p[MsgBoxCrlNumber];
		//MsgBoxCtrl�i���s���̃p�����[�^�j�F�{���̒l�C������ԁC�t�H�[���Ƃ̊֘A����@MsgBoxCtrl_p[MsgBoxCrlNumber]�i�p�����[�^�̏����l�j�F�}�X�^�[�C�{���̒l�C������ԁC�t�H�[���Ƃ̊֘A����
		MsgBoxCtrl.ParentArea_p = &DisplayArea_p[AreaNumber];//�G���A��t��������

		//�ҏW���[�h
		if (flag_mode == 1) {
			//�����b�Z�[�W�{�b�N�X�t�H�[���̒l��ҏW�p�ɏ���������
			int Value1buff = 4;//�S�F��~ MsgBoxForm[i].Option % 10;
			int Value2buff = 4;//�S�F�{�b�N�X���� MsgBoxForm[i].Option % 100 / 10;
			int Value3buff = 4;//���P���ڂ�4�����炱���͉��ł��悢 MsgBoxForm[i].Option % 1000 / 100;
			int Value4buff = Value4;// MsgBoxForm_p[MsgFormNo].Option % 10000 / 1000;//������4���ڂ͏��������Ȃ��B�O�F�܂�Ԃ��Ȃ��@�P�F�܂�Ԃ����� �@�Q�F�܂�Ԃ�����i�킩���j
			int Value5buff = 3;
			MsgBoxForm_p[MsgFormNo].Option = Value5buff * 10000 + Value4buff * 1000 + Value3buff * 100 + Value2buff * 10 + Value1buff * 1;
			MsgBoxForm_p[MsgFormNo].OutputSpeed = -2;//

			MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_edit;
			MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_edit;
			MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_edit;

			PropertyArea.Width = 605;//WindowWidth;// -PropertyArea.Location[0] - DisplayArea.Padding[0] - DisplayArea.Padding[2] - DisplayArea.BorderThickness * 2;
			PropertyArea.Height = SystemFontSize * 1.5 * 21 - 7 + 20;

			PropertyArea.Location[0] = WindowWidth - PropertyArea.Width - 10;
			PropertyArea.Location[1] = WindowHeight - PropertyArea.Height - Statusbar.Height - 10;

			//�����̏o�̓X�s�[�h�i�v���X�F�P�b�Ԃɐi�ޕ������@�}�C�i�X�F�N���b�N�ɔ�������j
						 //�܂�i�v���X�F�p�J�p�J����B�J�[�\���Ȃ��B�@0�F�p�J�p�J�Ȃ��B�J�[�\���Ȃ��B�@-1�F�p�J�p�J�Ȃ��B�N���b�N�ォ��J�[�\������B�@-2�ȉ��F�p�J�p�J�Ȃ��B������J�[�\������B�j
		}

		//���s���[�h
		else if (flag_mode == 2) {//flag_mode==2�@�v���r���[
			MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
			MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;//
			MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
			MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
			MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;

			PropertyArea.Width = 605;//WindowWidth;// -PropertyArea.Location[0] - DisplayArea.Padding[0] - DisplayArea.Padding[2] - DisplayArea.BorderThickness * 2;
			PropertyArea.Location[0] = WindowWidth - PropertyArea.Width - 10;

			PropertyArea.Height = 18 * 3 + 80;
			PropertyArea.Location[1] = WindowHeight - PropertyArea.Height - Statusbar.Height;

		}

		int nukeru = 0;//0:for���[�v�p���@1�Ffor���[�v���甲����
		///////���b�Z�[�W�v���r���[��ʂ̃��C�����[�v
		for (int frameH = 0; !nukeru && !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !MathgpUpdateMouse() && !MathgpUpdateKey() && !MathgpUpdateJoypad(); frameH++) {//�}�E�X�E�L�[�{�[�h�E�W���C�p�b�h
			//������������ҋ@
			SleepToFitFPS(FPS);
			////�@�c�[���o�[A�@////
			static int ClickedNoA = -1;//�����ꂽ�{�^���ԍ�
			//�c�[���o�[
			ShowArea(Toolbar, 2);


			//���c�[���i�v���_�E�����X�g�j
			int ToolA_PushType = 0; int ToolA_Prev = -2; int ToolA_Next = -2;
			if (ShowButton(ToolA, ToolAKosuu, &ClickedNoA, ToolA_PushType, ToolA_Prev, ToolA_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				//�t�@�C���C�܂��̓J�X�^�}�C�Y�C�܂��͐ݒ���������u��
				if (ClickedNoA >= 0) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea_p[AreaNumber].Active = 0;
					//���X�g���J���Ă��Ȃ���Ԃł̃N���b�N��
					//Mouse[MOUSE_INPUT_LEFT] = 2�́C�v���_�E�����X�g�������ɏ����Ă��܂��̂�h���i���X�g�͈̔͊O�N���b�N�ɊY�����邽�߁j�i�O�͂��߁B���̃��[�v�łɂ܂��P�ɂȂ��Ă��܂��j
					if (ClickedNoA == 0 && List0.Active != 1) { List0.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 1 && List1.Active != 1) { List1.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 2 && List2.Active != 1) { List2.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
				}

			}

			//�t�@�C���C�܂��̓J�X�^�}�C�Y�C�܂��͐ݒ������������
			else if (List0.Active == 1 || List1.Active == 1 || List2.Active == 1) {//�v���_�E����ԂŃJ�[�\�����w���{�^��������Ƃ�
				for (int i = 0; i < ToolAKosuu; i++) {
					if (ToolA[i].Active == 3) {//�J�[�\�����w���Ă���Ƃ���PulldownFlag������������
						if (i == 0) { List0.Active = 1; List1.Active = -1;  List2.Active = -1;}
						else if (i == 1) { List0.Active = -1; List1.Active = 1;  List2.Active = -1;}
						else if (i == 2) { List0.Active = -1; List1.Active = -1;  List2.Active = 1; }
						break;
					}
				}
			}

			//////�c�[���̏���
			ShowArea(Tool[0].ParentArea_p, 1);
	
			int ClickedNo = -1;//�����ꂽ�{�^���ԍ�
			int Tool_PushType = 0; int Tool_Prev = -2; int Tool_Next = -2;
			if (ShowButton(Tool, ToolKosuu, &ClickedNo, Tool_PushType, Tool_Prev, Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
			// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
				//���z�[���{�^��
				if (ClickedNo == 0) {
					*ExitModeFlag_p = 1;//�e���[�h���甲����T�C��
					*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
					return 0;//�v���r���[���[�h���甲����
				}
				//���߂�{�^��
				else if (ClickedNo == 1) {
					//���b�Z�[�W�ҏW���[�h�̂Ƃ��̓z�[���܂Ŗ߂�i�K�����b�Z�[�W�ҏW���[�h���甲����̂�*ExitModeFlag_p = 1;�͕s�v�j
					if (*EditorMode_p == 0) *EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
					//���ҏW���[�h�C�p�b�h�r���[�A�̂Ƃ��͊e���[�h�܂Ŗ߂�
					else {
						//�ҏW���̂Ƃ��{���̒l�ɖ߂�
						if (flag_mode == 1) {
							MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
							MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;//
							MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
							MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
							MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;
						}
					}
					return 0;
				}
				//���V�K�쐬�{�^��
				else if (ClickedNo == 2) {
					char GetDir[MAX_PATH];
					//�_�C�A���O����f�B���N�g���̑I��
					if (LocalDir[0] == '\0') {
						strcpy(LocalDir, AppDir);
						strcat(LocalDir, "\\OriginalFile\\MessageData");
					}
					if (GetOpenDirectoryName(LocalDir, GetDir, MAX_PATH)) {
						strcpy(FilePath_h, GetDir);//) strcpy(FileTitle_Mondai, "����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
						strcat(FilePath_h, "\\����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
						//�i�g���q�Ȃ��Ȃ̂Œ��ӁB�f�B���N�g�����Ɂu����.txt�v������΂�����J���Ă��܂����߁j

						//�f�B���N�g���̒�����Monster�Ƃ����f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCMonster���̊����̃t�@�C���͏����Ȃ��B
						SetCurrentDirectory(GetDir);
						CreateDirectory("Img", NULL);
						CreateDirectory("Sound", NULL);
						*ExitModeFlag_p = 1;//�e���[�h���甲����T�C��
						return 0;//�v���r���[���[�h���甲����
					}
				}
				//���t�@�C�����J���{�^��
				else if (ClickedNo == 3) {
					//�_�C�A���O����t�@�C�������擾
					if (LocalDir[0] == '\0') {
						strcpy(LocalDir, AppDir);
						strcat(LocalDir, "\\OriginalFile\\MessageData");
					}
					char filepath[MAX_PATH]; char filetitle[MAX_PATH];
					if (GetOpenFileNameACM(LocalDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
					//���I�����̃J�����g�f�B���N�g���̓��b�Z�[�W�t�@�C��������f�B���N�g���B�u�`\\OriginalFile\\MessageData�v�Ƃ͌���Ȃ��̂Œ��ӁB
					//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
						//�J�����t�@�C���̃��[�h�𒲂ׂ�
						ClearDrawScreen();
						switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
						case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
							strcpy(FilePath_h, filepath);//�t�@�C���p�X�̊m��
							for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
							*ExitModeFlag_p = 1;//�e���[�h���甲����T�C��
							return 0;//�v���r���[���[�h���甲����
						case -1:
							ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
							WaitKey(); break;
						default://�����icase -2�j�j
							ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
							WaitKey();
						}
					}
				}

				//���ۑ��{�^��
				else if (ClickedNo == 4) {
					
					//���b�Z�[�W�̏㏑���ۑ��i�܂��͖��O��t���ĕۑ��j
					if (mondai_p != NULL) OverwriteMondai(FilePath_h, FileTitle_h, MAX_PATH, MAX_PATH, mondai_p);////���ҏW���[�h
					else OverwriteMessage(FilePath_h, FileTitle_h, MAX_PATH, MAX_PATH, Message_h, MsgBoxCtrl.Tag[0].Post);//���b�Z�[�W�ҏW���[�h�E�p�b�h�r���[�A//tag[0].Post��TagKosuu�itagnomax�j�Ƃ��đ�p
					//�ҏW���̂Ƃ��{���̒l�ɖ߂�
					if (flag_mode == 1) {
						MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
						MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;//
						MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
						MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
						MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;
					}
					else flag_mode = 1;//�Đ����̂Ƃ��C�ҏW���[�h�ɖ߂��Ă��甲����i�ۑ�����C�Đ����n�܂�̂�h�����߁j
					//���b�Z�[�W�{�b�N�X�R���g���[���C���b�Z�[�W�{�b�N�X�t�H�[���C�X�^�C���Z�b�g�̕ۑ�
					SetCurrentDirectory(LocalDir);
					SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", MsgBoxCtrl_p, MsgBoxCtrl_Kosuu, MsgBoxFormNumber_h);
					SaveMsgBoxForm(".\\MsgBoxForm.txt", MsgBoxForm_p, MsgBoxForm_RGB_SoundPath_p, MsgBoxForm_Kosuu);
					SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
					SaveJoypadSetPath(".\\JoypadSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

					//�I�����̃J�����g�f�B���N�g����LocalDir

					//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
					strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
					strcat(Titlebar_text, FileTitle_h);//�t�@�C������A��
					SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
					//for���[�v���甲���ď�������
					nukeru = 1;//0:for���[�v�p���@1�Ffor���[�v���甲����
				}
				//���t�H�[���ƃR���g���[���̕\��/��\��
				else if (ClickedNo == 5) {
					if (flag_mode != 1) { flag_mode = 1; nukeru = 1; flag_paramata = 1;}//�ҏW���[�h�łȂ��Ȃ�C//�ҏW���[�h�ɐ؂芷���C�p�����[�^�̕\��
					else flag_paramata *= -1;//�ʏ�́C�p�����[�^�̕\���E��\��
				}
				//���Đ��{�^��
				else if (ClickedNo == 6) {
					flag_mode = 2;//�Đ����[�h�ɐ؂芷��
					nukeru = 1;//0:for���[�v�p���@1�Ffor���[�v���甲����
				}
				//���ҏW�{�^��
				else if (ClickedNo == 7) {
					flag_mode = 1;//�ҏW���[�h�ɐ؂芷��
					nukeru = 1;//0:for���[�v�p���@1�Ffor���[�v���甲����
				}
				//���X�N���[�����b�Z�[�W�i�W���C�p�b�h[1]�j�̑�p�{�^��
				else if (ClickedNo == 8) {
					ActiveMath::Joypad[Action[Act_ScrollMsg]] += 1;
				}
			}
			//���f�B�X�v���C�G���A
			ShowArea(&DisplayArea_p[AreaNumber], 1);//

			static int FontColor = GetColor(255, 0, 0);
			static int TimeFrame = 0;//�o�߃t���[���i���̑��Ɉڂ��Ă������j

			//���^�C���i�t���[�������犄��o�������ԁj
			DrawFormatString(750, 305, FontColor, "�^�C��:%7.2f�b", TimeFrame / (float)FPS);
			TimeFrame++;//�t���[���̃J�E���g
			//������
			int Time_Now = GetNowCount();
			DrawFormatString(750, 330, FontColor, "����:%10.2f�b", Time_Now / 1000.00);
			//�����σt���[�����[�g�̑���i10�̕��ϒl�j
			float AverageFPS = MeasureAverageFPS(10);
			DrawFormatString(750, 355, FontColor, "����FPS:%5.1ffps", AverageFPS);


			//�����
			if (DisplayArea_p[AreaNumber].BorderColor != NULL) {
				DrawLine(DisplayArea_p[AreaNumber].Nest[0], DisplayArea_p[AreaNumber].Nest[1] - DisplayArea_p[AreaNumber].Padding[1],
					DisplayArea_p[AreaNumber].Nest[0], DisplayArea_p[AreaNumber].Nest[3] + DisplayArea_p[AreaNumber].Padding[3], DisplayArea_p[AreaNumber].BorderColor, false);//�c��
				DrawLine(DisplayArea_p[AreaNumber].Nest[0] - DisplayArea_p[AreaNumber].Padding[0], DisplayArea_p[AreaNumber].Nest[1],
					DisplayArea_p[AreaNumber].Nest[2] + DisplayArea_p[AreaNumber].Padding[2], DisplayArea_p[AreaNumber].Nest[1], DisplayArea_p[AreaNumber].BorderColor, false);//����
			}

			////////////���̓p�b�h//////////
			int ShowMsgBoxFlag = 1;//�O�F���b�Z�[�W�{�b�N�X��\�����Ȃ��@�O�ȊO�F���b�Z�[�W�{�b�N�X��\������
			if (ShowPadM(Message_h, &MsgBoxCtrl, MsgSize, &InputHandleMath, ShowMsgBoxFlag, EditorIndex, EditorIndexKosuu, EditorButton_ph, EditorButtonKosuu, EditorBaseButton, EditorBaseButtonKosuu, EditorPadArea, &PadManager) == 1) {
				if (PadManager.InputButton_p != NULL && PadManager.InputButton_p->ButtonType == 4) {

					char Dir[MAX_PATH] = { 0 };//�f�B���N�g�����w�肷�邽�߂̕ϐ�
					int FileType = 0;//�摜�t�@�C��
					//�f�B���N�g���̌���
					if (!strcmp(PadManager.InputButton_p->PutText, "#img_lm{") || !strcmp(PadManager.InputButton_p->PutText, "#img_le{")) {//
						strcpy(Dir, LocalDir); strcat(Dir, "\\Img");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Img�ƂȂ�
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#img_am{") || !strcmp(PadManager.InputButton_p->PutText, "#img_ae{")) {//
						strcpy(Dir, Dir_AppImg);
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#img_nm{") || !strcmp(PadManager.InputButton_p->PutText, "#img_ne{")) {//
						strcpy(Dir, MsgDir);
					}

					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_l{")) {//
						strcpy(Dir, LocalDir); strcat(Dir, "\\Sound");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Sound�ƂȂ�
						FileType = 1;//�����t�@�C��
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_a{")) {//
						strcpy(Dir, Dir_AppSound);
						FileType = 1;//�����t�@�C��
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_n{")) {//
						strcpy(Dir, MsgDir);
						FileType = 1;//�����t�@�C��
					}
					//�f�B���N�g���̍쐬
					CreateDirectory(Dir, NULL);//Dir�̃f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCDir���̊����̃t�@�C���͏����Ȃ��B

					//�t�@�C���I���_�C�A���O
					char FilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
					char FileTitle[MAX_PATH];//�t�@�C�������擾����ϐ�
					if (*Dir != '\0' && GetImgFileName(Dir, FilePath, FileTitle, MAX_PATH, MAX_PATH, FileType)) {//�_�C�A���O�ɂ����t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
						char SoutaiPath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
						//�t�@�C���擾�ɐ���������t�@�C�����R�s�[���āCDir����݂��R�s�[�t�@�C���̑��΃p�X�i�܂�����̓t�@�C�����j���擾
						//�R�s�[�����t�@�C���̃t�@�C���p�X���쐬
						char CopyFilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
						strcpy(CopyFilePath, Dir);
						strcat(CopyFilePath, "\\");
						strcat(CopyFilePath, FileTitle);
						if (strcmp(FilePath, CopyFilePath)) {
							char CopyFilePath2[MAX_PATH] = { 0 };
							strcpy(CopyFilePath2, CopyFilePath);
							//�t�@�C�����R�s�[
							for (int num = 1; num < 10; num++) {//�i1�`9�܂ł̓����t�@�C�����쐬�\�j
								if (CopyFile(FilePath, CopyFilePath2, TRUE)) break;
								strcpy(CopyFilePath2, CopyFilePath);
								int point = strlen(CopyFilePath2);
								while (CopyFilePath2[point] != '.') point--;
								char kakuchoshi[5] = { 0 };
								for (int i = 0; CopyFilePath2[point + i] != '\0'; i++) kakuchoshi[i] = CopyFilePath2[point + i];
								CopyFilePath2[point] = '(';
								CopyFilePath2[point + 1] = '\0';
								char number[100];
								_itoa(num + 1, number, 10);
								strcat(CopyFilePath2, number);
								strcat(CopyFilePath2, ")");
								strcat(CopyFilePath2, kakuchoshi);
							}
							//���΃p�X���擾  ��(9)�܂ő��݂��Ă���Ȃ�R�[�h�ɂ�(10)���������܂�邪�摜�͍쐬����Ȃ��B
							PathRelativePathTo(SoutaiPath, Dir, FILE_ATTRIBUTE_DIRECTORY, CopyFilePath2, FILE_ATTRIBUTE_ARCHIVE);
						}
						else strcpy(SoutaiPath, FileTitle);//MsgDir���̉摜��I�������ꍇ�͉摜���R�s�[�����CFileTitle�����΃p�X�ƂȂ�

						////////////////////////////////////////////////////////////////////////////////////
						//�}�����镶����̍쐬
						char PutText[150];
						strcpy(PutText, PadManager.InputButton_p->PutText);
						strcat(PutText, SoutaiPath);
						strcat(PutText, "}");

						int PutTextMojisuu = strlen(PutText);//�}�����镶�������J�E���g
						int MessageMojisuu = strlen(Message_h);//���b�Z�[�W�̕��������擾

						//��������
						if (MessageMojisuu + PutTextMojisuu < MsgSize) {// return -1;//�T�C�Y�I�[�o�[���Ȃ��悤��
							int point = MsgBoxCtrl.Tag[0].PositionP;//tag[0].PositionP��*ActiveElement
							for (int i = MessageMojisuu; i >= point; i--) Message_h[i + PutTextMojisuu] = Message_h[i];//���������镶����̕��������ɂ��炷�B//�Ԃ�������
							for (int i = 0; i < PutTextMojisuu; i++) Message_h[point + i] = PutText[i]; //�A�N�e�B�u�ȗv�f�ȍ~�̔z��v�f�ɁC����������������� //�������}������i�A�N�e�B�u�ȗv�f����C���炵�ĊJ�����ʒu�܂Łj
							MsgBoxCtrl.Tag[0].PositionP += PutTextMojisuu;//tag[0].PositionP��ActiveElement
							MsgBoxCtrl.Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
						}

					}
				}
			}

			if (Message_h[0] != '\0') {
				//ShowMsgBox(Message_h, &MsgBoxCtrl);
				if (flag_mode == 1) {//�P�F�ҏW���[�h�@�Q�F���s���[�h
					ChangeImgAlign(Message_h, &MsgBoxCtrl);//�摜�̃N���b�N�ŏ㉺�ʒu�̕ύX�i�N���b�N��̃^�O�ǎ�莞�ɋL�^�����^�O���̗v�f�ԍ����g�p�j
					int Color;
					if (Value5 == 0 && Value1 != 5 && MsgBoxCtrl.Height > MsgBoxCtrl_p[MsgBoxCrlNumber].Height) Color = red;
					else if (Value5 == 0 && Value1 != 5 && MsgBoxCtrl.Height < MsgBoxCtrl_p[MsgBoxCrlNumber].Height) Color = white;
					else Color = blue;
					ShowHeightGauge(&MsgBoxCtrl, MsgBoxCtrl_p[MsgBoxCrlNumber].Height, Color);
				}
				//���p�����[�^�̕\��
				if (flag_paramata == 1) {

					if (flag_mode == 1) {//�P�F�ҏW���[�h�@�Q�F���s���[�h

						ShowArea(&PropertyArea, 1);
						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L1, "���b�Z�[�W�t�H�[��", red);

						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L2, "�}�[�W��", blue);

						DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L2, black, "��(%d)", Form_p->Margin[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L2, black, "��(%d)", Form_p->Margin[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L2, black, "�E(%d)", Form_p->Margin[2]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 4, PropertyArea.Nest[1] + L2, black, "��(%d)", Form_p->Margin[3]);

						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L3, "�]��", blue);

						DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L3, black, "��(%d)", Form_p->Padding[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L3, black, "��(%d)", Form_p->Padding[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L3, black, "�E(%d)", Form_p->Padding[2]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 4, PropertyArea.Nest[1] + L3, black, "��(%d)", Form_p->Padding[3]);

						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L4, "�g��", blue);

						if (Form_RGB_SoundPath_p->BorderColorRGB[0] == -1) DrawString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L4, "R(���F)", black);
						else DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L4, black, "R(%d)", Form_RGB_SoundPath_p->BorderColorRGB[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L4, black, "G(%d)", Form_RGB_SoundPath_p->BorderColorRGB[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L4, black, "B(%d)", Form_RGB_SoundPath_p->BorderColorRGB[2]);

						DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L5, black, "����(%d)", Form_p->BorderThickness);//���^�C�v��
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L5, black, "�^�C�v(%d)", Form_p->BorderType);

						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L6, "�w�i", blue);

						if (Form_RGB_SoundPath_p->BackColorRGB[0] == -1) DrawString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L6, "R(���F)", black);
						else DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L6, black, "R(%d)", Form_RGB_SoundPath_p->BackColorRGB[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L6, black, "G(%d)", Form_RGB_SoundPath_p->BackColorRGB[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L6, black, "B(%d)", Form_RGB_SoundPath_p->BackColorRGB[2]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 4, PropertyArea.Nest[1] + L6, black, "�����x(%d\%%)", Form_p->BackTransparency);

						DrawString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L7, "�A�N�e�B�u�ȃ^�O", blue);

						if (Form_RGB_SoundPath_p->ActiveTagColorRGB[0] == -1) DrawString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L7, "R(���F)", black);
						else DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L7, black, "R(%d)", Form_RGB_SoundPath_p->ActiveTagColorRGB[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L7, black, "G(%d)", Form_RGB_SoundPath_p->ActiveTagColorRGB[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L7, black, "B(%d)", Form_RGB_SoundPath_p->ActiveTagColorRGB[2]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 4, PropertyArea.Nest[1] + L7, black, "�����x(%d\%%)", Form_p->ActiveTagColorTransparency);

						DrawString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L8, "�A�N�e�B�u�Ȑ���", blue);

						if (Form_RGB_SoundPath_p->ActiveMathColorRGB[0] == -1) DrawString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L8, "R(���F)", black);
						else DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L8, black, "R(%d)", Form_RGB_SoundPath_p->ActiveMathColorRGB[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L8, black, "G(%d)", Form_RGB_SoundPath_p->ActiveMathColorRGB[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L8, black, "B(%d)", Form_RGB_SoundPath_p->ActiveMathColorRGB[2]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 4, PropertyArea.Nest[1] + L8, black, "�����x(%d\%%)", Form_p->ActiveMathColorTransparency);

						DrawString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L9, "����", blue);

						if (Form_p->FontColorRGB[0] == -1) DrawString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L9, "R(���F)", black);
						else DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L9, black, "R(%d)", Form_p->FontColorRGB[0]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 2, PropertyArea.Nest[1] + L9, black, "G(%d)", Form_p->FontColorRGB[1]);
						DrawFormatString(PropertyArea.Nest[0] + 120 * 3, PropertyArea.Nest[1] + L9, black, "B(%d)", Form_p->FontColorRGB[2]);

						DrawString(PropertyArea.Nest[0] + 120 * 0, PropertyArea.Nest[1] + L10, "�s", blue);

						DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L10, black, "�s��(%d%%)", Form_p->Leading);
						if (Form_p->MaxLine < 0) DrawFormatString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L10, black, "�ő�̍s��(�w��Ȃ�)");
						else DrawFormatString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L10, black, "�ő�̍s��(%d�s)", Form_p->MaxLine);

						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L11, "�X�s�[�h", blue);

						DrawFormatString(PropertyArea.Nest[0] + 120 * 1, PropertyArea.Nest[1] + L11, black, "�_��(%d��/��)", Form_p->BlinkSpeed);
						if (OutputSpeed_Copy > 0) DrawFormatString(PropertyArea.Nest[0] + 270, PropertyArea.Nest[1] + L11, black, "�o��(%d��/�b)", OutputSpeed_Copy);//���������Ă��Ȃ��l��\��
						else if (OutputSpeed_Copy == 0) DrawFormatString(PropertyArea.Nest[0] + 270, PropertyArea.Nest[1] + L11, black, "�o��(�S�\��)");//���������Ă��Ȃ��l��\��
						else if (OutputSpeed_Copy == -1) DrawFormatString(PropertyArea.Nest[0] + 270, PropertyArea.Nest[1] + L11, black, "�o��(�S�\���E�N���b�N��ɃJ�[�\��)");//���������Ă��Ȃ��l��\��
						else DrawFormatString(PropertyArea.Nest[0] + 270, PropertyArea.Nest[1] + L11, black, "�o��(�S�\���E�J�[�\��)");//���������Ă��Ȃ��l��\��
						DrawFormatString(PropertyArea.Nest[0] + 420, PropertyArea.Nest[1] + L11, black, "�X�N���[��(%dpx/�b)", Form_p->ScrollSpeed);

						//���������Ă��Ȃ��lValue1�`Value5�ŕ\�����e�����߂�
						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L12, "�X�N���[��", blue);

						if (Value5 == 0) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L12, "�{�b�N�X(0�w�肵������)", black);
						else if (Value5 == 1) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L12, "�{�b�N�X(1�\����̃��b�Z�[�W���[)", black);
						else if (Value5 == 2) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L12, "�{�b�N�X(2�\�����̃��b�Z�[�W���[�@��Height�͕\����̉��[)", black);
						else if (Value5 == 3) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L12, "�{�b�N�X(3�\�����̃��b�Z�[�W���[�@��Height�͕\�����̉��[)", black);
						else if (Value5 == 4) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L12, "�{�b�N�X(4�w�肵�������E����Ȃ��Ȃ�\����̃��b�Z�[�W���[)", black);
						if (Value4 == 0) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L13, "�܂�Ԃ�(0�Ȃ�)", black);
						else if (Value4 == 1) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L13, "�܂�Ԃ�(1�����E����)", black);
						else if (Value4 == 2) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L13, "�܂�Ԃ�(2�킩��)", black);
						if (Value3 == 0) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "0��~(����)", black);
						else if (Value3 == 1) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "��~(1���)", black);
						else if (Value3 == 2) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "��~(2�E��)", black);
						else if (Value3 == 3) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "��~(3����)", black);
						else if (Value3 == 4) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "��~(4������)", black);
						else if (Value3 == 5) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "��~(5���[�v)", black);
						else if (Value3 == 6) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L13, "��~(6�ʉ�)", black);
						if (Value2 == 0) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L14, "�J�n0(���[)", black);
						else if (Value2 == 1) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L14, "�J�n(1��[)", black);
						else if (Value2 == 2) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L14, "�J�n(2�E�[)", black);
						else if (Value2 == 3) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L14, "�J�n(3���[)", black);
						else if (Value2 == 4) DrawString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L14, "�J�n(4�{�b�N�X��)", black);
						if (Value1 == 0) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L14, "�i�s����(0��)", black);
						else if (Value1 == 1) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L14, "����(1��)", black);
						else if (Value1 == 2) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L14, "����(2�E)", black);
						else if (Value1 == 3) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L14, "����(3��)", black);
						else if (Value1 == 4) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L14, "����(4�Ȃ�)", black);
						else if (Value1 == 5) DrawString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L14, "����(5�W���C�p�b�h)", black);


						//�T�E���h�p�X
						static int MessageSound_x1 = PropertyArea.Nest[0] + 120 + GetDrawStringWidth("���b�Z�[�W��", strlen("���b�Z�[�W��"));//���b�Z�[�W���i�p�J�p�J�̉��@�W�����v���j
						static int MessageSound_y1 = PropertyArea.Nest[1] + L15;
						static int ConfirmSound_x1 = PropertyArea.Nest[0] + 120 + GetDrawStringWidth("�m�艹", strlen("�m�艹"));//�m�艹�i�t���[�Y�����I����ԁC�E�B���h�E�����t�̏�Ԃ̂Ƃ��Ƀ{�^�������������B���͂̊m�艹�j
						static int ConfirmSound_y1 = PropertyArea.Nest[1] + L16;
						static int BackDelSound_x1 = PropertyArea.Nest[0] + 120 + GetDrawStringWidth("�o�b�N�X�y�[�X�E�f���[�g��", strlen("�o�b�N�X�y�[�X�E�f���[�g��"));//�o�b�N�X�y�[�X�E�f���[�g�̉�
						static int BackDelSound_y1 = PropertyArea.Nest[1] + L17;
						static int SpotColor = GetColor(255, 255, 204);
						//���b�Z�[�W���i�p�J�p�J�̉��@�W�����v���j
						if (MessageSound_x1 < ActiveMath::MouseX && ActiveMath::MouseX < MessageSound_x1 + GetDrawStringWidth(Form_RGB_SoundPath_p->MessageSoundPath, strlen(Form_RGB_SoundPath_p->MessageSoundPath)) + SystemFontSize
							&& MessageSound_y1 < ActiveMath::MouseY && ActiveMath::MouseY < MessageSound_y1 + SystemFontSize) {
							//�X�|�b�g
							DrawBox(MessageSound_x1, MessageSound_y1, MessageSound_x1 + GetDrawStringWidth(Form_RGB_SoundPath_p->MessageSoundPath, strlen(Form_RGB_SoundPath_p->MessageSoundPath)) + SystemFontSize,
								MessageSound_y1 + SystemFontSize, SpotColor, true);
							//�����ꂽ�Ƃ�
							if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
								char ImgFilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
								char ImgFileTitle[MAX_PATH];//�t�@�C�������擾����ϐ�
								char Dir[MAX_PATH] = { 0 };//�f�B���N�g�����w�肷�邽�߂̕ϐ�
								int FileType = 1;//0:�摜�t�@�C���@�@1:�����t�@�C��
								strcpy(Dir, LocalDir); strcat(Dir, "\\Sound");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Sound�ƂȂ�
								//�t�@�C���I���_�C�A���O
								if (GetImgFileName(Dir, ImgFilePath, ImgFileTitle, MAX_PATH, MAX_PATH, FileType)) {//�_�C�A���O�ɂ����t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
									//�t�@�C���擾�ɐ���������Dir����݂��t�@�C���̑��΃p�X���擾
									PathRelativePathTo(ImgFilePath, Dir, FILE_ATTRIBUTE_DIRECTORY, ImgFilePath, FILE_ATTRIBUTE_ARCHIVE);
									strcpy(Form_RGB_SoundPath_p->MessageSoundPath, ImgFilePath);
									MessageSound_Copy = LoadSoundMem(ImgFilePath);
								}
								//�_�C�A���O�̃L�����Z���ŁC�p�X�ƃn���h�����폜
								else {
									Form_RGB_SoundPath_p->MessageSoundPath[0] = '\0';
									MessageSound_Copy = -1;

								}
							}
						}
						//�m�艹�i�t���[�Y�����I����ԁC�E�B���h�E�����t�̏�Ԃ̂Ƃ��Ƀ{�^�������������B���͂̊m�艹�j
						else if (ConfirmSound_x1 < ActiveMath::MouseX && ActiveMath::MouseX < ConfirmSound_x1 + GetDrawStringWidth(Form_RGB_SoundPath_p->ConfirmSoundPath, strlen(Form_RGB_SoundPath_p->ConfirmSoundPath)) + SystemFontSize
							&& ConfirmSound_y1 < ActiveMath::MouseY && ActiveMath::MouseY < ConfirmSound_y1 + SystemFontSize) {
							//�X�|�b�g
							DrawBox(ConfirmSound_x1, ConfirmSound_y1, ConfirmSound_x1 + GetDrawStringWidth(Form_RGB_SoundPath_p->ConfirmSoundPath, strlen(Form_RGB_SoundPath_p->ConfirmSoundPath)) + SystemFontSize,
								ConfirmSound_y1 + SystemFontSize, SpotColor, true);
							//�����ꂽ�Ƃ�
							if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
								char ImgFilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
								char ImgFileTitle[MAX_PATH];//�t�@�C�������擾����ϐ�
								char Dir[MAX_PATH] = { 0 };//�f�B���N�g�����w�肷�邽�߂̕ϐ�
								int FileType = 1;//0:�摜�t�@�C���@�@1:�����t�@�C��
								strcpy(Dir, LocalDir); strcat(Dir, "\\Sound");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Sound�ƂȂ�
								//�t�@�C���I���_�C�A���O
								if (GetImgFileName(Dir, ImgFilePath, ImgFileTitle, MAX_PATH, MAX_PATH, FileType)) {//�_�C�A���O�ɂ����t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
									//�t�@�C���擾�ɐ���������Dir����݂��t�@�C���̑��΃p�X���擾
									PathRelativePathTo(ImgFilePath, Dir, FILE_ATTRIBUTE_DIRECTORY, ImgFilePath, FILE_ATTRIBUTE_ARCHIVE);
									strcpy(Form_RGB_SoundPath_p->ConfirmSoundPath, ImgFilePath);
									ConfirmSound_Copy = LoadSoundMem(ImgFilePath);

								}
								//�_�C�A���O�̃L�����Z���ŁC�p�X�ƃn���h�����폜
								else {
									Form_RGB_SoundPath_p->ConfirmSoundPath[0] = '\0';
									ConfirmSound_Copy = -1;

								}
							}
						}
						//�o�b�N�X�y�[�X�E�f���[�g�̉�
						else if (BackDelSound_x1 < ActiveMath::MouseX && ActiveMath::MouseX < BackDelSound_x1 + GetDrawStringWidth(Form_RGB_SoundPath_p->BackDelSoundPath, strlen(Form_RGB_SoundPath_p->BackDelSoundPath)) + SystemFontSize
							&& BackDelSound_y1 < ActiveMath::MouseY && ActiveMath::MouseY < BackDelSound_y1 + SystemFontSize) {
							//�X�|�b�g
							DrawBox(BackDelSound_x1, BackDelSound_y1, BackDelSound_x1 + GetDrawStringWidth(Form_RGB_SoundPath_p->BackDelSoundPath, strlen(Form_RGB_SoundPath_p->BackDelSoundPath)) + SystemFontSize,
								BackDelSound_y1 + SystemFontSize, SpotColor, true);
							//�����ꂽ�Ƃ�
							if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
								char ImgFilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
								char ImgFileTitle[MAX_PATH];//�t�@�C�������擾����ϐ�
								char Dir[MAX_PATH] = { 0 };//�f�B���N�g�����w�肷�邽�߂̕ϐ�
								int FileType = 1;//0:�摜�t�@�C���@�@1:�����t�@�C��
								strcpy(Dir, LocalDir); strcat(Dir, "\\Sound");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Sound�ƂȂ�
								//�t�@�C���I���_�C�A���O
								if (GetImgFileName(Dir, ImgFilePath, ImgFileTitle, MAX_PATH, MAX_PATH, FileType)) {//�_�C�A���O�ɂ����t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
									//�t�@�C���擾�ɐ���������Dir����݂��t�@�C���̑��΃p�X���擾
									PathRelativePathTo(ImgFilePath, Dir, FILE_ATTRIBUTE_DIRECTORY, ImgFilePath, FILE_ATTRIBUTE_ARCHIVE);
									strcpy(Form_RGB_SoundPath_p->BackDelSoundPath, ImgFilePath);
									BackDelSound_Copy = LoadSoundMem(ImgFilePath);
								}
								//�_�C�A���O�̃L�����Z���ŁC�p�X�ƃn���h�����폜
								else {
									Form_RGB_SoundPath_p->BackDelSoundPath[0] = '\0';
									BackDelSound_Copy = -1;
								}
							}
						}
						//�T�E���h�p�X�̕�����i�J�[�\���\���̂��Ƃɕ������\�����邱�Ɓj
						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L15, "�T�E���h", blue);

						DrawFormatString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L15, black, "���b�Z�[�W��(%s)", Form_RGB_SoundPath_p->MessageSoundPath);
						DrawFormatString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L16, black, "�m�艹(%s)", Form_RGB_SoundPath_p->ConfirmSoundPath);
						DrawFormatString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L17, black, "�o�b�N�X�y�[�X�E�f���[�g��(%s)", Form_RGB_SoundPath_p->BackDelSoundPath);

						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L18, "���b�Z�[�W�R���g���[�������l", red);

						//���s���ɒl�iMsgBoxCtrl.�`�j�������l�iMsgBoxCtrl_p[MsgBoxCrlNumber].�`�j�̂܂ܕω����Ȃ�����
						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L19, "�t�H�[���ԍ�", blue);
						DrawFormatString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L19, black, "MsgFormNo(%d)", MsgFormNo);//
						//���s���ɒl�iMsgBoxCtrl.�`�j�������l�iMsgBoxCtrl_p[MsgBoxCrlNumber].�`�j����ω��������
						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L20, "�����l", blue);
						DrawFormatString(PropertyArea.Nest[0] + 120, PropertyArea.Nest[1] + L20, black, "�ʒuX(%d)", MsgBoxCtrl_p[MsgBoxCrlNumber].Location[0]);
						DrawFormatString(PropertyArea.Nest[0] + 240, PropertyArea.Nest[1] + L20, black, "�ʒuY(%d)", MsgBoxCtrl_p[MsgBoxCrlNumber].Location[1]);
						DrawFormatString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L20, black, "��(%d)", MsgBoxCtrl_p[MsgBoxCrlNumber].Width);//�����l��\��
						DrawFormatString(PropertyArea.Nest[0] + 480, PropertyArea.Nest[1] + L20, black, "����(%d)", MsgBoxCtrl_p[MsgBoxCrlNumber].Height);//�����l��\��

				/////////////////////////////////////
						DrawString(PropertyArea.Nest[0], PropertyArea.Nest[1] + L21, "�����l", gray30);

						DrawFormatString(PropertyArea.Nest[0] + 360, PropertyArea.Nest[1] + L21, black, "��:%d", MsgBoxCtrl.Width);//���s���̒l��\��
						DrawFormatString(PropertyArea.Nest[0] + 480, PropertyArea.Nest[1] + L21, black, "����:%d", MsgBoxCtrl.Height);//���s���̒l��\��





						//�R���g���[���̕\��//////////////
						int PropertyBtn_PushType = 0; int PropertyBtn_Prev = -2; int PropertyBtn_Next = -2;
						int PropertyBtnClicked;
						PropertyBtnClicked = ShowButton(PropertyBtn, PropertyBtn_Kosuu, &ClickedNo, PropertyBtn_PushType, PropertyBtn_Prev, PropertyBtn_Next);
						// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

										//�������u�Ԃ܂��͒�������
						if (PropertyBtnClicked == 1 || PropertyBtnClicked > 20) {



							if (ClickedNo == 0) Form_p->Margin[0] += 1;
							else if (ClickedNo == 1 && Form_p->Margin[0] > 0) Form_p->Margin[0] -= 1;//0�܂ŉ�������

							else if (ClickedNo == 2) Form_p->Margin[1] += 1;
							else if (ClickedNo == 3 && Form_p->Margin[1] > 0) Form_p->Margin[1] -= 1;

							else if (ClickedNo == 4) Form_p->Margin[2] += 1;
							else if (ClickedNo == 5 && Form_p->Margin[2] > 0) Form_p->Margin[2] -= 1;

							else if (ClickedNo == 6) Form_p->Margin[3] += 1;
							else if (ClickedNo == 7 && Form_p->Margin[3] > 0) Form_p->Margin[3] -= 1;

							else if (ClickedNo == 8) Form_p->Padding[0] += 1;
							else if (ClickedNo == 9 && Form_p->Padding[0] > 0) Form_p->Padding[0] -= 1;

							else if (ClickedNo == 10) Form_p->Padding[1] += 1;
							else if (ClickedNo == 11 && Form_p->Padding[1] > 0) Form_p->Padding[1] -= 1;

							else if (ClickedNo == 12) Form_p->Padding[2] += 1;
							else if (ClickedNo == 13 && Form_p->Padding[2] > 0) Form_p->Padding[2] -= 1;

							else if (ClickedNo == 14) Form_p->Padding[3] += 1;
							else if (ClickedNo == 15 && Form_p->Padding[3] > 0) Form_p->Padding[3] -= 1;

							else if (16 <= ClickedNo && ClickedNo <= 21) {
								if (ClickedNo == 16 && Form_RGB_SoundPath_p->BorderColorRGB[0] < 255) Form_RGB_SoundPath_p->BorderColorRGB[0] += 1;
								else if (ClickedNo == 17 && Form_RGB_SoundPath_p->BorderColorRGB[0] > -1) Form_RGB_SoundPath_p->BorderColorRGB[0] -= 1;

								else if (ClickedNo == 18 && Form_RGB_SoundPath_p->BorderColorRGB[1] < 255) Form_RGB_SoundPath_p->BorderColorRGB[1] += 1;
								else if (ClickedNo == 19 && Form_RGB_SoundPath_p->BorderColorRGB[1] > 0) Form_RGB_SoundPath_p->BorderColorRGB[1] -= 1;

								else if (ClickedNo == 20 && Form_RGB_SoundPath_p->BorderColorRGB[2] < 255) Form_RGB_SoundPath_p->BorderColorRGB[2] += 1;
								else if (ClickedNo == 21 && Form_RGB_SoundPath_p->BorderColorRGB[2] > 0) Form_RGB_SoundPath_p->BorderColorRGB[2] -= 1;

								//�J���[�n���h���̎擾�iGetColor�͕��̒l�ł����[�h�͂ł��邪�F�͂悭�킩��Ȃ��jR�CG�CB��NULL�Ȃ�0�C0�C0�ō��ƂȂ�B
								if (Form_RGB_SoundPath_p->BorderColorRGB[0] == -1) Form_p->BorderColor = NULL;//R���|�P�Ȃ疳�F����
								else Form_p->BorderColor = GetColor(Form_RGB_SoundPath_p->BorderColorRGB[0], Form_RGB_SoundPath_p->BorderColorRGB[1], Form_RGB_SoundPath_p->BorderColorRGB[2]);

							}

							else if (ClickedNo == 22) Form_p->BorderThickness += 1;
							else if (ClickedNo == 23 && Form_p->BorderThickness > 0) Form_p->BorderThickness -= 1;

							else if (ClickedNo == 24 && Form_p->BorderType < 1) Form_p->BorderType += 1;//���^�C�v��
							else if (ClickedNo == 25 && Form_p->BorderType > 0) Form_p->BorderType -= 1;

							else if (26 <= ClickedNo && ClickedNo <= 31) {
								if (ClickedNo == 26 && Form_RGB_SoundPath_p->BackColorRGB[0] < 255) Form_RGB_SoundPath_p->BackColorRGB[0] += 1;
								else if (ClickedNo == 27 && Form_RGB_SoundPath_p->BackColorRGB[0] > -1) Form_RGB_SoundPath_p->BackColorRGB[0] -= 1;

								else if (ClickedNo == 28 && Form_RGB_SoundPath_p->BackColorRGB[1] < 255) Form_RGB_SoundPath_p->BackColorRGB[1] += 1;
								else if (ClickedNo == 29 && Form_RGB_SoundPath_p->BackColorRGB[1] > 0) Form_RGB_SoundPath_p->BackColorRGB[1] -= 1;

								else if (ClickedNo == 30 && Form_RGB_SoundPath_p->BackColorRGB[2] < 255) Form_RGB_SoundPath_p->BackColorRGB[2] += 1;
								else if (ClickedNo == 31 && Form_RGB_SoundPath_p->BackColorRGB[2] > 0) Form_RGB_SoundPath_p->BackColorRGB[2] -= 1;
								//�J���[�n���h���̎擾�iGetColor�͕��̒l�ł����[�h�͂ł��邪�F�͂悭�킩��Ȃ��jR�CG�CB��NULL�Ȃ�0�C0�C0�ō��ƂȂ�B
								if (Form_RGB_SoundPath_p->BackColorRGB[0] == -1) Form_p->BackColor = NULL;//R���|�P�Ȃ疳�F����
								else Form_p->BackColor = GetColor(Form_RGB_SoundPath_p->BackColorRGB[0], Form_RGB_SoundPath_p->BackColorRGB[1], Form_RGB_SoundPath_p->BackColorRGB[2]);
							}

							else if (ClickedNo == 32 && Form_p->BackTransparency < 100) Form_p->BackTransparency += 1;
							else if (ClickedNo == 33 && Form_p->BackTransparency > 0) Form_p->BackTransparency -= 1;

							else if (34 <= ClickedNo && ClickedNo <= 39) {
								if (ClickedNo == 34 && Form_RGB_SoundPath_p->ActiveTagColorRGB[0] < 255) Form_RGB_SoundPath_p->ActiveTagColorRGB[0] += 1;
								else if (ClickedNo == 35 && Form_RGB_SoundPath_p->ActiveTagColorRGB[0] > -1) Form_RGB_SoundPath_p->ActiveTagColorRGB[0] -= 1;

								else if (ClickedNo == 36 && Form_RGB_SoundPath_p->ActiveTagColorRGB[1] < 255) Form_RGB_SoundPath_p->ActiveTagColorRGB[1] += 1;
								else if (ClickedNo == 37 && Form_RGB_SoundPath_p->ActiveTagColorRGB[1] > 0) Form_RGB_SoundPath_p->ActiveTagColorRGB[1] -= 1;

								else if (ClickedNo == 38 && Form_RGB_SoundPath_p->ActiveTagColorRGB[2] < 255) Form_RGB_SoundPath_p->ActiveTagColorRGB[2] += 1;
								else if (ClickedNo == 39 && Form_RGB_SoundPath_p->ActiveTagColorRGB[2] > 0) Form_RGB_SoundPath_p->ActiveTagColorRGB[2] -= 1;
								//�J���[�n���h���̎擾�iGetColor�͕��̒l�ł����[�h�͂ł��邪�F�͂悭�킩��Ȃ��jR�CG�CB��NULL�Ȃ�0�C0�C0�ō��ƂȂ�B
								if (Form_RGB_SoundPath_p->ActiveTagColorRGB[0] == -1) Form_p->ActiveTagColor = NULL;//R���|�P�Ȃ疳�F����
								else Form_p->ActiveTagColor = GetColor(Form_RGB_SoundPath_p->ActiveTagColorRGB[0], Form_RGB_SoundPath_p->ActiveTagColorRGB[1], Form_RGB_SoundPath_p->ActiveTagColorRGB[2]);
							}

							else if (ClickedNo == 40 && Form_p->ActiveTagColorTransparency < 100) Form_p->ActiveTagColorTransparency += 1;
							else if (ClickedNo == 41 && Form_p->ActiveTagColorTransparency > 0) Form_p->ActiveTagColorTransparency -= 1;

							else if (42 <= ClickedNo && ClickedNo <= 47) {
								if (ClickedNo == 42 && Form_RGB_SoundPath_p->ActiveMathColorRGB[0] < 255) Form_RGB_SoundPath_p->ActiveMathColorRGB[0] += 1;
								else if (ClickedNo == 43 && Form_RGB_SoundPath_p->ActiveMathColorRGB[0] > -1) Form_RGB_SoundPath_p->ActiveMathColorRGB[0] -= 1;

								else if (ClickedNo == 44 && Form_RGB_SoundPath_p->ActiveMathColorRGB[1] < 255) Form_RGB_SoundPath_p->ActiveMathColorRGB[1] += 1;
								else if (ClickedNo == 45 && Form_RGB_SoundPath_p->ActiveMathColorRGB[1] > 0) Form_RGB_SoundPath_p->ActiveMathColorRGB[1] -= 1;

								else if (ClickedNo == 46 && Form_RGB_SoundPath_p->ActiveMathColorRGB[2] < 255) Form_RGB_SoundPath_p->ActiveMathColorRGB[2] += 1;
								else if (ClickedNo == 47 && Form_RGB_SoundPath_p->ActiveMathColorRGB[2] > 0) Form_RGB_SoundPath_p->ActiveMathColorRGB[2] -= 1;
								//�J���[�n���h���̎擾�iGetColor�͕��̒l�ł����[�h�͂ł��邪�F�͂悭�킩��Ȃ��jR�CG�CB��NULL�Ȃ�0�C0�C0�ō��ƂȂ�B
								if (Form_RGB_SoundPath_p->ActiveMathColorRGB[0] == -1) Form_p->ActiveMathColor = NULL;//R���|�P�Ȃ疳�F����
								else Form_p->ActiveMathColor = GetColor(Form_RGB_SoundPath_p->ActiveMathColorRGB[0], Form_RGB_SoundPath_p->ActiveMathColorRGB[1], Form_RGB_SoundPath_p->ActiveMathColorRGB[2]);
							}


							else if (ClickedNo == 48 && Form_p->ActiveMathColorTransparency < 100) Form_p->ActiveMathColorTransparency += 1;
							else if (ClickedNo == 49 && Form_p->ActiveMathColorTransparency > 0) Form_p->ActiveMathColorTransparency -= 1;

							else if (50 <= ClickedNo && ClickedNo <= 55) {
								if (ClickedNo == 50 && Form_p->FontColorRGB[0] < 255) Form_p->FontColorRGB[0] += 1;
								else if (ClickedNo == 51 && Form_p->FontColorRGB[0] > -1) Form_p->FontColorRGB[0] -= 1;

								else if (ClickedNo == 52 && Form_p->FontColorRGB[1] < 255) Form_p->FontColorRGB[1] += 1;
								else if (ClickedNo == 53 && Form_p->FontColorRGB[1] > 0) Form_p->FontColorRGB[1] -= 1;

								else if (ClickedNo == 54 && Form_p->FontColorRGB[2] < 255) Form_p->FontColorRGB[2] += 1;
								else if (ClickedNo == 55 && Form_p->FontColorRGB[2] > 0) Form_p->FontColorRGB[2] -= 1;

								//�J���[�n���h���̎擾�iGetColor�͕��̒l�ł����[�h�͂ł��邪�F�͂悭�킩��Ȃ��jR�CG�CB��NULL�Ȃ�0�C0�C0�ō��ƂȂ�B
								if (Form_p->FontColorRGB[0] == -1) Form_p->FontColor = NULL;//R���|�P�Ȃ疳�F����
								else Form_p->FontColor = GetColor(Form_p->FontColorRGB[0], Form_p->FontColorRGB[1], Form_p->FontColorRGB[2]);
							}

							else if (ClickedNo == 56) Form_p->Leading += 1;
							else if (ClickedNo == 57) Form_p->Leading -= 1;

							else if (ClickedNo == 58) Form_p->MaxLine += 1;
							else if (ClickedNo == 59 && Form_p->MaxLine > -1) Form_p->MaxLine -= 1;//-1�܂ŉ�������

							else if (ClickedNo == 60) Form_p->BlinkSpeed += 1;
							else if (ClickedNo == 61) Form_p->BlinkSpeed -= 1;

							else if (ClickedNo == 62) OutputSpeed_Copy += 1;
							else if (ClickedNo == 63 && OutputSpeed_Copy > -2) OutputSpeed_Copy -= 1;

							else if (ClickedNo == 64) Form_p->ScrollSpeed += 1;
							else if (ClickedNo == 65 && Form_p->ScrollSpeed > 0) Form_p->ScrollSpeed -= 1;

							else if (66 <= ClickedNo && ClickedNo <= 75) {
								if (ClickedNo == 66 && Value5 < 4) Value5++;
								else if (ClickedNo == 67 && Value5 > 0) {
									Value5--;//�}�C�i�X�ɂȂ�Ȃ��悤��if (Value5 > 0)  && flag_mode == 1
									if (Value5 == 0) MsgBoxCtrl.Height = MsgBoxCtrl_p[MsgBoxCrlNumber].Height;//���s���̃R���g���[���ɍ����̏����l�������ʂ�
									//�i�����̌Œ�E�L�k�i������5���ځj�̐؂�ւ����ɁC�����L�k�������������ɖ߂����߁j
								}
								else if (ClickedNo == 68 && Value4 < 2) Value4++;
								else if (ClickedNo == 69 && Value4 > 0) Value4--;
								else if (ClickedNo == 70 && Value3 < 6) Value3++;
								else if (ClickedNo == 71 && Value3 > 0) Value3--;
								else if (ClickedNo == 72 && Value2 < 4) Value2++;
								else if (ClickedNo == 73 && Value2 > 0) Value2--;
								else if (ClickedNo == 74 && Value1 < 5) Value1++;
								else if (ClickedNo == 75 && Value1 > 0) Value1--;
								nukeru = 1;//0:for���[�v�p���@1�Ffor���[�v���甲����
							}
							else if (ClickedNo == 76 && MsgFormNo < MsgBoxForm_Kosuu - 1) {
								//�t�H�[���ԍ��̕ύX�O�ɃX�N���[���^�C�v��OutputSpeed��{���̒l�ɖ߂��Ă���
								MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
								MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;
								MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
								MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
								MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;

								//�t�H�[���̔ԍ���ύX����
								MsgFormNo++;//�l�𑝂₷
								MsgBoxCtrl.MsgBoxForm_p += 1;//���s���̃R���g���[���̒l�𑀍삷��
								MsgBoxCtrl_p[MsgBoxCrlNumber].MsgBoxForm_p += 1;//���̒l�𑀍삷��
								MsgBoxFormNumber_h[MsgBoxCrlNumber] = MsgFormNo;
								//�X�N���[���^�C�v��OutputSpeed��ς���
								Value1 = MsgBoxForm_p[MsgFormNo].Option % 10;
								Value2 = MsgBoxForm_p[MsgFormNo].Option % 100 / 10;
								Value3 = MsgBoxForm_p[MsgFormNo].Option % 1000 / 100;
								Value4 = MsgBoxForm_p[MsgFormNo].Option % 10000 / 1000;
								Value5 = MsgBoxForm_p[MsgFormNo].Option % 100000 / 10000;
								OutputSpeed_Copy = MsgBoxForm_p[MsgFormNo].OutputSpeed;
								MessageSound_Copy = MsgBoxForm_p[MsgFormNo].MessageSound;
								BackDelSound_Copy = MsgBoxForm_p[MsgFormNo].BackDelSound;
								ConfirmSound_Copy = MsgBoxForm_p[MsgFormNo].ConfirmSound;

								nukeru = 1;//nukeru�@0:for���[�v�p���@1�Ffor���[�v���甲����
							}
							else if (ClickedNo == 77 && MsgFormNo > 0) {
								//�t�H�[���ԍ��̕ύX�O�ɃX�N���[���^�C�v��OutputSpeed��{���̒l�ɖ߂��Ă���
								MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
								MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;
								MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
								MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
								MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;

								//�t�H�[���̔ԍ���ύX����
								MsgFormNo--;//�l�����炷
								MsgBoxCtrl.MsgBoxForm_p -= 1;//���s���̃R���g���[���̒l�𑀍삷��
								MsgBoxCtrl_p[MsgBoxCrlNumber].MsgBoxForm_p -= 1;//���̒l�𑀍삷��
								MsgBoxFormNumber_h[MsgBoxCrlNumber] = MsgFormNo;
								//�X�N���[���^�C�v��OutputSpeed��ς���
								Value1 = MsgBoxForm_p[MsgFormNo].Option % 10;
								Value2 = MsgBoxForm_p[MsgFormNo].Option % 100 / 10;
								Value3 = MsgBoxForm_p[MsgFormNo].Option % 1000 / 100;
								Value4 = MsgBoxForm_p[MsgFormNo].Option % 10000 / 1000;
								Value5 = MsgBoxForm_p[MsgFormNo].Option % 100000 / 10000;
								OutputSpeed_Copy = MsgBoxForm_p[MsgFormNo].OutputSpeed;
								MessageSound_Copy = MsgBoxForm_p[MsgFormNo].MessageSound;
								BackDelSound_Copy = MsgBoxForm_p[MsgFormNo].BackDelSound;
								ConfirmSound_Copy = MsgBoxForm_p[MsgFormNo].ConfirmSound;

								nukeru = 1;//nukeru�@0:for���[�v�p���@1�Ffor���[�v���甲����
							}
							else if (ClickedNo == 78) {
								MsgBoxCtrl.Location[0] += 1;//���s���̃R���g���[���̒l�𑀍삷��
								MsgBoxCtrl_p[MsgBoxCrlNumber].Location[0] += 1;//���̒l�𑀍삷��
							}
							else if (ClickedNo == 79) {
								MsgBoxCtrl.Location[0] -= 1;//���s���̃R���g���[���̒l�𑀍삷��
								MsgBoxCtrl_p[MsgBoxCrlNumber].Location[0] -= 1;//���̒l�𑀍삷��
							}
							else if (ClickedNo == 80) {
								MsgBoxCtrl.Location[1] += 1;//���s���̃R���g���[���̒l�𑀍삷��
								MsgBoxCtrl_p[MsgBoxCrlNumber].Location[1] += 1;//���̒l�𑀍삷��
							}
							else if (ClickedNo == 81) {
								MsgBoxCtrl.Location[1] -= 1;//���s���̃R���g���[���̒l�𑀍삷��
								MsgBoxCtrl_p[MsgBoxCrlNumber].Location[1] -= 1;//���̒l�𑀍삷��
							}
							else if (ClickedNo == 82) {
								MsgBoxCtrl_p[MsgBoxCrlNumber].Width += 1;//�����l�𑀍삷��
								MsgBoxCtrl.Width += 1;//���s���̃R���g���[���̒l�𑀍삷��
							}
							else if (ClickedNo == 83 && MsgBoxCtrl_p[MsgBoxCrlNumber].Width > 0) {
								MsgBoxCtrl_p[MsgBoxCrlNumber].Width -= 1;//�����l�𑀍삷��
								MsgBoxCtrl.Width -= 1;//���s���̃R���g���[���̒l�𑀍삷��
							}
							else if (ClickedNo == 84) {
								MsgBoxCtrl_p[MsgBoxCrlNumber].Height += 1;//�����l�𑀍삷��
								if (MsgBoxForm_p[MsgFormNo].Option % 100000 / 10000 == 4) {
									if (MsgBoxCtrl.Height < MsgBoxCtrl_p[MsgBoxCrlNumber].Height) MsgBoxCtrl.Height = MsgBoxCtrl_p[MsgBoxCrlNumber].Height;
								}
							}
							else if (ClickedNo == 85 && MsgBoxCtrl_p[MsgBoxCrlNumber].Height > 0) {
								MsgBoxCtrl_p[MsgBoxCrlNumber].Height -= 1;//�����l�𑀍삷��

								if (MsgBoxForm_p[MsgFormNo].Option % 100000 / 10000 == 4) {
									if (MsgBoxCtrl.Height == MsgBoxCtrl_p[MsgBoxCrlNumber].Height + 1) MsgBoxCtrl.Height = MsgBoxCtrl_p[MsgBoxCrlNumber].Height;
								}
							}

						}

					}
				}//�p�����[�^�̕\���̏I��

				//���s���̃p�����[�^�i�R���g���[���{P�j
				if (flag_mode == 2) {//���s���[�h
					if (ActiveMath::Key[KEY_INPUT_P] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {//�R���g���[���{P�Ŏ��s���̃p�����[�^�\��
						ParameterFlag++;
						if (ParameterFlag == 2) ParameterFlag = 0;
					}
					if (ParameterFlag == 1) {

						ShowArea(&PropertyArea, 1);

						//�l�͕ω����邪����������ϐ��ł͂Ȃ��B�i�ҏW���̒l�Ȃ̂ŕ\������K�v�͂Ȃ��j
						DrawFormatString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L1, black, "Width(%d)", MsgBoxCtrl.Width);//���s���̒l��\��
						DrawFormatString(PropertyArea.Nest[0] + 180 * 1, PropertyArea.Nest[1] + L1, black, "Height(%d)", MsgBoxCtrl.Height);//���s���̒l��\��
						DrawFormatString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L2, black, "OuterWidth(%d)", MsgBoxCtrl.OuterWidth);
						DrawFormatString(PropertyArea.Nest[0] + 180 * 1, PropertyArea.Nest[1] + L2, black, "OuterHeight(%d)", MsgBoxCtrl.OuterHeight);
						DrawFormatString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L3, black, "MessWidth(%d)", MsgBoxCtrl.MessWidth);
						DrawFormatString(PropertyArea.Nest[0] + 180 * 1, PropertyArea.Nest[1] + L3, black, "MessHeight(%d)", MsgBoxCtrl.MessHeight);
						DrawFormatString(PropertyArea.Nest[0] + 180 * 0, PropertyArea.Nest[1] + L4, black, "Condition(%d)", MsgBoxCtrl.Condition);
						DrawFormatString(PropertyArea.Nest[0] + 180 * 1, PropertyArea.Nest[1] + L4, black, "Condition(%d)", MsgBoxCtrl.Condition);
					}
				}//

			}//�t�@�C�����J���Ă���Ƃ��̏����̏I��

			//���X�e�[�^�X�o�[
			ShowArea(&Statusbar, 1);
			static int StatusNumber = 0;//�p�b�h���[�h�̃X�e�[�^�X�o�[�̕\�����e��ύX�i�R���g���[���{S�j
			if (ActiveMath::Key[KEY_INPUT_S] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {//
				StatusNumber += 1;//
				if (StatusNumber == 9) StatusNumber = 0;
			}
			if (StatusNumber == 0) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "���b�Z�[�W�t�H�[���ԍ�: %d  /  �R���f�B�V����: %d", MsgFormNo, MsgBoxCtrl.Condition);
			}
			else if (StatusNumber == 1) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�t�H���g�Z�b�g_rw: %s  /  �t�H���g�摜�Z�b�g_rw: %s  /  �^�O�Z�b�g_rw: %s", FileTitle_Font_rw, FileTitle_FontImg_rw, FileTitle_Tag_rw);
			}
			else if (StatusNumber == 2) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�t�H���g�Z�b�g: %s  /  �t�H���g�摜�Z�b�g: %s  /  �^�O�Z�b�g: %s", FileTitle_Font, FileTitle_FontImg, FileTitle_Tag);
			}
			else if (StatusNumber == 3) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�W���C�p�b�h_rw: %s", FileTitle_Joypad_rw);
			}
			else if (StatusNumber == 4) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�W���C�p�b�h: %s", FileTitle_Joypad);
			}
			else if (StatusNumber == 5) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�t�@�C���p�X: %s", FilePath_h);//�t�@�C���p�X
			}
			else if (StatusNumber == 6) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "AppDir: %s", AppDir);//�A�v���P�[�V�����f�B���N�g��
			}
			else if (StatusNumber == 7) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "LocalDir: %s", LocalDir);//���[�J���f�B���N�g��
			}
			else if (StatusNumber == 8) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "MsgDir: %s", MsgDir);//���b�Z�[�W�f�B���N�g��
			}

			////////�i�S�j�v���_�E�����j���[�̏���////////////////////////////
			if (List0.Active == 1) {//�t�@�C���֘A�̃v���_�E�����X�g�̏���
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[0].Location[0] + ToolAForm.Margin[0],
					ToolA[0].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[0].Width,
					box[1] + ToolA[0].Height
				};
				if (ToolA[0].ParentArea_p != NULL) {
					box[0] += ToolA[0].ParentArea_p->Nest[0];
					box[1] += ToolA[0].ParentArea_p->Nest[1];
					box[2] += ToolA[0].ParentArea_p->Nest[0];
					box[3] += ToolA[0].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List0.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[0].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[0].Padding[1], black, ToolA[0].Title); //�����̕\��
				//���X�g����
				ShowList(&List0);


				////�V�K�쐬//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�iNULL�j�C�t�@�C���^�C�g���i����j�C�G�f�B�^�[���[�h�i����}�}�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				int r = 0;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {//�N���b�N�����Ƃ��̏���
						char GetDir[MAX_PATH];
						//�_�C�A���O����f�B���N�g���̑I��
						if (LocalDir[0] == '\0') {
							strcpy(LocalDir, AppDir);
							strcat(LocalDir, "\\OriginalFile\\MessageData");
						}
						if (GetOpenDirectoryName(LocalDir, GetDir, MAX_PATH)) {
							strcpy(FilePath_h, GetDir);//) strcpy(FileTitle_Mondai, "����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
							strcat(FilePath_h, "\\����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
							//�i�g���q�Ȃ��Ȃ̂Œ��ӁB�f�B���N�g�����Ɂu����.txt�v������΂�����J���Ă��܂����߁j

							//�f�B���N�g���̒�����Monster�Ƃ����f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCMonster���̊����̃t�@�C���͏����Ȃ��B
							SetCurrentDirectory(GetDir);
							CreateDirectory("Img", NULL);
							CreateDirectory("Sound", NULL);
							*ExitModeFlag_p = 1;//�e���[�h���甲����T�C��
							return 0;//�v���r���[���[�h���甲����
						}
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/

				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�@�C�����J���i���t�@�C���j//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�i�擾�j�C�t�@�C���^�C�g���i�擾�j�C�G�f�B�^�[���[�h�ԍ��i�擾�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O����t�@�C�������擾
						if (LocalDir[0] == '\0') {
							strcpy(LocalDir, AppDir);
							strcat(LocalDir, "\\OriginalFile\\MessageData");
						}
						char filepath[MAX_PATH]; char filetitle[MAX_PATH];
						if (GetOpenFileNameACM(LocalDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I�����̃J�����g�f�B���N�g���̓��b�Z�[�W�t�@�C��������f�B���N�g���B�u�`\\OriginalFile\\MessageData�v�Ƃ͌���Ȃ��̂Œ��ӁB
						//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
							//�J�����t�@�C���̃��[�h�𒲂ׂ�
							ClearDrawScreen();
							switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
							case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
								strcpy(FilePath_h, filepath);//�t�@�C���p�X�̊m��
								for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
								*ExitModeFlag_p = 1;//�e���[�h���甲����T�C��
								return 0;//�v���r���[���[�h���甲����
							case -1:
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
								WaitKey(); break;
							default://�����icase -2�j�j
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
								WaitKey();
							}
						}
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷

				//�㏑���ۑ�
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//���b�Z�[�W�̕ۑ�
						if (mondai_p != NULL) OverwriteMondai(FilePath_h, FileTitle_h, MAX_PATH, MAX_PATH, mondai_p);//��胂�[�h���炫���Ƃ��̏㏑���ۑ��i�܂��͖��O��t���ĕۑ��j
						else OverwriteMessage(FilePath_h, FileTitle_h, MAX_PATH, MAX_PATH, Message_h, MsgBoxCtrl.Tag[0].Post);//���b�Z�[�W���炫���Ƃ��̏㏑���ۑ��i�܂��͖��O��t���ĕۑ��j;//tag[0].Post��TagKosuu�itagnomax�j�Ƃ��đ�p
						//�ҏW���̂Ƃ��{���̒l�ɖ߂�
						if (flag_mode == 1) {
							MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
							MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;//
							MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
							MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
							MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;
						}
						else flag_mode = 1;//�Đ����̂Ƃ��C�ҏW���[�h�ɖ߂��Ă��甲����i�ۑ�����C�Đ����n�܂�̂�h�����߁j
						//���b�Z�[�W�{�b�N�X�R���g���[���C���b�Z�[�W�{�b�N�X�t�H�[���C�X�^�C���Z�b�g�̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", MsgBoxCtrl_p, MsgBoxCtrl_Kosuu, MsgBoxFormNumber_h);
						SaveMsgBoxForm(".\\MsgBoxForm.txt", MsgBoxForm_p, MsgBoxForm_RGB_SoundPath_p, MsgBoxForm_Kosuu);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
						SaveJoypadSetPath(".\\JoypadSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

						//�I�����̃J�����g�f�B���N�g����LocalDir

						//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_h);//�t�@�C������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
						//for���[�v���甲���ď�������
						nukeru = 1;//0:for���[�v�p���@1�Ffor���[�v���甲����
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				//���O��t���ĕۑ�
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						/**/
						SaveAsNewMessage(FilePath_h, FileTitle_h, MAX_PATH, MAX_PATH, Message_h, MsgBoxCtrl.Tag[0].Post); //���O��t���ĕۑ�
						//�ҏW���̂Ƃ��{���̒l�ɖ߂�
						if (flag_mode == 1) {
							MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
							MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;//
							MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
							MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
							MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;
						}
						else flag_mode = 1;//�Đ����̂Ƃ��C�ҏW���[�h�ɖ߂��Ă��甲����i�ۑ�����C�Đ����n�܂�̂�h�����߁j
						//���b�Z�[�W�{�b�N�X�R���g���[���C���b�Z�[�W�{�b�N�X�t�H�[���C�X�^�C���Z�b�g�̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", MsgBoxCtrl_p, MsgBoxCtrl_Kosuu, MsgBoxFormNumber_h);
						SaveMsgBoxForm(".\\MsgBoxForm.txt", MsgBoxForm_p, MsgBoxForm_RGB_SoundPath_p, MsgBoxForm_Kosuu);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
						SaveJoypadSetPath(".\\JoypadSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

						//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_h);//�t�@�C������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
						//for���[�v���甲���ď�������
						nukeru = 1;//0:for���[�v�p���@1�Ffor���[�v���甲����
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				///////�߂�
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//���b�Z�[�W�ҏW���[�h�̂Ƃ��̓z�[���܂Ŗ߂�i�K�����b�Z�[�W�ҏW���[�h���甲����̂�*ExitModeFlag_p = 1;�͕s�v�j
						if (*EditorMode_p == 0) *EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
						//���ҏW���[�h�C�p�b�h�r���[�A�̂Ƃ��͊e���[�h�܂Ŗ߂�
						else {
							//�ҏW���̂Ƃ��{���̒l�ɖ߂�
							if (flag_mode == 1) {
								MsgBoxForm_p[MsgFormNo].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
								MsgBoxForm_p[MsgFormNo].OutputSpeed = OutputSpeed_Copy;//
								MsgBoxForm_p[MsgFormNo].MessageSound = MessageSound_Copy;
								MsgBoxForm_p[MsgFormNo].BackDelSound = BackDelSound_Copy;
								MsgBoxForm_p[MsgFormNo].ConfirmSound = ConfirmSound_Copy;
							}
						}
						return 0;
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				///////�z�[����ʂɖ߂�//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						*ExitModeFlag_p = 1;//�e���[�h���甲����T�C��
						*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
						return 0;//�v���r���[���[�h���甲����
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////////�A�v���P�[�V�����̏I��
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						DxLib_End(); return 0;
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����@�ireturn�Ŋ֐����甲������̈ȊO�́C���ׂĂ����Ń��X�g���甲����j
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List0.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea_p[AreaNumber].Active = 1;
				}
			}

			//////�J�X�^�}�C�Y�̃v���_�E�����X�g
			if (List1.Active == 1) {//�v���_�E�����X�g190802
				ShowList(&List1);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[1].Location[0] + ToolAForm.Margin[0],
					ToolA[1].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[1].Width,
					box[1] + ToolA[1].Height
				};
				if (ToolA[1].ParentArea_p != NULL) {
					box[0] += ToolA[1].ParentArea_p->Nest[0];
					box[1] += ToolA[1].ParentArea_p->Nest[1];
					box[2] += ToolA[1].ParentArea_p->Nest[0];
					box[3] += ToolA[1].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List1.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[1].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[1].Padding[1], black, ToolA[1].Title); //�����̕\��

				////�X�^�C���̕ۑ�
				int  r = 0;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SetCurrentDirectory(LocalDir);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
						SaveJoypadSetPath(".\\JoypadSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontSet, SourcePath, FileTitle_Font, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontSet���J�����g�f�B���N�g���ƂȂ�
							//rw�̏�������
							if (strcmp(FileTitle_Font_rw, "�Ȃ�") == 0) {//FontTagSettings���Ȃ��Ƃ�
								strcpy(FileTitle_FontImg_rw, "���ݒ�"); strcpy(FileTitle_Tag_rw, "���ݒ�");
								strcpy(Dir_FontSet_rw, "���ݒ�"); strcpy(Dir_FontImgSet_rw, "���ݒ�"); strcpy(Dir_TagSet_rw, "���ݒ�");
								strcpy(Dir_AppImg_rw, "���ݒ�"); strcpy(Dir_AppSound_rw, "���ݒ�");
							}
							strcpy(FileTitle_Font_rw, FileTitle_Font);
							//�t�@�C���̃R�s�[�iDir_FontSet�O����t�@�C����I�������Ƃ��j
							char FilePath[MAX_PATH];
							strcpy(FilePath, Dir_FontSet); strcat(FilePath, "\\"); strcat(FilePath, FileTitle_Font);
							if (strcmp(SourcePath, FilePath)) CopyFile(SourcePath, FilePath, FALSE);//��΃p�X�ǂ����̔�r
							//�t�H���g�Z�b�g�̃��[�h
							LoadFontSet(FilePath);//��΃p�X�Ń��[�h
							nukeru = 1;//�^�O���ēǂݍ��݂��邽�߁i�������Ŋ֌W����Ǝv���j
						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�摜�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�摜�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontImgSet, SourcePath, FileTitle_FontImg, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontImgSet���J�����g�f�B���N�g���ƂȂ�
							//rw�̏�������
							if (strcmp(FileTitle_Font_rw, "�Ȃ�") == 0) {//FontTagSettings���Ȃ��Ƃ�
								strcpy(FileTitle_Font_rw, "���ݒ�"); strcpy(FileTitle_Tag_rw, "���ݒ�");
								strcpy(Dir_FontSet_rw, "���ݒ�"); strcpy(Dir_FontImgSet_rw, "���ݒ�"); strcpy(Dir_TagSet_rw, "���ݒ�");
								strcpy(Dir_AppImg_rw, "���ݒ�"); strcpy(Dir_AppSound_rw, "���ݒ�");
							}
							strcpy(FileTitle_FontImg_rw, FileTitle_FontImg);
							//�t�@�C���̃R�s�[�iDir_FontSet�O����t�@�C����I�������Ƃ��j
							char FilePath[MAX_PATH];
							strcpy(FilePath, Dir_FontImgSet); strcat(FilePath, "\\"); strcat(FilePath, FileTitle_FontImg);
							if (strcmp(SourcePath, FilePath)) CopyFile(SourcePath, FilePath, FALSE);//��΃p�X�ǂ����̔�r
							//�t�H���g�摜�Z�b�g�̃��[�h
							LoadFontImgSet(FilePath);//��΃p�X�Ń��[�h
							nukeru = 1;//�^�O���ēǂݍ��݂��邽�߁i�摜�̕��Ŋ֌W����Ǝv���j
						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�^�O�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ń^�O�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_TagSet, SourcePath, FileTitle_Tag, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_TagSet���J�����g�f�B���N�g���ƂȂ�
							//rw�̏�������
							if (strcmp(FileTitle_Font_rw, "�Ȃ�") == 0) {//FontTagSettings���Ȃ��Ƃ�
								strcpy(FileTitle_Font_rw, "���ݒ�"); strcpy(FileTitle_FontImg_rw, "���ݒ�");
								strcpy(Dir_FontSet_rw, "���ݒ�"); strcpy(Dir_FontImgSet_rw, "���ݒ�"); strcpy(Dir_TagSet_rw, "���ݒ�");
								strcpy(Dir_AppImg_rw, "���ݒ�"); strcpy(Dir_AppSound_rw, "���ݒ�");
							}
							strcpy(FileTitle_Tag_rw, FileTitle_Tag);
							//�t�@�C���̃R�s�[�iDir_FontSet�O����t�@�C����I�������Ƃ��j
							char FilePath[MAX_PATH];
							strcpy(FilePath, Dir_TagSet); strcat(FilePath, "\\"); strcat(FilePath, FileTitle_Tag);
							if (strcmp(SourcePath, FilePath)) CopyFile(SourcePath, FilePath, FALSE);//��΃p�X�ǂ����̔�r
							//�^�O�Z�b�g�̃��[�h
							LoadTagSet(FilePath);//��΃p�X�Ń��[�h
							nukeru = 1;//�^�O���ēǂݍ��݂��邽��
						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�W���C�p�b�h�̊��蓖��
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�ŃW���C�p�b�h�̊��蓖�Ẵt�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_Joypad, SourcePath, FileTitle_Joypad, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_Joypad���J�����g�f�B���N�g���ƂȂ�
							if (strcmp(FileTitle_Joypad_rw, "�Ȃ�") == 0) {//JoypadSettings���Ȃ��Ƃ�
								strcpy(Dir_Joypad_rw, "���ݒ�");
							}
							strcpy(FileTitle_Joypad_rw, FileTitle_Joypad);
							//�t�@�C���̃R�s�[�iDir_FontSet�O����t�@�C����I�������Ƃ��j
							char FilePath[MAX_PATH];
							strcpy(FilePath, Dir_Joypad); strcat(FilePath, "\\"); strcat(FilePath, FileTitle_Joypad);
							if (strcmp(SourcePath, FilePath)) CopyFile(SourcePath, FilePath, FALSE);//��΃p�X�ǂ����̔�r
							//�W���C�p�b�h�̊��蓖�Ẵ��[�h
							LoadJoypadAssignment(FilePath);//��΃p�X�Ń��[�h
							//�^�O�̍ēǂݍ��݂͕K�v�Ȃ�
						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H�[���ƃR���g���[���̕\��/��\��
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						flag_paramata *= -1;
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List1.Nest[1] += List1.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List1.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea_p[AreaNumber].Active = 1;
				}
			}
			//////�ݒ�̃v���_�E�����X�g
			if (List2.Active == 1) {//�v���_�E�����X�g190802
				ShowList(&List2);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[2].Location[0] + ToolAForm.Margin[0],
					ToolA[2].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[2].Width,
					box[1] + ToolA[2].Height
				};
				if (ToolA[2].ParentArea_p != NULL) {
					box[0] += ToolA[2].ParentArea_p->Nest[0];
					box[1] += ToolA[2].ParentArea_p->Nest[1];
					box[2] += ToolA[2].ParentArea_p->Nest[0];
					box[3] += ToolA[2].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List2.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[2].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[2].Padding[1], black, ToolA[2].Title); //�����̕\��

				////�G�f�B�^�[�̐ݒ�
				int  r = 0;
				if (List2.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List2.Nest[0] + List2.RowWidth && List2.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List2.Nest[1] + List2.RowHeight
					&& List2Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List2.Nest[0], List2.Nest[1], List2.Nest[0] + List2.RowWidth, List2.Nest[1] + List2.RowHeight, List2.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						EditorSettingsFlag = 1;
					}
				}
				if (List2Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List2.Nest[0] + List2.BorderThickness + List2.RowPadding[0], List2.Nest[1] + List2.BorderThickness + List2.RowPadding[1], black, List2Row[r].Title); //�����̕\��
				if (List2Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List2.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea_p[AreaNumber].Active = 1;
				}
			}

			if (EditorSettingsFlag > 0) {
				if (EditorSettingsFlag == 1) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea_p[AreaNumber].Active = 0;
				}
				
				int Value = SettingPreviewMode(DisplayArea_Preview_FilePath_h, DisplayArea_p, BorderColorRGB_h, BackColorRGB_h, BackImgPath_h, Area_Kosuu, AreaNumber, &EditorSettingsFlag);
				if (Value == 1 || Value == -1) {
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�BackImgPath_h[AreaNumber]
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea_p[AreaNumber].Active = 1;
				}


			}
			//���J�[�\���I�[�o�[
			static const int BackColor = GetColor(230, 255, 230);//R:255 G:255 B:204
			Math_CursorOver(ActiveMath::MouseX, ActiveMath::MouseY + 20, 2, black, BackColor, NULL);//Math_ButtonTitleShow(const int LocationX, const int LocationY, const int Padding, const int StringColor, const int BackColor, const int Type)

			//���}���`�K�C�h
			MultiGuide();
			//���T���v���̐��������i�R���g���[���{R�j
			if (ActiveMath::Key[KEY_INPUT_R] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {
				for (int i = 0; i < ToolKosuu; i++) Tool[i].Active = 1;
				for (int i = 0; i < List0RowKosuu; i++) List0Row[i].Active = 1;
				for (int i = 0; i < List1RowKosuu; i++) List1Row[i].Active = 1;
				for (int i = 0; i < List2RowKosuu; i++) List2Row[i].Active = 1;
			}

		}
	}
	return 0;
}
//�ڍוҏW�̏I��


//�p�b�h�r���[�A
int PadPreviewMode(int *EditorMode_p, char* FilePath_Pad_h) {
	//char Directory_PadSet[MAX_PATH];//���p�f�B���N�g�����L�^
	//GetCurrentDirectory(MAX_PATH, Directory_PadSet);
	SetCurrentDirectory(AppDir);
	//if (ActiveMath::FilePath_PadArea[0] == '\0') return 0;
	//char FileTitle_PadArea[MAX_PATH];//�X�e�[�^�X�o�[�ɕ\���p
	//GetTitleFromPath(FilePath_Pad_h, FilePath_Pad_h);//���΃p�X����t�@�C�������擾 �_�C�A���O���Ɏ擾�������̂��g������s�v�@�ݒ�t�@�C�����烍�[�h����Ƃ��̓_�C�A���O�ł͂Ȃ����烍�[�h�֐����ł��̊֐����g���Ă���B
	//////////�c�[���{�^��////////////
	int ButtonStrLen;

	//���c�[���o�[
	static struct AREACONTROL Toolbar[3] = { 0 };
	for (int AreaN = 0; AreaN < 3; AreaN++) {
		for (int i = 0; i < 4; i++) Toolbar[AreaN].Padding[i] = 1;
		Toolbar[AreaN].Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	}
	Toolbar[0].Width = 208;//140+0+0+
	Toolbar[0].Height = 28;//
	Toolbar[0].BackColor = GetColor(51, 102, 153);//204, 204, 204 R:51 G:102 B:153//102, 153, 204
	Toolbar[1].Location[0] = -111111;//�����s�̉E�ׂɔz�u
	Toolbar[1].Width = WindowWidth;
	Toolbar[1].Height = 28;//
	Toolbar[1].BackColor = GetColor(51, 102, 153);//204, 204, 204 R:51 G:102 B:153//102, 153, 204
	Toolbar[2].Location[1] = -111111;//�����̍��[�ɔz�u
	Toolbar[2].Width = WindowWidth;
	Toolbar[2].Height = 24;
	Toolbar[2].BackColor = GetColor(240, 240, 240);//204, 204, 204

	//���{�^��A�t�H�[��
	static struct BUTTONFORM ToolAForm = { 0 };
	for (int i = 0; i < 4; i++) ToolAForm.Margin[i] = 1;
	ToolAForm.CursorColor = GetColor(255, 255, 204);

	//���c�[���{�^��A
	const int ToolAKosuu = 3;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
	static struct BUTTONCONTROL ToolA[ToolAKosuu] = { 0 };
	strcpy(ToolA[0].Title, "�t�@�C��");
	strcpy(ToolA[1].Title, "�J�X�^�}�C�Y");
	strcpy(ToolA[2].Title, "�ݒ�");

	for (int b = 0; b < ToolAKosuu; b++) {
		ToolA[b].ParentArea_p = &Toolbar[0];
		if (b > 0) ToolA[b].Location[0] = -111111;
		for (int i = 0; i < 4; i++) ToolA[b].Padding[i] = 5;
		ToolA[b].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolA[b].ButtonForm_p = &ToolAForm;
	}

	//���c�[���{�^��B�t�H�[��
	static struct BUTTONFORM ToolBForm = { 0 };
	for (int i = 0; i < 4; i++) ToolBForm.Margin[i] = 1;
	ToolBForm.CursorColor = GetColor(255, 255, 204);

	//���c�[���{�^��B
	const int ToolBKosuu = 5;//�{�^���z��̌��@���@�z��v�f���iMax�͂Ȃ��j
	static struct BUTTONCONTROL ToolB[ToolBKosuu] = { 0 };

	strcpy(ToolB[0].String, "�z�[����ʂɖ߂�");
	if (ToolB[0].WaitingImg == -1) {
		ToolB[0].WaitingImg = LoadGraph(".\\System\\Fixed\\home24.png");
		ToolB[0].CursorImg = LoadGraph(".\\System\\Fixed\\home24b.png");
		ToolB[0].PushedImg = ToolB[0].CursorImg;
	}
	strcpy(ToolB[1].String, "�t�@�C�����J��");
	if (ToolB[1].WaitingImg == -1) {
		ToolB[1].WaitingImg = LoadGraph(".\\System\\Fixed\\open24.png");
		ToolB[1].CursorImg = LoadGraph(".\\System\\Fixed\\open24b.png");
		ToolB[1].PushedImg = ToolB[1].CursorImg;
	}
	strcpy(ToolB[2].String, "�N���A�[");
	if (ToolB[2].WaitingImg == -1) {
		ToolB[2].WaitingImg = LoadGraph(".\\System\\Fixed\\clear24.png");
		ToolB[2].CursorImg = LoadGraph(".\\System\\Fixed\\clear24b.png");
		ToolB[2].PushedImg = ToolB[2].CursorImg;
	}
	strcpy(ToolB[3].String, "���̓��[�h�̕ύX");
	if (ToolB[3].WaitingImg == -1) {
		ToolB[3].WaitingImg = LoadGraph(".\\System\\Fixed\\joypad24.png");
		ToolB[3].CursorImg = LoadGraph(".\\System\\Fixed\\joypad24b.png");
		ToolB[3].PushedImg = ToolB[3].CursorImg;
	}
	strcpy(ToolB[4].String, "�ڍוҏW");
	if (ToolB[4].WaitingImg == -1) {
		ToolB[4].WaitingImg = LoadGraph(".\\System\\Fixed\\edit24.png");
		ToolB[4].CursorImg = LoadGraph(".\\System\\Fixed\\edit24b.png");
		ToolB[4].PushedImg = ToolB[4].CursorImg;
	}

	for (int b = 0; b < ToolBKosuu; b++) {
		ToolB[b].ParentArea_p = &Toolbar[1];
		if (b > 0)  ToolB[b].Location[0] = -111111;
		ToolB[b].Padding[0] = 6; ToolB[b].Padding[1] = 3; ToolB[b].Padding[2] = 6; ToolB[b].Padding[3] = 3;//
		ToolB[b].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolB[b].ButtonForm_p = &ToolBForm;

	}

	const char TextBoxTitle_Text[] = "Text";//���ӁFText�Ƃ������O�̕ϐ��ɂ��܂���"Text"�Ƃ��������񂪓����Ă���
	static struct AREACONTROL TextBoxTitle = { 0 };
	TextBoxTitle.ParentArea_p = &Toolbar[2];
	for (int i = 0; i < 4; i++) TextBoxTitle.Margin[i] = 1;
	TextBoxTitle.BorderThickness = 0;
	TextBoxTitle.Padding[0] = 3;
	TextBoxTitle.Padding[1] = 3;
	TextBoxTitle.Padding[2] = 3;
	TextBoxTitle.Padding[3] = 0;//
	TextBoxTitle.Width = 0;
	TextBoxTitle.Height = 20;
	TextBoxTitle.BorderColor = gray30;
	TextBoxTitle.Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
	////////
	int TextBoxTitleStrLen = strlen(TextBoxTitle_Text);
	if (TextBoxTitle.Width == 0) TextBoxTitle.Width = GetDrawStringWidth(TextBoxTitle_Text, TextBoxTitleStrLen) + TextBoxTitle.Padding[0] + TextBoxTitle.Padding[2] + TextBoxTitle.BorderThickness * 2;
	//if (TextBoxTitle.Height == 0) TextBoxTitle.Height = systemfontsize + TextBoxTitle.Padding[1] + TextBoxTitle.Padding[3] + TextBoxTitle.BorderThickness * 2;

	static struct AREACONTROL TextBox = { 0 };
	TextBox.ParentArea_p = &Toolbar[2];
	TextBox.Location[0] = TextBoxTitle.Location[0] + TextBoxTitle.Margin[0] + TextBoxTitle.Width + TextBoxTitle.Margin[2];
	TextBox.Margin[0] = 1;
	TextBox.Margin[1] = 1;
	TextBox.Margin[2] = 10;
	TextBox.Margin[3] = 1;
	TextBox.BorderThickness = 1;
	TextBox.Padding[0] = 2;
	TextBox.Padding[1] = 2;
	TextBox.Padding[2] = 0;
	TextBox.Padding[3] = 0;//
	TextBox.Width = 250;//0�Ȃ�I�[�g�T�C�Y
	TextBox.Height = 20;//0�Ȃ�I�[�g�T�C�Y
	TextBox.BackColor = gray60;
	TextBox.BorderColor = gray30;
	TextBox.Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����

	static const char StringBoxTitle_Text[] = "String";
	static struct AREACONTROL StringBoxTitle = { 0 };
	StringBoxTitle.ParentArea_p = &Toolbar[2];
	StringBoxTitle.Location[0] = TextBox.Location[0] + TextBox.Margin[0] + TextBox.Width + TextBox.Margin[2];
	for (int i = 0; i < 4; i++) StringBoxTitle.Margin[i] = 1;
	StringBoxTitle.BorderThickness = 0;
	StringBoxTitle.Padding[0] = 3;
	StringBoxTitle.Padding[1] = 3;
	StringBoxTitle.Padding[2] = 3;
	StringBoxTitle.Padding[3] = 0;//
	StringBoxTitle.Width = 0;
	StringBoxTitle.Height = 20;
	StringBoxTitle.BorderColor = gray30;
	StringBoxTitle.Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		////////
	int StringBoxTitleStrLen = strlen(StringBoxTitle_Text);
	if (StringBoxTitle.Width == 0) StringBoxTitle.Width = GetDrawStringWidth(StringBoxTitle_Text, StringBoxTitleStrLen) + StringBoxTitle.Padding[0] + StringBoxTitle.Padding[2] + StringBoxTitle.BorderThickness * 2;
	//if (StringBoxTitle.Height == 0) StringBoxTitle.Height = systemfontsize + StringBoxTitle.Padding[1] + StringBoxTitle.Padding[3] + StringBoxTitle.BorderThickness * 2;

	static struct AREACONTROL StringBox = { 0 };
	StringBox.ParentArea_p = &Toolbar[2];
	StringBox.Location[0] = StringBoxTitle.Location[0] + StringBoxTitle.Margin[0] + StringBoxTitle.Width + StringBoxTitle.Margin[2];
	StringBox.Margin[0] = 1;
	StringBox.Margin[1] = 1;
	StringBox.Margin[2] = 10;
	StringBox.Margin[3] = 1;
	StringBox.BorderThickness = 1;
	StringBox.Padding[0] = 2;
	StringBox.Padding[1] = 2;
	StringBox.Padding[2] = 0;
	StringBox.Padding[3] = 0;//
	StringBox.Width = 250;//0�Ȃ�I�[�g�T�C�Y
	StringBox.Height = 20;//0�Ȃ�I�[�g�T�C�Y
	StringBox.BackColor = gray60;
	StringBox.BorderColor = gray30;
	StringBox.Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
	//���c�[���{�^��C�t�H�[��
	static struct BUTTONFORM ToolCForm = { 0 };
	for (int i = 0; i < 4; i++) ToolCForm.Margin[i] = 1;
	ToolCForm.CursorColor = GetColor(255, 255, 204);


	//���c�[���{�^��C
	const int ToolCKosuu = 2;//�{�^���z��̌��@���@�z��v�f���iMax�͂Ȃ��j
	//const int ToolCEnd = ToolCKosuu;//�ŏI�{�^���̗v�f�ԍ��i�z��̗v�f�����P���������Ă����Ƃ悢�j�i�{�^���������o���Ƃ��Ɏg�p����j
	static struct BUTTONCONTROL ToolC[ToolCKosuu] = { 0 };
	strcpy(ToolC[0].Title, "<<�O�̃V�[�g");
	strcpy(ToolC[1].Title, "���̃V�[�g>>");

	for (int b = 0; b < ToolCKosuu; b++) {
		ToolC[b].ParentArea_p = &Toolbar[2];
		if (b == 0) ToolC[b].Location[0] = StringBox.Location[0] + StringBox.Margin[0] + StringBox.Width + StringBox.Margin[2];
		else ToolC[b].Location[0] = -111111;
		ToolC[b].Padding[0] = 6; ToolC[b].Padding[1] = 3; ToolC[b].Padding[2] = 6; ToolC[b].Padding[3] = 3;//
		ToolC[b].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolC[b].ButtonForm_p = &ToolCForm;
	}

	//�G�f�B�^�[�̐ݒ�i�v���r���[�p�f�B�X�v���C�G���A�j�̎擾
	int SettingEditorBackFlag = 0;
	const int DisplayArea_Preview_Kosuu = 2;
	char BackImgPath[DisplayArea_Preview_Kosuu][MAX_PATH] = { 0 };//�w�i�摜�t�@�C�����擾�p
	int BorderColorRGB[DisplayArea_Preview_Kosuu][3] = { 0 };//�w�i�F��RGB�擾�p
	int BackColorRGB[DisplayArea_Preview_Kosuu][3] = { 0 };//�w�i�F��RGB�擾�p
	static struct AREACONTROL DisplayArea_Preview[DisplayArea_Preview_Kosuu] = { 0 };
	SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	char DisplayArea_Preview_FilePath[MAX_PATH] = ".\\System\\BackImg\\BackImgPath_Pad.txt";
	LoadEditorSettings(DisplayArea_Preview_FilePath, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview, DisplayArea_Preview_Kosuu);


	const int DisplayArea_Kosuu = 2;

	static struct AREACONTROL DisplayArea[DisplayArea_Kosuu] = { 0 };
	//�����b�Z�[�W���̓G���A
	DisplayArea[0].Location[1] = 28+24;// Toolbar[2].Location[1] + Toolbar[2].Margin[1] + Toolbar[2].Height + Toolbar[2].Margin[3];
	for (int i = 0; i < 4; i++) DisplayArea[0].Padding[i] = 10;
	DisplayArea[0].Width = WindowWidth;//140+0+0+
	DisplayArea[0].Height = 78;//�ǂ����펞�X�V����
	DisplayArea[0].BorderColor = GetColor(153, 153, 153);//= NULL; 
	DisplayArea[0].Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���




	//���p�b�h�\���G���A
	DisplayArea[1].Location[1] = 80;
	for (int i = 0; i < 4; i++) DisplayArea[1].Padding[i] = 10;
	DisplayArea[1].Width = WindowWidth;
	DisplayArea[1].Height = WindowHeight - 24 - 42 - 24;//WindowHeight = 24 + 34 + 750 + 24
	DisplayArea[1].BorderColor = GetColor(153, 153, 153);//NULL;
	DisplayArea[1].Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	DisplayArea[1].Line[0] = 0;
	DisplayArea[1].Line[1] = 0;
	DisplayArea[1].Line[2] = WindowWidth;//(WindowWidth==1000)
	DisplayArea[1].Line[3] = 0;



	//////////////////////////////////////////////////



	//���X�e�[�^�X�o�[
	static struct AREACONTROL Statusbar = { 0 };
	Statusbar.Width = WindowWidth;
	Statusbar.Height = 24;//������v���̂���Location[1]����ɏ�����
	Statusbar.Location[1] = WindowHeight - Statusbar.Height;
	for (int i = 0; i < 4; i++) Statusbar.Padding[i] = 5;
	Statusbar.BackColor = GetColor(240, 240, 240);
	Statusbar.Active = 1;

	//////////�v���_�E�����X�g////////////
	int ListStrLen;//�^�C�g���̕�����
	int ListStrWidth;//�^�C�g���̕�
	const int list_BackColor = GetColor(204, 204, 153);
	const int list_BorderColor = GetColor(153, 153, 102);
	const int List_CursorColor = GetColor(255, 255, 204);
	//���t�@�C���̃v���_�E�����X�g
	const int List0RowKosuu = 3;
	ListStrWidth = GetDrawStringWidth("�A�v���P�[�V�����̏I��", strlen("�A�v���P�[�V�����̏I��"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List0 = { 0 };
	List0.ParentButton_p = &ToolA[0];//�t�@�C���{�^��
	List0.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List0.Padding[i] = 2;
	List0.BackColor = list_BackColor;
	List0.BorderColor = list_BorderColor;
	List0.CursorColor = List_CursorColor;

	List0.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List0.RowKosuu = List0RowKosuu;
	for (int i = 0; i < 4; i++) List0.RowPadding[i] = 5;
	List0.RowWidth = ListStrWidth + List0.RowPadding[0] + List0.RowPadding[2];
	List0.RowHeight = SystemFontSize + List0.RowPadding[1] + List0.RowPadding[3];
	/////////
	List0.Width = List0.RowWidth + List0.Padding[0] + List0.Padding[2] + List0.BorderThickness * 2;
	List0.Height = List0.RowHeight * List0.RowKosuu + List0.Padding[1] + List0.Padding[3] + List0.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List0Row[List0RowKosuu] = { 0 };
	for (int i = 0; i < List0RowKosuu; i++) List0Row[i].List_p = &List0;
	strcpy(List0Row[0].Title, "�t�@�C�����J��");
	strcpy(List0Row[1].Title, "�z�[���ɖ߂�");
	strcpy(List0Row[2].Title, "�A�v���P�[�V�����̏I��");

	//���X�^�C���̃v���_�E�����X�g
	const int List1RowKosuu = 5;
	ListStrWidth = GetDrawStringWidth("�W���C�p�b�h�̊��蓖�Ă̕ύX", strlen("�W���C�p�b�h�̊��蓖�Ă̕ύX"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List1 = { 0 };
	List1.ParentButton_p = &ToolA[1];//�t�@�C���{�^��
	List1.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List1.Padding[i] = 2;
	List1.BackColor = list_BackColor;
	List1.BorderColor = list_BorderColor;
	List1.CursorColor = List_CursorColor;
	List1.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List1.RowKosuu = List1RowKosuu;
	for (int i = 0; i < 4; i++) List1.RowPadding[i] = 5;
	List1.RowWidth = ListStrWidth + List1.RowPadding[0] + List1.RowPadding[2];
	List1.RowHeight = SystemFontSize + List1.RowPadding[1] + List1.RowPadding[3];
	/////////
	List1.Width = List1.RowWidth + List1.Padding[0] + List1.Padding[2] + List1.BorderThickness * 2;
	List1.Height = List1.RowHeight * List1.RowKosuu + List1.Padding[1] + List1.Padding[3] + List1.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List1Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List1RowKosuu; i++) List1Row[i].List_p = &List1;
	strcpy(List1Row[0].Title, "�X�^�C���̕ۑ�");
	strcpy(List1Row[1].Title, "�t�H���g�Z�b�g�̕ύX");
	strcpy(List1Row[2].Title, "�t�H���g�摜�Z�b�g�̕ύX");
	strcpy(List1Row[3].Title, "�^�O�Z�b�g�̕ύX");
	strcpy(List1Row[4].Title, "�W���C�p�b�h�̊��蓖�Ă̕ύX");

	//���ݒ�̃v���_�E�����X�g
	const int List2RowKosuu = 1;
	ListStrWidth = GetDrawStringWidth("�w�i�̕ύX", strlen("�w�i�̕ύX"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List2 = { 0 };
	List2.ParentButton_p = &ToolA[2];//�t�@�C���{�^��
	List2.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List2.Padding[i] = 2;
	List2.BackColor = list_BackColor;
	List2.BorderColor = list_BorderColor;
	List2.CursorColor = List_CursorColor;
	List2.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List2.RowKosuu = List2RowKosuu;
	for (int i = 0; i < 4; i++) List2.RowPadding[i] = 5;
	List2.RowWidth = ListStrWidth + List2.RowPadding[0] + List2.RowPadding[2];
	List2.RowHeight = SystemFontSize + List2.RowPadding[1] + List2.RowPadding[3];
	/////////
	List2.Width = List2.RowWidth + List2.Padding[0] + List2.Padding[2] + List2.BorderThickness * 2;
	List2.Height = List2.RowHeight * List2.RowKosuu + List2.Padding[1] + List2.Padding[3] + List2.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List2Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List2RowKosuu; i++) List2Row[i].List_p = &List2;//������
	strcpy(List2Row[0].Title, "�w�i�̕ύX");




	///////////////////////
		//�p�b�h�v���r���[
		//�k�𓚗p�̃p�b�h�l
	struct PadManager PadManager;//static�ɂ�������Ȃ����x�Ƀp�����[�^�𖈉񃊃Z�b�g

	//���G���A�i[0]�C���f�b�N�X�G���A�C[1]�{�^���G���A�C[2]�x�[�X�{�^���G���A�̌v3�j
	const int PadAreaMax = 3;
	int PadAreaKosuu;
	struct AREACONTROL PadArea[PadAreaMax] = { 0 };

	//���{�^���t�H�[���i�ő�10�j
	const int ButtonFormMax = 10;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
	int ButtonFormKouu;//�ŏI�{�^���̗v�f�ԍ��i���[�h���Ɏ擾�j�i�{�^���������o���Ƃ��Ɏg�p����j
	struct BUTTONFORM ButtonForm[ButtonFormMax] = { 0 };
	//�����͗p�C���f�b�N�X�i�ő�20�j
	const int IndexMax = 20;
	int IndexKosuu=0;//�C���f�b�N�X�̌��i���[�h���Ɏ擾�j

	struct BUTTONCONTROL Index[IndexMax] = { 0 };
	//�����͗p�{�^���i�e�V�[�g�ő�100�j
	const int ButtonMax[IndexMax] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };//�{�^���z��̗v�f��
	int ButtonKosuu[IndexMax] = { 0 };//�{�^���̌��i���[�h���Ɏ擾�j�i�{�^���������o���Ƃ��Ɏg�p����j

	static struct INPUTTEXTBUTTONCTRL Button0[100];
	static struct INPUTTEXTBUTTONCTRL Button1[100];
	static struct INPUTTEXTBUTTONCTRL Button2[100];
	static struct INPUTTEXTBUTTONCTRL Button3[100];
	static struct INPUTTEXTBUTTONCTRL Button4[100];
	static struct INPUTTEXTBUTTONCTRL Button5[100];
	static struct INPUTTEXTBUTTONCTRL Button6[100];
	static struct INPUTTEXTBUTTONCTRL Button7[100];
	static struct INPUTTEXTBUTTONCTRL Button8[100];
	static struct INPUTTEXTBUTTONCTRL Button9[100];
	static struct INPUTTEXTBUTTONCTRL Button10[100];
	static struct INPUTTEXTBUTTONCTRL Button11[100];
	static struct INPUTTEXTBUTTONCTRL Button12[100];
	static struct INPUTTEXTBUTTONCTRL Button13[100];
	static struct INPUTTEXTBUTTONCTRL Button14[100];
	static struct INPUTTEXTBUTTONCTRL Button15[100];
	static struct INPUTTEXTBUTTONCTRL Button16[100];
	static struct INPUTTEXTBUTTONCTRL Button17[100];
	static struct INPUTTEXTBUTTONCTRL Button18[100];
	static struct INPUTTEXTBUTTONCTRL Button19[100];
	static struct INPUTTEXTBUTTONCTRL* Button_ph[] = { Button0, Button1, Button2, Button3, Button4, Button5, Button6, Button7, Button8, Button9,
		Button10, Button11, Button12, Button13, Button14, Button15, Button16, Button17, Button18, Button19
	};
	//�����͗p��{�{�^���i�ő�100�j
	const int BaseButtonMax = 100;
	int BaseButtonKosuu=0;//��{�{�^���̌��i���[�h���Ɏ擾�j

	struct INPUTTEXTBUTTONCTRL BaseButton[BaseButtonMax] = { 0 };
	//�����b�Z�[�W
	const int MsgCharMax = 2000;//MsgCharMax�͏I�[�������܂܂Ȃ��B�I�[�������܂߂� MsgCharMax + 1 �͕ϐ���MsgSize�ƕ\�����ƂƂ���B
	char Message_Master[MsgCharMax + 1] = { "<math></math>" }; //���b�Z�[�W������

	//�����b�Z�[�W�t�H�[���i�}�X�^�[�j
	const int MsgBoxForm_Kosuu = 1;
	struct MsgBoxForm MsgBoxForm;
	static struct MsgBoxForm_RGB_SoundPath MsgBoxForm_RGB_SoundPath;//�F�C�����̓n���h���ł͂Ȃ��C�F��RGB�l�C������LocalDir����̑��΃p�X���L�^�i�l�̕ύX��ۑ��Ŏg�p�j

	//�����b�Z�[�W�R���g���[���i�}�X�^�[�j
	const int MsgBoxCtrl_Kosuu = 1;
	int MsgBoxCtrlmEnd;
	struct MsgBoxCtrl MsgBoxCtrl_Master = { 0 };//���t�g�o�[�iHeight�j�C���b�Z�[�W�v���r���[�i�|�C���^�[�A�h���X�j�C�p�b�h�v���r���[�i�|�C���^�[�A�h���X�j�Ŏg�p
	int FormNumberOfMsgCtrs = 0;

	//�^�C�g��
	char AppMode_text[MAX_PATH];
	strcpy(AppMode_text, ApplicationTitle);//�A�v���P�[�V����������
	strcat(AppMode_text, " - �p�b�h�r���[�A - ");//�t�@�C������A��
	char Titlebar_text[MAX_PATH];
	char FileTitle_Pad[MAX_PATH] = { 0 };//���t�@�C�������擾����ϐ�
	if (FilePath_Pad_h[0] != '\0') GetTitleFromPath(FileTitle_Pad, FilePath_Pad_h);//�t�@�C���p�X����t�@�C�������擾�i�t�@�C���p�X��"����"�̂Ƃ��̓t�@�C������"����"�j
	static char PadDir[MAX_PATH] = { 0 };
		//////////���J���̂Ƃ��i�t�@�C���p�X���Ȃ��j��C�t�@�C������"����"�i�V�K�쐬�j�̂Ƃ��j
	if (FilePath_Pad_h[0] != '\0') {
		//�f�B���N�g���̎擾�i�t�@�C�����̑O��\\�̈ʒu��T���j
		strcpy(PadDir, FilePath_Pad_h);
		int mojisuu = strlen(PadDir);
		int count;
		for (count = 1; PadDir[mojisuu - count] != '\\' && count < MAX_PATH; count++);//
		PadDir[mojisuu - count] = '\0';

		char DirectoryNow1[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p

				//SetCurrentDirectory(ActiveDirectory_h);//�f�B���N�g����ύX����
				//���p�b�h�G���A�C���͗p�C���f�b�N�X�C���͗p�{�^���C���͗p��{�{�^���̃��[�h�iLocalDir�̓p�b�h�G���A�Ɠ����̃f�B���N�g���ƂȂ�j
		int Error;
		switch (Error = LoadPad(FilePath_Pad_h, PadArea, &PadAreaKosuu, PadAreaMax, &DisplayArea[1],
			ButtonForm, &ButtonFormKouu, ButtonFormMax,
			Index, &IndexKosuu, IndexMax,
			Button_ph, ButtonKosuu, ButtonMax,
			BaseButton, &BaseButtonKosuu, BaseButtonMax,
			Message_Master, MsgCharMax, 1, &MsgBoxForm, MsgBoxForm_Kosuu, &MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, 1, 1
		)) {

		//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�G���A�Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�G���A�̃p�����[�^������܂���B", black, gray60); break;
		case -3: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�G���A�̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		//case -11: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�{�^���t�H�[���Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -12: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�{�^���t�H�[���̃p�����[�^������܂���B", black, gray60); break;
		case -13: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�{�^���t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		//case -21: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�C���f�b�N�X�Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -22: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�C���f�b�N�X�̃p�����[�^������܂���B", black, gray60); break;
		case -23: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�C���f�b�N�X�̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		//case -31: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�{�^���Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -32: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�{�^���̃p�����[�^������܂���B", black, gray60); break;
		case -33: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�{�^���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		//case -41: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�x�[�X�{�^���Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -42: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�x�[�X�{�^���̃p�����[�^������܂���B", black, gray60); break;
		case -43: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�x�[�X�{�^���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		//case -51: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -52: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃p�����[�^������܂���B", black, gray60); break;//���`�F�b�N
		case -53: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//���`�F�b�N
		//case -61: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -62: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃p�����[�^������܂���B", black, gray60); break;//���`�F�b�N
		case -63: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//���`�F�b�N
		//case -71: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -72: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃p�����[�^������܂���B", black, gray60); break;//���`�F�b�N
		}
		if (Error < -1 && Error != -11 && Error != -21 && Error != -31 && Error != -41 && Error != -51 && Error != -61 && Error != -71 && Error != -81) {
			WaitKey();
			FilePath_Pad_h[0] = '\0';//�t�@�C���p�X������
			ClearDrawScreen();
			return -1;
		}
		//���I�����̓p�b�h�t�@�C���Ɠ����̃f�B���N�g��
		//MsgBoxForm_RGB_SoundPath�̎擾�i�F�̒l�C���̃p�X�j
		LoadMsgBoxForm_RGB_SoundPath(".\\MsgBoxForm.txt", &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);//�t�@�[���̃Z�[�u�����邽�߁CLoadMsgBoxForm2�����[�h���Ă����K�v������B

		//���^�C�g���o�[�̃e�L�X�g�̍X�V
		strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
		strcat(Titlebar_text, FileTitle_Pad);//�t�@�C������A��
		SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������

	}

	int ExitModeFlag = 0;
	while (!ExitModeFlag && ProcessMessage() == 0) {
		DisplayArea[0].BackColor = DisplayArea_Preview[0].BackColor;
		DisplayArea[0].BackImg = DisplayArea_Preview[0].BackImg;

		DisplayArea[1].BackColor = DisplayArea_Preview[1].BackColor;
		DisplayArea[1].BackImg = DisplayArea_Preview[1].BackImg;

		//�k���͂������b�Z�[�W�̃��Z�b�g�l
		//�����b�Z�[�W�v���p�e�B*MsgBoxCtrl_p
		struct MsgBoxCtrl MsgBoxCtrl = MsgBoxCtrl_Master;//
		MsgBoxCtrl.ParentArea_p = &DisplayArea[0];
		MsgBoxCtrl.Location[0] = 0;//���P�[�V�����̓��[�h�����l�ł͂Ȃ�0�ɂ���
		MsgBoxCtrl.Location[1] = 0;


		//MsgBoxCtrl.Active = 2;//Active=1�ҏW���[�h�ɂ����ɁC�t�H�[���ł��܂������悤�ɐݒ肷�邱�ƁH�H�H�H
		//Active=1�F�ҏW���[�h�@�Q�F���H���[�h0709 
		//�ҏW���[�h�̂�(�^�C�v���Ȃ�)�N���b�N����*ActiveElement = 0�C�@�@�@�ҏW���[�h��(�^�C�v���܂���)�����L�k�^�C�v��Height��OuterHeight�̍X�V�j//
		//���H���[�h�̂�(�^�C�v���ł͂Ȃ��Ȃ�)�����o�����@�@�@�@�@�@�@�@�@�@���H���[�h�̂�MessScroll�֐����Ń^�C�v���ƂɃ��b�Z�[�W�̃X�N���[��(�^�C�v���w�肵�Ȃ�)
		//���H���[�h�̂݃^�C�v���Ƃ�StartingPointX��Y�𓮂���(�^�C�v���w�肵�Ȃ�)�@�@�@�@�@�@�@�@�@�@�@�@ �@���H���[�h(�^�C�v���ł͂Ȃ��Ȃ�)����OutputSpeed >= 0��kakumojisuu�̍X�V
		//���H���[�h�̂݁H�i�S�^�C�v�ɂ���������֌W�Ȃ��j�u���b�Z�[�W���Ō�܂ŏ����o�����v�u�����o�������ƃ{�^�����������v�̃T�C���𑗂鏈��
		//���H���[�h�̂�Option100�`103���[��艺�ŗ̈�O�ʂ��i�^�C�v����100�`103�ɊY�����Ȃ��̂ŏ����s�v�@�g���j�C�@�@Option == 110��afuresyori�i�^�C�v����100�`103�ɊY�����Ȃ��̂ŏ����s�v�@�g���j
		char Message[MsgCharMax + 1];
		strcpy(Message, Message_Master);
		MsgBoxCtrl.Tag[0].PositionP = 0;//tag[0].PositionP��ActiveElement�̑�p		  //0�F�������݊J�n�@-1�F�������ݕs��


		int nukeru = 0;

		//�O�t���[���̂Ƃ��̏����o��
		DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);


		////////�p�b�h�v���r���[��ʂ̃��C�����[�v
		for (int frameH = 0; !nukeru && !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !MathgpUpdateMouse() && !MathgpUpdateKey() && !MathgpUpdateJoypad(); frameH++) {//�}�E�X�E�L�[�{�[�h�E�W���C�p�b�h
			//������������ҋ@
			SleepToFitFPS(FPS);
			//�c�[���o�[
			ShowArea(Toolbar, 3);
			////�@�c�[���o�[A�@////
			static int ClickedNoA = -1;//�����ꂽ�{�^���ԍ�
			//���c�[���i�v���_�E�����X�g�j
			int ToolA_PushType = 0; int ToolA_Prev = -2; int ToolA_Next = -2;
			if (ShowButton(ToolA, ToolAKosuu, &ClickedNoA, ToolA_PushType, ToolA_Prev, ToolA_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				//�t�@�C���܂��̓X�^�C�����������u��
				if (ClickedNoA >= 0) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					//for (int i = 0; i < 3; i++) PadArea[i].Active = 2;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~190803
					//PadArea[2].Active = 2;
					DisplayArea[1].Active = 2;
					DisplayArea[0].Active = 0;

					//���X�g���J���Ă��Ȃ���Ԃł̃N���b�N��
					//Mouse[MOUSE_INPUT_LEFT] = 2�́C�v���_�E�����X�g�������ɏ����Ă��܂��̂�h���i���X�g�͈̔͊O�N���b�N�ɊY�����邽�߁j�i�O�͂��߁B���̃��[�v�łɂ܂��P�ɂȂ��Ă��܂��j
					if (ClickedNoA == 0 && List0.Active != 1) { List0.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 1 && List1.Active != 1) { List1.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 2 && List2.Active != 1) { List2.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
				}

			}

			//�t�@�C���܂��̓X�^�C��������������
			else if (List0.Active == 1 || List1.Active == 1 || List2.Active == 1) {//�v���_�E����ԂŃJ�[�\�����w���{�^��������Ƃ�
				for (int i = 0; i < ToolAKosuu; i++) {
					if (ToolA[i].Active == 3) {//�J�[�\�����w���Ă���Ƃ���PulldownFlag������������
						if (i == 0) { List0.Active = 1; List1.Active = -1;  List2.Active = -1; }
						else if (i == 1) { List0.Active = -1; List1.Active = 1;  List2.Active = -1; }
						else if (i == 2) { List0.Active = -1; List1.Active = -1;  List2.Active = 1; }
						break;
					}
				}
			}






			//���c�[���{�^��
			//�{�^���@Button_p->Active�i-�P�F��\���@�O�F�g�p�s��ԁi�{�^���̃^�C�g���𔖂��\�����Ė������j�@�P�F�ҋ@��ԁi�{�^���̕\���E�����j�@�Q�F�����ꂽ��ԁ@�R�F�J�[�\���j
			//�G���A�@AreaCtrl_p->Active�i-�P�F��\���@�O�F�g�p�s��ԁi�{�^���̃^�C�g���𔖂��\�����Ė������j�@�P�F�ҋ@��ԁi�{�^���̕\���E�����j�@�Q�F�{�^����\�����邪�������j
			//ToolB[0].Active = 0;//�g�p�s��ԁi�^�C�g�������j//Active �� 0�ɂ���΁C�N���b�N���̏����̂Ƃ����/*�@*/�ň͂ޕK�v�͂Ȃ�
			//ToolB[2].Active = 0;//�g�p�s��ԁi�^�C�g�������j
			//AreaControlShow(&ToolbarB, 1);
			int ClickedNo = -1;//�����ꂽ�{�^���ԍ�

			int ToolB_PushType = 0; int ToolB_Prev = -2; int ToolB_Next = -2;
			if (ShowButton(ToolB, ToolBKosuu, &ClickedNo, ToolB_PushType, ToolB_Prev, ToolB_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
			//ChangeType�i�O�F�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

			///////�V�K�쐬//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�iNULL�j�C�t�@�C���^�C�g���i����j�C�G�f�B�^�[���[�h�i����}�}�j�Ń��b�Z�[�W�ҏW���[�h���甲����

				///////�z�[���ɖ߂�
				if (ClickedNo == 0) {//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
					PadDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
					*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
					return 0;
				}

				///////�t�@�C�����J��
				else if (ClickedNo == 1) {
					//�_�C�A���O�Ńp�b�h�Z�b�g�̃t�@�C���p�X���擾
					if (PadDir == '\0') {
						strcpy(PadDir, AppDir);
						strcat(PadDir, "\\OriginalFile\\PadData");
					}
					//PadDir�̓p�b�h�t�@�C��������f�B���N�g���BPadDir���J���̂Ƃ��́u�`\\�p�b�h�Z�b�g�v
					char filepath[MAX_PATH]; char filetitle[MAX_PATH];
					if (GetOpenFileNameACP(PadDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I�����̃J�����g�f�B���N�g���̓p�b�h�Z�b�g�i�G���A�̃t�@�C���j������f�B���N�g���B�u�`\\�p�b�h�Z�b�g�v�Ƃ͌���Ȃ��̂Œ��ӁB
						//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
						//�J�����t�@�C���̃��[�h�𒲂ׂ�
						ClearDrawScreen();
						switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
						case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
							strcpy(FilePath_Pad_h, filepath);//�t�@�C���p�X�̊m��
							//if (*EditorMode_p != 2) PadDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
							return 0;//�p�b�h�v���r���[���[�h���甲����
						case -1:
							ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
							WaitKey(); break;
						default://�����icase -2�j�j
							ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
							WaitKey();
						}

					}
				}


				///////�ēǂݍ���
				else if (ClickedNo == 2) {//
					break;
				}
				///////���̓��[�h�̕ύX
				else if (ClickedNo == 3) {//
					if (ActiveMath::JoypadInputMode == 0) ActiveMath::JoypadInputMode = 1;//�A�i���O���[�h�ɕύX
					else ActiveMath::JoypadInputMode = 0;//�f�W�^�����[�h�ɕύX
				}
				///////���b�Z�[�W�v���r���[
				else if (ClickedNo == 4) {
					//�{���̒l�ɖ߂�   �p�b�h���[�h�͌���Ƃ��Ă͂��Ƃ��Ɩ{���̒l
					//MsgBoxForm = MsgBoxForm_Copy;
					//�v���r���[���[�h
					int MsgBoxCtrlNumber = 0;
					int MsgBoxFormNumber = 0;
					char MsgFilePath[MAX_PATH];
					strcpy(MsgFilePath, LocalDir);

					strcat(MsgFilePath, "\\Message.txt");
					int Area_Kosuu = 2;  int AreaNumber = 0;

					MessagePreviewMode(&MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, &MsgBoxForm, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, &MsgBoxFormNumber,
						Message_Master, MsgCharMax + 1, DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, Area_Kosuu, AreaNumber, //
						MsgFilePath, FileTitle_Pad, NULL, EditorMode_p, &ExitModeFlag//���ҏW���[�ǂ̂Ƃ���NULL�̂Ƃ��낪, &mondai�i����͖��t�@�C����ۑ�����̂ɕK�v������j
					);//�t�@�C���p�X�̓��b�Z�[�W�̃t�@�C���p�X�B�t�@�C�����̓p�b�h�̃t�@�C�����B

					if (ExitModeFlag) return 0;
					nukeru = 1;

				}

						//���b�Z�[�W�v���r���[, *MsgBoxCtrl_p�͏�����ԁB*MsgBoxCtrl_p��*MsgBoxForm_p�Ɗ֘A�Â��Ă���B???


			}

			//���c�[��
			//AreaControlShow(&ToolbarC, 1);
			//�e�L�X�g
			ShowArea(&TextBoxTitle, 1);
			DrawStringInArea(0, 0, &TextBoxTitle, TextBoxTitle_Text, black);
			ShowArea(&TextBox, 1);
			//�X�g�����O
			ShowArea(&StringBoxTitle, 1);
			DrawStringInArea(0, 0, &StringBoxTitle, StringBoxTitle_Text, black);
			ShowArea(&StringBox, 1);


			int ToolC_PushType = 0; int ToolC_Prev = -2; int ToolC_Next = -2;
			// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
			if (ShowButton(ToolC, ToolCKosuu, &ClickedNo, ToolC_PushType, ToolC_Prev, ToolC_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				//�O�̃V�[�g
				if (ClickedNo == 0) {
					Index[PadManager.IndexOn].Active = 1;
					PadManager.IndexOn--;
					if (PadManager.IndexOn < 0) PadManager.IndexOn = IndexKosuu - 1;//�V�[�g�P�܂Ői�񂾂�ŏI�V�[�g�ɐi�ށi���ӁF�O�Ԃ̊�{�V�[�g�͏�ɕ\�����Ă���j
					Index[PadManager.IndexOn].Active = 2;
				}
				//���̃V�[�g
				else if (ClickedNo == 1) {
					Index[PadManager.IndexOn].Active = 1;
					PadManager.IndexOn++;
					if (PadManager.IndexOn >= IndexKosuu) PadManager.IndexOn = 0;//�ŏI�̃V�[�g�܂Ői�񂾂�V�[�g�P�ɖ߂�i���ӁF�O�Ԃ̊�{�V�[�g�͏�ɕ\�����Ă��邩��P�ɖ߂��j
					Index[PadManager.IndexOn].Active = 2;
				}
			}
			//�C���v�b�g�G���A
			ShowArea(&DisplayArea[0], 1);//

			//�f�B�X�v���C�G���A
			//DisplayArea[1].Location[1] = DisplayArea[0].Nest[3] + DisplayArea[0].Padding[3] + DisplayArea[0].BorderThickness;
			DisplayArea[1].Location[1] = DisplayArea[0].Location[1] + DisplayArea[0].Height;
			ShowArea(&DisplayArea[1], 1);//



			//////////���t�@�C����������Ȃ珈�����Ȃ������̏�[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��////�N������C�A�v���͕����Ƀt�@�C���̂ݕ����Ƃ��B
			if (FilePath_Pad_h[0] != '\0') {
				//if (FilePath_Pad_h[0] != '\0' || strcmp(FileTitle_Pad, "����") == 0) {
				int ShowMsgBoxFlag = 1;//�O�F���b�Z�[�W�{�b�N�X��\�����Ȃ��@�O�ȊO�F���b�Z�[�W�{�b�N�X��\������
				if (ShowPadJ(Message, &MsgBoxCtrl, MsgCharMax + 1, ShowMsgBoxFlag, Index, IndexKosuu, Button_ph, ButtonKosuu, BaseButton, BaseButtonKosuu, PadArea, &PadManager) == 1) {//�v�b�V�������������P�̂Ƃ�
					if (PadManager.PushedNo == 35 && PadArea[2].Active == 1) {//�x�[�X�{�^����35�ԁi�m��{�^���j���N���b�N�����B�@�x�[�X�{�^���F1000�ԑ�
						nukeru = 1;//���͂������b�Z�[�W�����Z�b�g���邽�߂ɓ����̃��[�v�𔲂���
					}
				}
				if (MsgBoxCtrl.Condition == 101) {
					nukeru = 1;
				}

				DisplayArea[0].Nest[3] = DisplayArea[0].Nest[1] + MsgBoxCtrl.Location[1] + MsgBoxCtrl.OuterHeight;
				DisplayArea[0].Height = MsgBoxCtrl.OuterHeight + DisplayArea[0].Padding[1] + DisplayArea[0].Padding[3] + DisplayArea[0].BorderThickness * 2;

				DrawStringInArea(0, 0, &StringBox, PadManager.InputButton_p->ButtonCtrl.String, black);//�{�^����String������Ώ����o��
				DrawStringInArea(0, 0, &TextBox, PadManager.InputButton_p->PutText, black);//�}�E�X�I�[�o�[�����{�^����PutText������Ώ����o��
			}

			//////�X�e�[�^�X�o�[�̕\��
			ShowArea(&Statusbar, 1);

			static int StatusNumber = 0;//�p�b�h���[�h�̃X�e�[�^�X�o�[�̕\�����e��ύX�i�R���g���[���{S�j
			if (ActiveMath::Key[KEY_INPUT_S] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {//
				StatusNumber += 1;//
				if (StatusNumber == 7) StatusNumber = 0;
			}
			if (StatusNumber == 0) {
				static char DegitalMode[] = "�f�W�^��";
				static char AnalogMode[] = "�A�i���O";
				char *Mode_p;
				if (ActiveMath::JoypadInputMode == 0) Mode_p = DegitalMode;
				else Mode_p = AnalogMode;
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "���̓��[�h: %s  /  �C���f�b�N�X�̌�: %d  /  �{�^���̌�: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
					Mode_p, IndexKosuu, ButtonKosuu[0], ButtonKosuu[1], ButtonKosuu[2], ButtonKosuu[3], ButtonKosuu[4], ButtonKosuu[5], ButtonKosuu[6], ButtonKosuu[7], ButtonKosuu[8], ButtonKosuu[9],
					ButtonKosuu[10], ButtonKosuu[11], ButtonKosuu[12], ButtonKosuu[13], ButtonKosuu[14], ButtonKosuu[15], ButtonKosuu[16], ButtonKosuu[17], ButtonKosuu[18], ButtonKosuu[19]
				);
			}
			else if (StatusNumber == 1) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "PadManager.Duration: %d  /  PadManager.IndexOn: %d  /  PadArea[1].Active: %d  /  PadManager.PushedNo: %d",
					PadManager.Duration, PadManager.IndexOn, PadArea[1].Active, PadManager.PushedNo
					//PadArea[1].Active�i-�P�F��\���@�O�F�g�p�s��ԁi�{�^���̃^�C�g���𔖂��\�����Ė������j�@�P�F�ҋ@��ԁi�{�^���̕\���E�����j�@�Q�F�{�^����\�����邪�������j
				);
			}
			else if (StatusNumber == 2) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�t�H���g�Z�b�g: %s  /  �t�H���g�摜�Z�b�g: %s  /  �^�O�Z�b�g: %s", FileTitle_Font, FileTitle_FontImg, FileTitle_Tag);//�t�H���g�Z�b�g�̕\��
			}
			else if (StatusNumber == 3) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "�t�@�C���p�X: %s", FilePath_Pad_h);//�t�@�C���p�X
			}
			else if (StatusNumber == 4) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "AppDir: %s", AppDir);//�A�v���P�[�V�����f�B���N�g��
			}
			else if (StatusNumber == 5) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "LocalDir: %s", LocalDir);//���[�J���f�B���N�g��
			}
			else if (StatusNumber == 6) {
				DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1], black, "MsgDir: %s", MsgDir);//���b�Z�[�W�f�B���N�g��
			}

			////////�i�S�j�v���_�E�����j���[�̏���////////////////////////////
			if (List0.Active == 1) {//�t�@�C���֘A�̃v���_�E�����X�g�̏���
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[0].Location[0] + ToolAForm.Margin[0],
					ToolA[0].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[0].Width,
					box[1] + ToolA[0].Height
				};
				if (ToolA[0].ParentArea_p != NULL) {
					box[0] += ToolA[0].ParentArea_p->Nest[0];
					box[1] += ToolA[0].ParentArea_p->Nest[1];
					box[2] += ToolA[0].ParentArea_p->Nest[0];
					box[3] += ToolA[0].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List0.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[0].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[0].Padding[1], black, ToolA[0].Title); //�����̕\��
				//���X�g����
				ShowList(&List0);
				////�t�@�C�����J���i���t�@�C���j
				int r = 0;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {//�N���b�N�����Ƃ��̏���
						//�_�C�A���O�Ńp�b�h�Z�b�g�̃t�@�C���p�X���擾
						if (PadDir[0] == '\0') {
							strcpy(PadDir, AppDir);
							strcat(PadDir, "\\OriginalFile\\PadData");
						}
						//PadDire�̓p�b�h�t�@�C��������f�B���N�g���BPadDire���J���̂Ƃ��́u�`\\�p�b�h�Z�b�g�v
						char filepath[MAX_PATH]; char filetitle[MAX_PATH];
						if (GetOpenFileNameACP(PadDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I�����̃J�����g�f�B���N�g���̓p�b�h�Z�b�g�i�G���A�̃t�@�C���j������f�B���N�g���B�u�`\\�p�b�h�Z�b�g�v�Ƃ͌���Ȃ��̂Œ��ӁB
						//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
							//�J�����t�@�C���̃��[�h�𒲂ׂ�
							ClearDrawScreen();
							switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
							case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
								strcpy(FilePath_Pad_h, filepath);//�t�@�C���p�X�̊m��
								//if (*EditorMode_p != 2) PadDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
								//for (int i = 0; i < 3; i++) PadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
								return 0;//���ҏW���[�h���甲����
							case -1:
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
								WaitKey(); break;
							default://�����icase -2�j�j
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
								WaitKey();
							}

						}
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				///////�z�[���ɖ߂�//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						PadDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
						*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
						return 0;
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////////�A�v���P�[�V�����̏I��
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						DxLib_End(); return 0;
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List0.Active = -1; Toolbar[1].Active = 1; Toolbar[2].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					DisplayArea[0].Active = 1; DisplayArea[1].Active = 1;
				}

			}
			//////�X�^�C���̃v���_�E�����X�g
			if (List1.Active == 1) {//�v���_�E�����X�g
				ShowList(&List1);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[1].Location[0] + ToolAForm.Margin[0],
					ToolA[1].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[1].Width,
					box[1] + ToolA[1].Height
				};
				if (ToolA[1].ParentArea_p != NULL) {
					box[0] += ToolA[1].ParentArea_p->Nest[0];
					box[1] += ToolA[1].ParentArea_p->Nest[1];
					box[2] += ToolA[1].ParentArea_p->Nest[0];
					box[3] += ToolA[1].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List1.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[1].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[1].Padding[1], black, ToolA[1].Title); //�����̕\��

				 ////�X�^�C���̕ۑ�
				int  r = 0;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//char dir[MAX_PATH]; strcpy(dir, LocalDir); strcat(dir, "\\FontTagSettings.txt");
						//SaveFontTagSetPath(dir);//�X�^�C���Z�b�g�̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontSet, SourcePath, FileTitle_Font, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�摜�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�摜�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontImgSet, SourcePath, FileTitle_FontImg, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontImgSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�^�O�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ń^�O�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_TagSet, SourcePath, FileTitle_Tag, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_TagSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�W���C�p�b�h�̊��蓖��
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�ŃW���C�p�b�h�̊��蓖�Ẵt�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_Joypad, SourcePath, FileTitle_Joypad, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_TagSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List1.Nest[1] += List1.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List1.Active = -1; Toolbar[1].Active = 1; Toolbar[2].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					DisplayArea[0].Active = 1; DisplayArea[1].Active = 1;
				}
			}
			//////�ݒ�̃v���_�E�����X�g
			if (List2.Active == 1) {//�v���_�E�����X�g190802
				ShowList(&List2);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[2].Location[0] + ToolAForm.Margin[0],
					ToolA[2].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[2].Width,
					box[1] + ToolA[2].Height
				};
				if (ToolA[2].ParentArea_p != NULL) {
					box[0] += ToolA[2].ParentArea_p->Nest[0];
					box[1] += ToolA[2].ParentArea_p->Nest[1];
					box[2] += ToolA[2].ParentArea_p->Nest[0];
					box[3] += ToolA[2].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List2.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[2].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[2].Padding[1], black, ToolA[2].Title); //�����̕\��

				////�w�i�̕ύX
				int  r = 0;
				if (List2.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List2.Nest[0] + List2.RowWidth && List2.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List2.Nest[1] + List2.RowHeight
					&& List2Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List2.Nest[0], List2.Nest[1], List2.Nest[0] + List2.RowWidth, List2.Nest[1] + List2.RowHeight, List2.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SettingEditorBackFlag = 1;
					}
				}
				if (List2Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List2.Nest[0] + List2.BorderThickness + List2.RowPadding[0], List2.Nest[1] + List2.BorderThickness + List2.RowPadding[1], black, List2Row[r].Title); //�����̕\��
				if (List2Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List2.Active = -1; Toolbar[1].Active = 1; Toolbar[2].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					DisplayArea[0].Active = 1; DisplayArea[1].Active = 1;
				}
			}

			//�w�i�̕ύX
			if (SettingEditorBackFlag > 0) {
				//���X�g����I�������u��
				if (SettingEditorBackFlag == 1) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					//DisplayArea[0].Active = 0;DisplayArea[1].Active = 0;
				}
				//�w�i�̕ύX�t�H�[���̕\���@���X�g����I�����Ĉȍ~
				int Value = SettingEditorBack(DisplayArea, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Kosuu, &SettingEditorBackFlag);
				//�w�i�̕ύX�t�H�[�����ŕۑ���������
				if (Value == 1) {
					//�v���r���[�p�̃f�B�X�v���C�G���A�ɏ����ʂ�
					DisplayArea_Preview[0].BackColor = DisplayArea[0].BackColor;//���b�Z�[�W���̓G���A
					DisplayArea_Preview[0].BackImg = DisplayArea[0].BackImg;//���b�Z�[�W���̓G���A

					DisplayArea_Preview[1].BackColor = DisplayArea[1].BackColor;//�p�b�h�\���G���A
					DisplayArea_Preview[1].BackImg = DisplayArea[1].BackImg;//�p�b�h�\���G���A

					//�ݒ�p�t�@�C���̕ۑ�
					SetCurrentDirectory(AppDir);
					SaveEditorSettings(DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview_Kosuu);//�X�^�C���Z�b�g�̕ۑ�

					//�e�G���A�̃A�N�e�B�u��
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					//DisplayArea[0].Active = 1;DisplayArea[1].Active = 1;
				}
				//�w�i�̕ύX�t�H�[�����ŃL�����Z����������
				else if (Value == -1) {
					//�e�G���A�̃A�N�e�B�u��
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					//DisplayArea[0].Active = 1;DisplayArea[1].Active = 1;
				}
			}

			char DirectoryNow1[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p

			//���J�[�\���I�[�o�[
			static const int BackColor = GetColor(230, 255, 230);//R:255 G:255 B:204
			int LocationX = ActiveMath::MouseX; int LocationY = ActiveMath::MouseY + 20;
			Math_CursorOver(LocationX, LocationY, 2, black, BackColor, NULL);//Math_ButtonTitleShow(const int LocationX, const int LocationY, const int Padding, const int StringColor, const int BackColor, const int Type)


			//���}���`�K�C�h
			MultiGuide();
			//���T���v���̐��������i�R���g���[���{R�j
			if (ActiveMath::Key[KEY_INPUT_R] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {
				for (int i = 0; i < ToolBKosuu; i++) ToolB[i].Active = 1;
				for (int i = 0; i < List0RowKosuu; i++) List0Row[i].Active = 1;
				for (int i = 0; i < List1RowKosuu; i++) List1Row[i].Active = 1;
				for (int i = 0; i < List2RowKosuu; i++) List2Row[i].Active = 1;
			}
		}
	}
	return 0;
}
//�p�b�h�r���[�A�̏I���


//���b�Z�[�W�ҏW���[�h�C���ҏW���[�h�̃X�e�[�^�X�o�[�̕\�����e��ύX
int StatusShow(int LocationX, int LocationY, struct MsgBoxCtrl *MsgBoxCtrl_p, int MasterHeight, char *FilePath_h) {
	static int StatusNumber = 0;//�i�R���g���[���{S�j
	if (ActiveMath::Key[KEY_INPUT_S] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {//�uctrl + s�v�ŃX�e�[�^�X�o�[�̕\���؂�ւ�
		StatusNumber += 1;//
		if (StatusNumber == 6) StatusNumber = 0;
	}
	if (StatusNumber == 0) {
		int Height;
		if (MsgBoxCtrl_p != NULL) Height = MsgBoxCtrl_p->Height;
		else Height = 0;
		DrawFormatString(LocationX, LocationY, black, "�A�N�e�B�u�ȃ��b�Z�[�W�̍����@���݂̍���: %d  /  �w�肳�ꂽ����: %d", Height, MasterHeight);//���t�g�o�[�Ɋ֘A
	}
	else if (StatusNumber == 1) {
		DrawFormatString(LocationX, LocationY, black, "�t�H���g�Z�b�g: %s  /  �t�H���g�摜�Z�b�g: %s  /  �^�O�Z�b�g: %s", ActiveMath::FileTitle_Font, ActiveMath::FileTitle_FontImg, ActiveMath::FileTitle_Tag);//�t�H���g�Z�b�g�̕\��
	}
	else if (StatusNumber == 2) {
		DrawFormatString(LocationX, LocationY, black, "�t�@�C���p�X: %s", FilePath_h);//�t�@�C���p�X
	}
	else if (StatusNumber == 3) {
		DrawFormatString(LocationX, LocationY, black, "AppDir: %s", AppDir);//�A�v���P�[�V�����f�B���N�g��
	}
	else if (StatusNumber == 4) {
		DrawFormatString(LocationX, LocationY, black, "LocalDir: %s", LocalDir);//���[�J���f�B���N�g��
	}
	else if (StatusNumber == 5) {
		DrawFormatString(LocationX, LocationY, black, "MsgDir: %s", MsgDir);//���b�Z�[�W�f�B���N�g��
	}
	return 0;



}


/////�����ҏW���[�h��////////////�����ҏW���[�h��////////////�����ҏW���[�h��////////////�����ҏW���[�h��//////
int EditMondai(int* EditorMode_p, char* FilePath_Mondai_h) {
	int MonsterFlag = 1;//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
						 ////�V�X�e����ԂɊւ���ϐ��̐錾�Ə�����////
	int activesyoumonH = -1;//�A�N�e�B�u�ȏ���i-1�F��A�N�e�B�u�j
	int activesyoumonseikaiH = -1;//�A�N�e�B�u�ȏ��␳��ځi-1�F��A�N�e�B�u�j


	int Rot = 0;// �}�E�X�z�C�[���̉�]�ʂ̍��v�l
	int popupRot = 0;// �}�E�X�z�C�[���̉�]�ʂ̍��v�l�@�|�b�v�A�b�v�p�i�t��]�j

	int copyno = -1;//�R�s�[���̏���ԍ��̋L�^�i-1�F�Ȃ��@����ȊO�F�R�s�[���̏���v�f�ԍ��j�@�R�s�[����������悤�ɂ���}�[�N�̕\���Ɓu����ւ��v�����Ŏg�p�B


	//////���͂̏����Ɋւ���ϐ��̐錾�Ə�����////////////////////////////
	int InputHandleMath = MakeKeyInput(100, TRUE, FALSE, FALSE);//�V�����L�[���̓f�[�^�̍쐬  ESC�L�[�ɂ��L�����Z���@�\�̗L��TRUE�@���p�����݂̂̓���FALSE�@���l�����݂̂̓���FALSE

	////////////////////////

	//////////�c�[���{�^��////////////
	int ButtonStrLen;//�^�C�g���̕�����

	//���c�[���o�[
	static struct AREACONTROL Toolbar[2] = { 0 };
	for (int AreaN = 0; AreaN < 2; AreaN++) {
		for (int i = 0; i < 4; i++) Toolbar[AreaN].Padding[i] = 1;
		Toolbar[AreaN].BackColor = GetColor(51, 102, 153);//204, 204, 204 R:51 G:102 B:153//102, 153, 204
		Toolbar[AreaN].Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
		/////////
	}
	Toolbar[1].Location[0] = -111111;
	Toolbar[0].Width = 208;
	Toolbar[0].Height = 28;//
	////
	Toolbar[1].Width = 416;// jjj 276;//
	Toolbar[1].Height = 28;

	//���{�^��A�t�H�[��
	static struct BUTTONFORM ToolAForm = { 0 };
	for (int i = 0; i < 4; i++) ToolAForm.Margin[i] = 1;
	ToolAForm.CursorColor = GetColor(255, 255, 204);


	//���c�[���{�^��A
	const int ToolAKosuu = 3;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
	static struct BUTTONCONTROL ToolA[ToolAKosuu] = { 0 };
	strcpy(ToolA[0].Title, "�t�@�C��");
	strcpy(ToolA[1].Title, "�J�X�^�}�C�Y");
	strcpy(ToolA[2].Title, "�ݒ�");

	for (int BtnN = 0; BtnN < ToolAKosuu; BtnN++) {
		ToolA[BtnN].ParentArea_p = &Toolbar[0];
		if (BtnN > 0) ToolA[BtnN].Location[0] = -111111;
		for (int i = 0; i < 4; i++) ToolA[BtnN].Padding[i] = 5;
		ToolA[BtnN].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolA[BtnN].ButtonForm_p = &ToolAForm;
	}

	//���{�^��B�t�H�[��
	static struct BUTTONFORM ToolBForm = { 0 };
	for (int i = 0; i < 4; i++) ToolBForm.Margin[i] = 1;
	ToolBForm.CursorColor = GetColor(122, 163, 204);//255, 255, 204//R:102 G:153 B:204//R:153 G:204 B:255//R:122 G:163 B:204

	//���c�[���{�^��B
	SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	const int ToolBKosuu = 5;//�{�^���z��̗v�f��
	static struct BUTTONCONTROL ToolB[ToolBKosuu] = { 0 };
	strcpy(ToolB[0].String, "�z�[����ʂɖ߂�");
	if (ToolB[0].WaitingImg == -1) {
		ToolB[0].WaitingImg = LoadGraph(".\\System\\Fixed\\home24.png");
		ToolB[0].CursorImg = LoadGraph(".\\System\\Fixed\\home24b.png");
		ToolB[0].PushedImg = ToolB[0].CursorImg;
	}
	strcpy(ToolB[1].String, "�V�K�쐬");
	if (ToolB[1].WaitingImg == -1) {
		ToolB[1].WaitingImg = LoadGraph(".\\System\\Fixed\\new24.png");
		ToolB[1].CursorImg = LoadGraph(".\\System\\Fixed\\new24b.png");
		ToolB[1].PushedImg = ToolB[1].CursorImg;
	}
	strcpy(ToolB[2].String, "�t�@�C�����J��");
	if (ToolB[2].WaitingImg == -1) {
		ToolB[2].WaitingImg = LoadGraph(".\\System\\Fixed\\open24.png");
		ToolB[2].CursorImg = LoadGraph(".\\System\\Fixed\\open24b.png");
		ToolB[2].PushedImg = ToolB[2].CursorImg;
	}
	strcpy(ToolB[3].String, "�㏑���ۑ�");
	if (ToolB[3].WaitingImg == -1) {
		ToolB[3].WaitingImg = LoadGraph(".\\System\\Fixed\\save24.png");
		ToolB[3].CursorImg = LoadGraph(".\\System\\Fixed\\save24b.png");
		ToolB[3].PushedImg = ToolB[3].CursorImg;
	}
	strcpy(ToolB[4].String, "�����X�^�[�̕ҏW");
	if (ToolB[4].WaitingImg == -1) {
		ToolB[4].WaitingImg = LoadGraph(".\\System\\Fixed\\monster24.png");
		ToolB[4].CursorImg = LoadGraph(".\\System\\Fixed\\monster24b.png");
		ToolB[4].PushedImg = ToolB[4].CursorImg;
	}

	for (int BtnN = 0; BtnN < ToolBKosuu; BtnN++) {
		ToolB[BtnN].ParentArea_p = &Toolbar[1];
		if (BtnN > 0) ToolB[BtnN].Location[0] = -111111;
		ToolB[BtnN].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolB[BtnN].ButtonForm_p = &ToolBForm;
	}

	char DirectoryNow1[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p

	//���X�e�[�^�X�o�[
	static struct AREACONTROL Statusbar = { 0 };
	Statusbar.Width = WindowWidth;
	Statusbar.Height = 24;//������v���̂���Location[1]����ɏ�����
	Statusbar.Location[1] = WindowHeight - Statusbar.Height;
	for (int i = 0; i < 4; i++) Statusbar.Padding[i] = 5;
	Statusbar.BackColor = GetColor(240, 240, 240);
	Statusbar.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���


	//�G�f�B�^�[�̐ݒ�i�v���r���[�p�f�B�X�v���C�G���A�j�̎擾
	int SettingEditorBackFlag = 0;
	const int DisplayArea_Preview_Kosuu = 4;
	char BackImgPath[DisplayArea_Preview_Kosuu][MAX_PATH] = { 0 };//�w�i�摜�t�@�C�����擾�p
	int BorderColorRGB[DisplayArea_Preview_Kosuu][3] = { 0 };//�w�i�F��RGB�擾�p
	int BackColorRGB[DisplayArea_Preview_Kosuu][3] = { 0 };//�w�i�F��RGB�擾�p
	static struct AREACONTROL DisplayArea_Preview[DisplayArea_Preview_Kosuu] = { 0 };
	SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	char DisplayArea_Preview_FilePath[MAX_PATH] = ".\\System\\BackImg\\BackImgPath_Mondai.txt";
	LoadEditorSettings(DisplayArea_Preview_FilePath, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview, DisplayArea_Preview_Kosuu);
	
	//���f�B�X�v���C�G���A
	int DisplayArea_Kosuu = 1;
	static struct AREACONTROL DisplayArea = { 0 };
	DisplayArea.Location[1] = Toolbar[0].Height + EditorPadArea[2].Height;//28+56
	DisplayArea.Padding[0] = 14;
	DisplayArea.Padding[1] = 14;
	DisplayArea.Padding[2] = 0;//�����X�^�[�e�[�u���̕���953����������̉E�̗]����1000-(5+18+953+5)��19�ƂȂ�
	DisplayArea.Padding[3] = 0;
	DisplayArea.Width = WindowWidth;
	DisplayArea.Height = WindowHeight - Toolbar[0].Height - EditorPadArea[2].Height - Statusbar.Height;//798-28-56-24=690
	DisplayArea.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	//DisplayArea.BackColor = DisplayArea_Preview[0].BackColor;//NULL;//
	//DisplayArea.ImgHandle = DisplayArea_Preview[0].ImgHandle;



	//���f�B�X�v���C�G���A�Q
	static struct AREACONTROL DisplayArea2 = { 0 };
	DisplayArea2.ParentArea_p = &DisplayArea;
	DisplayArea2.Location[1] = 300;//�f�B�X�v���C�G���A�Q�ɑΉ�����G�f�B�^�[�ݒ�Ȃ��ɂ���Ȃ猩���Ȃ�����w�肵�Ȃ��Ă��悢�B�ݒ肠��ɂ���Ȃ猩���Ă��܂�����w��͕K�v�@�@�f�B�X�v���C�G���A�Q���f�B�X�v���C�G���A�̎q�G���A�łȂ��Ɨ����Ă���ΐ�΂ɕK�v�B
	DisplayArea2.Padding[1] = 3;//��؂���̕�
	DisplayArea2.Width = 953;//�i���b�Z�[�W�{�b�N�X�̊e�c�[���o�[�̕�953�j
	DisplayArea2.Height = DisplayArea.Height;//��␳���̏����o����ɏ펞�X�V����̂ŁC�����͉��ł��悢

	//DisplayArea2.BackColor = DisplayArea_Preview[1].BackColor;//NULL;//
	//DisplayArea2.ImgHandle = DisplayArea_Preview[1].ImgHandle;
	DisplayArea2.BorderColor = GetColor(153, 153, 153);

	DisplayArea2.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	DisplayArea2.Line[0] = 0;
	DisplayArea2.Line[1] = 0;
	DisplayArea2.Line[2] = 953;//�i���b�Z�[�W�{�b�N�X�̕�953�j
	DisplayArea2.Line[3] = 3;


	//������G���A
	static struct AREACONTROL SyoumonArea = { 0 };
	SyoumonArea.ParentArea_p = &DisplayArea2;
	SyoumonArea.Width = DisplayArea2.Width;
	SyoumonArea.Height = 100000;//�����^�̍ő�l���擾����Ɨǂ��Ǝv���H�H�H
	SyoumonArea.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���

	//////////////////////////////////////////////////
	/////////////////////////////////////////////////////

//////////�v���_�E�����X�g////////////
	int ListStrLen;//�^�C�g���̕�����
	int ListStrWidth;//�^�C�g���̕�
	const int list_BackColor = GetColor(204, 204, 153);//list_color
	const int list_BorderColor = GetColor(153, 153, 102);//list_color_k
	const int List_CursorColor = GetColor(255, 255, 204);//PulldownList_CursorColor
	//���t�@�C���̃v���_�E�����X�g
	const int List0RowKosuu = 7;
	ListStrWidth = GetDrawStringWidth("�A�v���P�[�V�����̏I��", strlen("�A�v���P�[�V�����̏I��"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List0 = { 0 };
	List0.ParentButton_p = &ToolA[0];//�t�@�C���{�^��
	List0.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List0.Padding[i] = 2;
	List0.BackColor = list_BackColor;
	List0.BorderColor = list_BorderColor;
	List0.CursorColor = List_CursorColor;

	List0.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List0.RowKosuu = List0RowKosuu;
	for (int i = 0; i < 4; i++) List0.RowPadding[i] = 5;
	List0.RowWidth = ListStrWidth + List0.RowPadding[0] + List0.RowPadding[2];
	List0.RowHeight = SystemFontSize + List0.RowPadding[1] + List0.RowPadding[3];
	/////////
	List0.Width = List0.RowWidth + List0.Padding[0] + List0.Padding[2] + List0.BorderThickness * 2;
	List0.Height = List0.RowHeight * List0.RowKosuu + List0.Padding[1] + List0.Padding[3] + List0.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List0Row[List0RowKosuu] = { 0 };
	for (int i = 0; i < List0RowKosuu; i++) List0Row[i].List_p = &List0;
	strcpy(List0Row[0].Title, "�V�K�쐬");
	strcpy(List0Row[1].Title, "�t�@�C�����J��");
	strcpy(List0Row[2].Title, "�㏑���ۑ�");
	strcpy(List0Row[3].Title, "���O��t���ĕۑ�");
	strcpy(List0Row[4].Title, "�����X�^�[�̕ҏW");
	strcpy(List0Row[5].Title, "�z�[���ɖ߂�");
	strcpy(List0Row[6].Title, "�A�v���P�[�V�����̏I��");

	//���J�X�^�}�C�Y�̃v���_�E�����X�g
	const int List1RowKosuu = 5;
	ListStrWidth = GetDrawStringWidth("�W���C�p�b�h�̊��蓖�Ă̕ύX", strlen("�W���C�p�b�h�̊��蓖�Ă̕ύX"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List1 = { 0 };
	List1.ParentButton_p = &ToolA[1];//�J�X�^�}�C�Y�{�^��
	List1.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List1.Padding[i] = 2;
	List1.BackColor = list_BackColor;
	List1.BorderColor = list_BorderColor;
	List1.CursorColor = List_CursorColor;
	List1.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List1.RowKosuu = List1RowKosuu;
	for (int i = 0; i < 4; i++) List1.RowPadding[i] = 5;
	List1.RowWidth = ListStrWidth + List1.RowPadding[0] + List1.RowPadding[2];
	List1.RowHeight = SystemFontSize + List1.RowPadding[1] + List1.RowPadding[3];
	/////////
	List1.Width = List1.RowWidth + List1.Padding[0] + List1.Padding[2] + List1.BorderThickness * 2;
	List1.Height = List1.RowHeight * List1.RowKosuu + List1.Padding[1] + List1.Padding[3] + List1.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List1Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List1RowKosuu; i++) List1Row[i].List_p = &List1;
	strcpy(List1Row[0].Title, "�X�^�C���̕ۑ�");
	strcpy(List1Row[1].Title, "�t�H���g�Z�b�g�̕ύX");
	strcpy(List1Row[2].Title, "�t�H���g�摜�Z�b�g�̕ύX");
	strcpy(List1Row[3].Title, "�^�O�Z�b�g�̕ύX");
	strcpy(List1Row[4].Title, "�W���C�p�b�h�̊��蓖�Ă̕ύX");


	//���ݒ�̃v���_�E�����X�g
	const int List2RowKosuu = 1;
	ListStrWidth = GetDrawStringWidth("�w�i�̕ύX", strlen("�w�i�̕ύX"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List2 = { 0 };
	List2.ParentButton_p = &ToolA[2];//�ݒ�{�^��
	List2.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List2.Padding[i] = 2;
	List2.BackColor = list_BackColor;
	List2.BorderColor = list_BorderColor;
	List2.CursorColor = List_CursorColor;
	List2.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List2.RowKosuu = List2RowKosuu;
	for (int i = 0; i < 4; i++) List2.RowPadding[i] = 5;
	List2.RowWidth = ListStrWidth + List2.RowPadding[0] + List2.RowPadding[2];
	List2.RowHeight = SystemFontSize + List2.RowPadding[1] + List2.RowPadding[3];
	/////////
	List2.Width = List2.RowWidth + List2.Padding[0] + List2.Padding[2] + List2.BorderThickness * 2;
	List2.Height = List2.RowHeight * List2.RowKosuu + List2.Padding[1] + List2.Padding[3] + List2.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List2Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List2RowKosuu; i++) List2Row[i].List_p = &List2;//������
	strcpy(List2Row[0].Title, "�w�i�̕ύX");

	//////////////////////////////////////////
		//�����X�^�[�e�[�u��
	const int cursorColorbuff = GetColor(102, 102, 51);//�Y���̃����X�^�[�ɂ��v���_�E�����X�g�ɂ��g�p����
	struct MonsterTableAll monstertableall;
	monstertableallsyokika(DisplayArea.Location[0] + DisplayArea.BorderThickness + DisplayArea.Padding[0], DisplayArea.Location[1] + DisplayArea.BorderThickness + DisplayArea.Padding[1]+ SystemFontSize + 2, &monstertableall, 1);
	//DisplayArea��Nest�̓��C�����[�v�ɓ���܂Ŏg���Ȃ�����Location + Padding�Ƃ���//+16�̓e�[�u���̌��o���̍����i14+2�j
																																						//�������X�^�[�e�[�u�� �v���_�E�����X�g
	static struct MonsterTableAll MonsterTable_pd[5];
	const int TableMax = 5;
	static int tablesuu;//���[�h��ɂT��菬������Ό��炷

	const char PulldownList_Monster_text[] = { "�����X�^�[" };//�v���_�E�����X�g�̃^�C�g��
	static int PulldownList_Monster[4] = { monstertableall.tablewaku[0], monstertableall.tablewaku[3], monstertableall.tablewaku[2] + 10, monstertableall.tablewaku[3] + 90 * TableMax + 10 + SystemFontSize + 5 };//�v���_�E�����X�g
																																																				   ////////�����X�^�[
																						  //���b�Z�[�W�ƃ��b�Z�[�W�v���p�e�B
	struct Kadai mondai = { 0 }; //���f�[�^������
	int MsgSizeE = 0;//MsgSizeE�͏I�[�������܂߂��T�C�Y
	//���[�h�̃e�L�X�g
	char AppMode_text[MAX_PATH];
	strcpy(AppMode_text, ApplicationTitle);//�A�v���P�[�V����������
	strcat(AppMode_text, " - ���ҏW���[�h - ");//���[�h����A��
	//�^�C�g���o�[
	char Titlebar_text[MAX_PATH];
	strcpy(Titlebar_text, AppMode_text);
	//
	static char FileTitle_Mondai[MAX_PATH] = { 0 };//���t�@�C�������擾����ϐ�
	if (FilePath_Mondai_h[0] != '\0') GetTitleFromPath(FileTitle_Mondai, FilePath_Mondai_h);//�t�@�C���p�X����t�@�C�������擾

	//�t�@�C���p�X�֘A//
	static char FilePath_Settings[MAX_PATH];//�X�^�C�����̐ݒ�t�@�C���̃t���p�X�i���t�@�C�����J���s�x�C���t�@�C���Ɠ����f�B���N�g�����́@"�ݒ�.txt"�@�t�@�C���̃t���p�X�ƂȂ�j
	static char FilePath_MsgBoxForm[MAX_PATH];//���b�Z�[�W�{�b�N�X�R���g���[���t�@�C���̃t���p�X�i���t�@�C�����J���s�x�C���t�@�C���Ɠ����f�B���N�g�����́@"MsgBoxForm.txt"�@�t�@�C���̃t���p�X�ƂȂ�j
	static char FilePath_MsgBoxCtrl[MAX_PATH];//���b�Z�[�W�v���p�e�B�t�@�C���̃t���p�X�i���t�@�C�����J���s�x�C���t�@�C���Ɠ����f�B���N�g�����́@"Propaty.txt"�@�t�@�C���̃t���p�X�ƂȂ�j


	//���b�Z�[�W�t�H�[��
	const int MsgBoxForm_Kosuu = 4;
	//static int MsgBoxFormEnd;
	static struct MsgBoxForm MsgBoxForm[MsgBoxForm_Kosuu];//�}�X�^�[�i���b�Z�[�W�̕\���ɂ͂�����g�p����B���b�Z�[�W�̕ҏW�ł͒l���ꎞ�I�ɏ���������j
	static struct MsgBoxForm MsgBoxForm_Copy[MsgBoxForm_Kosuu];//�R�s�[�i���b�Z�[�W�̕ҏW�ňꎞ�I�ɏ����������l���C���ɖ߂����߂Ɏg�p�B�܂����b�Z�[�W�t�H�[���̕ۑ��ɂ͂�����g�p�B�j
	static struct MsgBoxForm_RGB_SoundPath MsgBoxForm_RGB_SoundPath[MsgBoxForm_Kosuu];//�F�C�����̓n���h���ł͂Ȃ��C�F��RGB�l�C������LocalDir����̑��΃p�X���L�^�i�l�̕ύX��ۑ��Ŏg�p�j

	//���b�Z�[�W�{�b�N�X�i�}�X�^�[�j
	const int MsgBoxCtrl_Kosuu = 4;
	//static int MsgBoxCtrlmEnd;
	static struct MsgBoxCtrl MsgBoxCtrl_Master[MsgBoxCtrl_Kosuu];// = { 0 };//���t�g�o�[�iHeight�j�C���b�Z�[�W�v���r���[�i�|�C���^�[�A�h���X�j�C�p�b�h�v���r���[�i�|�C���^�[�A�h���X�j�Ŏg�p
	static int MsgBoxFormNumber[MsgBoxCtrl_Kosuu];

	//���b�Z�[�W�{�b�N�X
	static struct MsgBoxCtrl HMsgBoxHCtrl_D;
	static struct MsgBoxCtrl HMsgBoxHCtrl_DS;
	static struct MsgBoxCtrl HMsgBoxHCtrl_S[SYOUMON_MAX];
	static struct MsgBoxCtrl HMsgBoxHCtrl_SS[SYOUMON_MAX];


	int syoumonsuu;//���␔�i���ۂ̌��j
	char* Message_p = NULL;
	struct MsgBoxCtrl* MsgBoxCtrl_p = NULL;
	int MasterHeight = 0;//�A�N�e�B�u��MsgBoxCtrl_Master[0]�`[3]��.Height���X�e�[�^�X�o�[�ɑ��邽�߂̕ϐ�;
	//�����X�^�[�֘A
	struct Monster Monster[MONSTER_MAX];
	static int Monster_Kosuu = 0;//�����X�^�[���i���ۂ̌��j
	static char ColumnTitle[MONSTER_COLUMNMAX][MONSTER_COLUMNTITLEFIELDMAX + 1] = { 0 };//�K��MONSTER_COLUMNTITLEFIELDMAX + 1�ȉ��ɂ��邱�Ɓi2�����z��̈�����MONSTER_COLUMNTITLEFIELDMAX + 1���w�肳��Ă��邽��
	static int Column_Kosuu = 0;
	char MonsterImg_Path[MONSTER_MAX][MAX_PATH] = { 0 }; //�S�����X�^�[�̉摜�t�@�C���̃p�X������z��
	static int MonsterImgWidth[MONSTER_MAX];
	static int MonsterImgHeight[MONSTER_MAX];//�����X�^�[�̉摜�̏c���T�C�Y���擾���邽�߂̕ϐ�
	int MaxMonsterID = 0;

	int MonsterNum = 0;//0�F�����X�^�[�e�[�u�����ł̗v�f�ԍ��@�����X�^�[�h�c��0�B�����X�^�[���o�^�̏��
		//����`�̓����X�^�[�e�[�u���ɑ�������̂ł͂Ȃ�
	char Undefined_MonsterName[MONSTERNAME_FIELDSISE + 1] = { "����`" };
	int Undefined_MonsterImg = LoadGraph(".\\System\\Fixed\\undefined_monster.png");
	int Undefined_MonsterImgWidth;
	int Undefined_MonsterImgHeight;
	GetGraphSize(Undefined_MonsterImg, &Undefined_MonsterImgWidth, &Undefined_MonsterImgHeight); //�����X�^�[�̉摜�̏c���T�C�Y���擾����Undefined_MonsterImgWide�Cmonsterhight�ɏ����o��

	if (FilePath_Mondai_h[0] != '\0') {
		//if (FilePath_Mondai_h[strlen(FilePath_Mondai_h) - 4] == '.') {
		//char LocalDir_Befor[MAX_PATH];
		//strcpy(LocalDir_Befor, LocalDir);

		//���̃��[�h�Ə��␔�̎擾
		int LoadMondaiError;
		//LocalDir���擾���邽��MondaiDir�͕K����΃p�X�Ƃ��邱��
		switch (LoadMondaiError = LoadMondai(FilePath_Mondai_h, &mondai, &syoumonsuu, 1)) {//�P�FLocalDir�CMsgDir�̎擾
		//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[ID���T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -3: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "��₪�T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -4: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "��␳�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -5: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���₪�T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -6: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���␳�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60);
		}
		if (LoadMondaiError < -1) {//-1�̓G���[�Ƃ��Ȃ��B�i�V�K�쐬�̂Ƃ��C���̃t�@�C�������݂��Ȃ����߁j
			DxLib::WaitKey();
			FilePath_Mondai_h[0] = '\0';//�t�@�C���p�X������
			ClearDrawScreen();
			return -1;
		}
		//	}

		//////���Z�b�g�̃��[�h
		int Error;
		switch (Error = LoadMondaiSet(LocalDir, MsgBoxForm, MsgBoxForm_Kosuu, MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu,
				Monster, MONSTER_MAX, &Monster_Kosuu, &MaxMonsterID, ColumnTitle, &Column_Kosuu, 1, 1//�t�H���g�^�O�ݒ�����[�h����C�W���C�p�b�h�ݒ�����[�h����
		)) {
		//���[�h���甲����
		//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		case -3: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//�@�i�Ȃ��j
		//case -11: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -12: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		case -13: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//�@�i�Ȃ��j
		//case -21: FontTagSettingsCreateFlag = 0;//�X�^�C���ۑ����ɐV�K�쐬���Ȃ��悤��//ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;
		//case -22: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		//case -31: JoypadSettingsCreateFlag = 0;//�X�^�C���ۑ����ɐV�K�쐬���Ȃ��悤��//ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�W���C�p�b�h�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;
		//case -32: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�W���C�p�b�h�ݒ�̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j

		//case -41: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃t�@�C�������݂��܂���B", black, gray60); break;
		//���̂܂ܑ��s
		case -42: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[��ID�p�J�����̃^�C�g�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -45: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃J�����̃^�C�g�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -47: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[��ID�p�J�������T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -48: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃����X�^�[�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -49: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃����X�^�[�摜�p�X���T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
		case -50: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃J�������T�C�Y�I�[�o�[���Ă��܂��B", black, gray60);
		}
		if (Error <= -42) DxLib::WaitKey();//�T�C�Y�I�[�o�[�ł����̂܂ܑ�����i-42�`-50�j
		else if (Error < -1 && Error != -11 && Error != -21 && Error != -31 && Error != -41) {//���[�h���甲����i-1�`-41�j
			DxLib::WaitKey();
			FilePath_Mondai_h[0] = '\0';//�t�@�C���p�X������
			ClearDrawScreen();
			return -1;
		}
		//���I�����̓����X�^�[�f�B���N�g��
		for (int i = 0; i < MsgBoxCtrl_Kosuu; i++) {
			MsgBoxFormNumber[i] = MsgBoxCtrl_Master[i].MsgBoxForm_p - MsgBoxForm;
		}
		if (Monster_Kosuu > TableMax) tablesuu = TableMax;//
		else tablesuu = Monster_Kosuu;
		SetCurrentDirectory(LocalDir);//
		//MsgBoxForm2r�̃��[�h�i�F�̒l�C���̃p�X�j
		LoadMsgBoxForm_RGB_SoundPath(".\\MsgBoxForm.txt", MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);//�t�H�[���̃Z�[�u�����邩��Form2�����[�h���Ă����K�v������B
		//�����X�^�[�摜�p�X�̃��[�h
		LoadMonsterImgPath(".\\Monster\\monstertable.csv", MonsterImg_Path, MONSTER_MAX);
		//char DirectoryNow1[MAX_PATH];
		//GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p


		///////////////////////////
		SetCurrentDirectory(AppDir);//
		//�Y���Ȃ��̓����X�^�[�e�[�u����[monstersuu]�C���ݒ�̓����X�^�[�e�[�u����[monstersuu + 1]
		strcpy(Monster[Monster_Kosuu].Name, "�Y���Ȃ�");//0720
		Monster[Monster_Kosuu].Img = LoadGraph(".\\System\\Fixed\\notappricable.png");
		strcpy(Monster[Monster_Kosuu + 1].Name, "���ݒ�");
		Monster[Monster_Kosuu + 1].Img = LoadGraph(".\\System\\Fixed\\notset.png");

		//�������X�^�[�ԍ��̊m��
		for (int i = 0; i < Monster_Kosuu; i++) {//�����X�^�[�i���o�[�i�����X�^�[�̗v�f�ԍ��j�̊m��
			if (mondai.monsterID == 0) {//ID���J���̂Ƃ��C�u���ݒ�v�ƂȂ�B
				MonsterNum = Monster_Kosuu + 1; break;
			}
			else if (mondai.monsterID == Monster[i].Column[0]) {
				MonsterNum = i; break;
			}
			else if (i == Monster_Kosuu - 1) {
				MonsterNum = Monster_Kosuu;  break;//�Ō�܂Ń`�F�b�N���Ă���v����ID���Ȃ��Ƃ��C�u�Y���Ȃ��v�ƂȂ�B
			}
		}

		//�������X�^�[�摜�T�C�Y�̎擾
		for (int i = 0; i < Monster_Kosuu + 2; i++) {//�����X�^�[�摜�T�C�Y�̎擾
			GetGraphSize(Monster[i].Img, &MonsterImgWidth[i], &MonsterImgHeight[i]); //�����X�^�[�̉摜�̏c���T�C�Y���擾����MonsterImgWide�CMonsterImgHeight�Ɏ擾
		}

		InputHandleMath = MakeKeyInput(100, TRUE, FALSE, FALSE);//�V�����L�[���̓f�[�^�̍쐬  ESC�L�[�ɂ��L�����Z���@�\�̗L��TRUE�@���p�����݂̂̓���FALSE�@���l�����݂̂̓���FALSE
		SetActiveKeyInput(InputHandleMath);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
		//�^�C�g���o�[�̃e�L�X�g�Ƀt�@�C�����t��
		strcat(Titlebar_text, FileTitle_Mondai);

	}
	SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������

	int SyoumonCutFlag = 0;//����؂��莞�C����ŏI�c�[���{�^�������ꍞ��ł��Ȃ��悤�ɁC���␔�𐏎����炳���C�t���O���g���Ď��̃t���[���Ō��炷�B
						//���ŏI�̏���؂��莞�Ɂu�؂���v�{�^�����C����ŏI�c�[���{�^���́u����ǉ��v�Əd�Ȃ��Ă��܂��̂��h����
	int ExitModeFlag = 0;
	

	while (!ProcessMessage()) {
		//���p�b�h�}�l�[�W���[�ƃC���f�b�N�X�{�^���̃A�N�e�B�u�̃��Z�b�g
		struct PadManager PadManager;
		//�p�b�h�̏������i�I�����Ă���C���f�b�N�X�{�^����0�ԂɃ��Z�b�g�j
		for (int i = 0; i < EditorIndexKosuu; i++) EditorIndex[i].Active = 1;
		EditorIndex[0].Active = 2;
		//�w�i�̏����ʂ��i�t�@�C�����J�����Ƃ�����сC�w�i�ύX������[�v�𔲂��čX�V�����j
		DisplayArea.BackColor = DisplayArea_Preview[0].BackColor;
		DisplayArea.BackImg = DisplayArea_Preview[0].BackImg;

		if (FilePath_Mondai_h[0] != '\0') {

			//�����b�Z�[�W�{�b�N�X�t�H�[���̒l��ҏW�p�ɏ���������
			for (int i = 0; i < MsgBoxForm_Kosuu; i++) {//[0]���@[1]��␳���@[2]����@[3]���␳���@

				//�{���̒l�����������i�t�H�[���̓��[�h�������̂��g�����߁C����������O�Ɍ��̒l���R�s�[���Ă����j
				MsgBoxForm_Copy[i] = MsgBoxForm[i];
				//�ҏW�p�ɂ���������
				int Value1 = 4;//�S�F��~ MsgBoxForm[i].Option % 10;
				int Value2 = 4;//�S�F�{�b�N�X���� MsgBoxForm[i].Option % 100 / 10;
				int Value3 = 4;//���P���ڂ�4�����炱���͉��ł��悢 MsgBoxForm[i].Option % 1000 / 100;
				int Value4 = MsgBoxForm[i].Option % 10000 / 1000;//������4���ڂ������������Ȃ��B�O�F�܂�Ԃ��Ȃ��@�P�F�܂�Ԃ����� �@�Q�F�܂�Ԃ�����i�킩���j
				int Value5 = 3;//�R�F�\�����̃��b�Z�[�W���[�iHeight�̒l���ω��j MsgBoxForm[i].Option % 100000 / 10000;
				MsgBoxForm[i].Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;

				MsgBoxForm[i].OutputSpeed = -1;//�����̏o�̓X�s�[�h�i�v���X�F�P�b�Ԃɐi�ޕ������@�}�C�i�X�F�N���b�N�ɔ�������j
							 //�܂�i�v���X�F�p�J�p�J����B�J�[�\���Ȃ��B�@0�F�p�J�p�J�Ȃ��B�J�[�\���Ȃ��B�@-1�F�p�J�p�J�Ȃ��B�N���b�N�ォ��J�[�\������B�@-2�ȉ��F�p�J�p�J�Ȃ��B������J�[�\������B�j
				MsgBoxForm[i].Margin[0] = 0; MsgBoxForm[i].Margin[1] = 0; MsgBoxForm[i].Margin[2] = 0; MsgBoxForm[i].Margin[3] = 0;
			}

			//�ҏW�p�̑�⃁�b�Z�[�W�{�b�N�X���쐬
			HMsgBoxHCtrl_D = MsgBoxCtrl_Master[0];//�}�X�^�[�͖�肪�ς�����Ƃ���v���r���[�ŁC�N���A�[���邽�߂Ɏg�p
			HMsgBoxHCtrl_D.Location[0] = 0;//���t�g�o�[�̕\�����Ƃ��Ċm�ہi�{�b�N�X�����������o���Ȃ��̂ŁC�f�B�X�v���C�G���A�P��Pading[1]��18�ɂ��Ă�����G���A�̃��t�g�o�[�͏����o���Ȃ����߁j
			HMsgBoxHCtrl_D.ParentArea_p = &DisplayArea;//�G���A�̎w��
			HMsgBoxHCtrl_D.OuterWidth = HMsgBoxHCtrl_D.Width + HMsgBoxHCtrl_D.MsgBoxForm_p->Margin[0] + HMsgBoxHCtrl_D.MsgBoxForm_p->Margin[2];
			HMsgBoxHCtrl_D.OuterHeight = HMsgBoxHCtrl_D.Height + HMsgBoxHCtrl_D.MsgBoxForm_p->Margin[1] + HMsgBoxHCtrl_D.MsgBoxForm_p->Margin[3];
			//�ҏW�p�̑�␳�����b�Z�[�W�{�b�N�X���쐬
			HMsgBoxHCtrl_DS = MsgBoxCtrl_Master[1];//�}�X�^�[�͖�肪�ς�����Ƃ���v���r���[�ŁC�N���A�[���邽�߂Ɏg�p
			HMsgBoxHCtrl_DS.Location[0] = 0;//���t�g�o�[�̕\�����Ƃ��Ċm�ہi�{�b�N�X�����������o���Ȃ��̂ŁC�f�B�X�v���C�G���A�P��Pading[1]��18�ɂ��Ă�����G���A�̃��t�g�o�[�͏����o���Ȃ����߁j
			HMsgBoxHCtrl_DS.ParentArea_p = &DisplayArea;//�G���A�̎w��
			HMsgBoxHCtrl_DS.OuterWidth = HMsgBoxHCtrl_DS.Width + HMsgBoxHCtrl_DS.MsgBoxForm_p->Margin[0] + HMsgBoxHCtrl_DS.MsgBoxForm_p->Margin[2];
			HMsgBoxHCtrl_DS.OuterHeight = HMsgBoxHCtrl_DS.Height + HMsgBoxHCtrl_DS.MsgBoxForm_p->Margin[1] + HMsgBoxHCtrl_DS.MsgBoxForm_p->Margin[3];

			for (int i = 0; i < SYOUMON_MAX; i++) {
				//�ҏW�p�̏��⃁�b�Z�[�W�{�b�N�X���쐬
				HMsgBoxHCtrl_S[i] = MsgBoxCtrl_Master[2];//�}�X�^�[�͖�肪�ς�����Ƃ���v���r���[�ŁC�N���A�[���邽�߂Ɏg�p
				HMsgBoxHCtrl_S[i].Location[0] = 0;//���t�g�o�[�̕\�����Ƃ��Ċm�ہi�{�b�N�X�����������o���Ȃ��̂ŁC�f�B�X�v���C�G���A�P��Pading[1]��18�ɂ��Ă�����G���A�̃��t�g�o�[�͏����o���Ȃ����߁j
				HMsgBoxHCtrl_S[i].ParentArea_p = &SyoumonArea;//�G���A�̎w��
				HMsgBoxHCtrl_S[i].OuterWidth = HMsgBoxHCtrl_S[i].Width + HMsgBoxHCtrl_S[i].MsgBoxForm_p->Margin[0] + HMsgBoxHCtrl_S[i].MsgBoxForm_p->Margin[2];
				HMsgBoxHCtrl_S[i].OuterHeight = HMsgBoxHCtrl_S[i].Height + HMsgBoxHCtrl_S[i].MsgBoxForm_p->Margin[1] + HMsgBoxHCtrl_S[i].MsgBoxForm_p->Margin[3];
				//�ҏW�p�̏��␳�����b�Z�[�W�{�b�N�X���쐬
				HMsgBoxHCtrl_SS[i] = MsgBoxCtrl_Master[3];//�}�X�^�[�͖�肪�ς�����Ƃ���v���r���[�ŁC�N���A�[���邽�߂Ɏg�p
				HMsgBoxHCtrl_SS[i].Location[0] = 0;//���t�g�o�[�̕\�����Ƃ��Ċm�ہi�{�b�N�X�����������o���Ȃ��̂ŁC�f�B�X�v���C�G���A�P��Pading[1]��18�ɂ��Ă�����G���A�̃��t�g�o�[�͏����o���Ȃ����߁j
				HMsgBoxHCtrl_SS[i].ParentArea_p = &SyoumonArea;//�G���A�̎w��
				HMsgBoxHCtrl_SS[i].OuterWidth = HMsgBoxHCtrl_SS[i].Width + HMsgBoxHCtrl_SS[i].MsgBoxForm_p->Margin[0] + HMsgBoxHCtrl_SS[i].MsgBoxForm_p->Margin[2];
				HMsgBoxHCtrl_SS[i].OuterHeight = HMsgBoxHCtrl_SS[i].Height + HMsgBoxHCtrl_SS[i].MsgBoxForm_p->Margin[1] + HMsgBoxHCtrl_SS[i].MsgBoxForm_p->Margin[3];
			}
		}
		int nukeru = 0;
		//////////�����ҏW���C�����[�v�̎n�܂聫////////////////////�����ҏW���C�����[�v�̎n�܂聫///////////////////�����ҏW���C�����[�v�̎n�܂聫///////////////////�����ҏW���C�����[�v�̎n�܂聫/////////
		for (int frameH = 0; !nukeru && !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !MathgpUpdateMouse() && !MathgpUpdateKey(); frameH++) {//�}�E�X�E�L�[�{�[�h
			//������������ҋ@
			SleepToFitFPS(FPS);

			int rot = GetMouseWheelRotVol(); //�O�񂩂�̃}�E�X�z�C�[���̉�]�̑����ʂ����Z
			//�����X�^�[�e�[�u���̃X�N���[���i�\������v�f�ԍ��̊m��Ɏg�p�j
			if (MonsterFlag == 2) popupRot -= rot;//�}�E�X�z�C�[���̉�]�ʂ̍��v�l�i����]��popupRot�͑����j
			//����̃X�N���[���i�\���ʒu�̊m��Ɏg�p�j
			else {
				Rot += rot;//�}�E�X�z�C�[���̉�]�ʂ̍��v�l�i����]��Rot�͌����j
				if (Rot > 0) Rot = 0;//����̈ʒu�����������Ȃ��iRot���O���傫�����Ȃ��j
			}
			//�c�[���o�[
			ShowArea(Toolbar, 2);
			////�@�c�[���o�[A�@////
			static int ClickedNoA = -1;//�����ꂽ�{�^���ԍ�
			//���c�[���i�v���_�E�����X�g�j
			int ToolA_PushType = 0; int ToolA_Prev = -2; int ToolA_Next = -2;
			if (ShowButton(ToolA, ToolAKosuu, &ClickedNoA, ToolA_PushType, ToolA_Prev, ToolA_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				//�t�@�C���܂��̓X�^�C�����������u��
				if (ClickedNoA >= 0) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 0;
					MonsterFlag = 0;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��

					//���X�g���J���Ă��Ȃ���Ԃł̃N���b�N��
					//Mouse[MOUSE_INPUT_LEFT] = 2�́C�v���_�E�����X�g�������ɏ����Ă��܂��̂�h���i���X�g�͈̔͊O�N���b�N�ɊY�����邽�߁j�i�O�͂��߁B���̃��[�v�łɂ܂��P�ɂȂ��Ă��܂��j
					if (ClickedNoA == 0 && List0.Active != 1) { List0.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 1 && List1.Active != 1) { List1.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 2 && List2.Active != 1) { List2.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
				}

			}

			//�t�@�C���܂��̓X�^�C��������������
			else if (List0.Active == 1 || List1.Active == 1 || List2.Active == 1) {//�v���_�E����ԂŃJ�[�\�����w���{�^��������Ƃ�
				for (int i = 0; i < ToolAKosuu; i++) {
					if (ToolA[i].Active == 3) {//�J�[�\�����w���Ă���Ƃ���PulldownFlag������������
						if (i == 0) { List0.Active = 1; List1.Active = -1; List2.Active = -1; }
						else if (i == 1) { List0.Active = -1; List1.Active = 1; List2.Active = -1; }
						else if (i == 2) { List0.Active = -1; List1.Active = -1; List2.Active = 1; }
						break;
					}
				}
			}


			////�@�{�^���@////
			//���c�[���{�^��
			//AreaControlShow(ToolB[0].ParentArea_p, 1);//IndexArea_p
			int ClickedNo = -1;//�����ꂽ�{�^���ԍ�

			int ToolB_PushType = 0; int ToolB_Prev = -2; int ToolB_Next = -2;
			if (ShowButton(ToolB, ToolBKosuu, &ClickedNo, ToolB_PushType, ToolB_Prev, ToolB_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
			// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

				///////�z�[��
				if (ClickedNo == 0) {//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
					*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
					return 0;
				}
				///////�V�K�쐬//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�iNULL�j�C�t�@�C���^�C�g���i����j�C�G�f�B�^�[���[�h�i����}�}�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				else if (ClickedNo == 1) {
					char GetDir[MAX_PATH];
					//�_�C�A���O����f�B���N�g���̑I��
					if (LocalDir[0] == '\0') {
						strcpy(LocalDir, AppDir);
						strcat(LocalDir, "\\OriginalFile\\MondaiData");
					}
					if (GetOpenDirectoryName(LocalDir, GetDir, MAX_PATH)) {
						strcpy(FilePath_Mondai_h, GetDir);//) strcpy(FileTitle_Mondai, "����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
						strcat(FilePath_Mondai_h, "\\����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
						//�i�g���q�Ȃ��Ȃ̂Œ��ӁB�f�B���N�g�����Ɂu����.txt�v������΂�����J���Ă��܂����߁j

						//�f�B���N�g���̒�����Monster�Ƃ����f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCMonster���̊����̃t�@�C���͏����Ȃ��B
						SetCurrentDirectory(GetDir);
						CreateDirectory("Monster", NULL);
						CreateDirectory("Img", NULL);
						CreateDirectory("Sound", NULL);
					}
					char DirectoryNow1[MAX_PATH];
					GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p

					return 0;//���ҏW���[�h���甲����
				}
				///////�t�@�C�����J��
				else if (ClickedNo == 2) {
					//�_�C�A���O����t�@�C�������擾
					if (LocalDir[0] == '\0') {
						strcpy(LocalDir, AppDir);
						strcat(LocalDir, "\\OriginalFile\\MondaiData");
					}
					//LocalDir�͌����_�ŊJ���Ă���t�@�C���̃f�B���N�g���B���ꂪ�Ȃ��Ƃ��́u�`\\OriginalFile\\MondaiData�v
					char filepath[MAX_PATH]; char filetitle[MAX_PATH];
					if (GetOpenFileNameACK(LocalDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
					//���I�����̃J�����g�f�B���N�g���͖��t�@�C��������f�B���N�g���B�u�`\\OriginalFile\\MondaiData�v�Ƃ͌���Ȃ��̂Œ��ӁBMondaiDir�͌��̂܂�
					//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
						//�J�����t�@�C���̃��[�h�𒲂ׂ�
						ClearDrawScreen();
						switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
						case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
							strcpy(FilePath_Mondai_h, filepath);//�t�@�C���p�X�̊m��
							//if (*EditorMode_p != 1) LocalDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
							return 0;//���ҏW���[�h���甲����
						case -1:
							ShowMsgDsignedBox(-1, -1, 600,//�^�C�g���̃p�f�B���O5�C���b�Z�[�W�̃p�f�B���O20
								"�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60
							);
							WaitKey(); break;
						default://�����icase -2�j�j
							ShowMsgDsignedBox(-1, -1, 600,//�^�C�g���̃p�f�B���O5�C���b�Z�[�W�̃p�f�B���O20
								"�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60
							);
							WaitKey();
						}
					}
				}
				///////�㏑���ۑ�
				else if (ClickedNo == 3) {
					//���b�Z�[�W�̕ۑ�
					OverwriteMondai(FilePath_Mondai_h, FileTitle_Mondai, MAX_PATH, MAX_PATH, &mondai);//�㏑���ۑ��i�܂��͖��O��t���ĕۑ��j
					//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
					strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
					strcat(Titlebar_text, FileTitle_Mondai);//�t�@�C������A��
					SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
					//���b�Z�[�W�{�b�N�X�R���g���[���ƃ��b�Z�[�W�{�b�N�X�t�H�[���̕ۑ�
					SetCurrentDirectory(LocalDir);
					SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxFormNumber);
					SaveMsgBoxForm(".\\MsgBoxForm.txt", MsgBoxForm_Copy, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);
					SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
					//�������X�^�[�̂h�c���̕��בւ�
					char charbuff[MAX_PATH] = { 0 }; //�摜�t�@�C��
					int intbuff;
					struct Monster MinsterBuff;
					for (int i = 0; i < Monster_Kosuu; i++) {
						for (int j = Monster_Kosuu - 1; j > i; j--) {
							if (Monster[j - 1].Column[0] > Monster[j].Column[0] && Monster[j].Column[0] != 0) {

								MinsterBuff = Monster[j];
								Monster[j] = Monster[j - 1];
								Monster[j - 1] = MinsterBuff;

								strcpy(charbuff, MonsterImg_Path[j]);//�摜�p�X�̕��בւ�
								strcpy(MonsterImg_Path[j], MonsterImg_Path[j - 1]);
								strcpy(MonsterImg_Path[j - 1], charbuff);

								intbuff = MonsterImgWidth[j];
								MonsterImgWidth[j] = MonsterImgWidth[j - 1];
								MonsterImgWidth[j - 1] = intbuff;

								intbuff = MonsterImgHeight[j];
								MonsterImgHeight[j] = MonsterImgHeight[j - 1];
								MonsterImgHeight[j - 1] = intbuff;
							}
						}
					}
					//�������X�^�[�t�@�C���̕ۑ�
					SetCurrentDirectory(LocalDir);

					//char FilePath_Monster[MAX_PATH];//�����X�^�[�t�@�C���p�X���擾����ϐ�
					//strcpy(FilePath_Monster, LocalDir);//
					//if (LocalDir[0] != '\0') strcat(FilePath_Monster, "\\Monster\\monstertable.csv");//���f�B���N�g�����J���Ȃ�p�X���J���ɂȂ�
					////�����X�^�[�̃Z�[�u�i�t�@�C���p�X���J���Ȃ炷���ɔ����邩�牽���N����Ȃ��j
					SaveMonster(".\\Monster\\monstertable.csv", Monster, Monster_Kosuu, MaxMonsterID, ColumnTitle, Column_Kosuu, MonsterImg_Path);	//////////
				}
				///////�����X�^�[�ҏW
				else if (ClickedNo == 4) {
					char FilePath_Monster[MAX_PATH];//�����X�^�[�t�@�C���p�X���擾����ϐ�
					strcpy(FilePath_Monster, LocalDir);//
					if (LocalDir[0] != '\0') strcat(FilePath_Monster, "\\Monster\\monstertable.csv");//���f�B���N�g�����J���Ȃ�p�X���J���ɂȂ�
					ClearDrawScreen();
					if (!EditMonster(FilePath_Monster, Monster, &Monster_Kosuu, &MaxMonsterID, ColumnTitle, &Column_Kosuu, MonsterImg_Path, DisplayArea.BackImg)) {//�����X�^�[�ҏW���[�h
					/*
					//�����m�X�^�[�e�[�u���̍ēǂݍ���
						SetCurrentDirectory(LocalDir);//���t�@�C��������f�B���N�g�����J�����g�f�B���N�g���Ƃ���i�����Ő؂�ւ��Ȃ��Ă��C�_�C�A���O�őI���������_�ł��łɐ؂�ւ���Ă��邪�O�̂��߁j

						int error;
						switch (error = LoadMonster(".\\Monster\\monstertable.csv", MonsterH, Monster_name, Monster_gazou, MonsterImg, &ColumnKosuu, columntitle, &monstersuu)) {
						//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃t�@�C�������݂��܂���B", black, gray60); break;
						case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[��ID�p�J�����̃^�C�g�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
						case -5: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃J�����̃^�C�g�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
						case -7: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[��ID�p�J�������T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
						case -8: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃����X�^�[�����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
						case -9: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃����X�^�[�摜�p�X���T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
						case -10: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�����X�^�[�̃J�������T�C�Y�I�[�o�[���Ă��܂��B", black, gray60);

						}
						if (error < -1) DxLib::WaitKey();//�T�C�Y�I�[�o�[�ł����̂܂ܑ�����B-1�̓G���[�Ƃ��Ȃ�
						//���I�����̓����X�^�[�f�B���N�g��
*/
						if (Monster_Kosuu > TableMax) tablesuu = TableMax;//
						else tablesuu = Monster_Kosuu;

						SetCurrentDirectory(AppDir);//0720
						strcpy(Monster[Monster_Kosuu].Name, "�Y���Ȃ�");
						Monster[Monster_Kosuu].Img = LoadGraph(".\\System\\EditMondai\\notappricable.png");
						strcpy(Monster[Monster_Kosuu + 1].Name, "���ݒ�");
						Monster[Monster_Kosuu + 1].Img = LoadGraph(".\\System\\EditMondai\\notset.png");

						//�������X�^�[�ԍ��̊m��
						for (int i = 0; i < Monster_Kosuu; i++) {//�����X�^�[�i���o�[�i�����X�^�[�̗v�f�ԍ��j�̊m��
							if (mondai.monsterID == 0) {//ID���J���̂Ƃ��C�u���ݒ�v�ƂȂ�B
								MonsterNum = Monster_Kosuu + 1; break;
							}
							else if (mondai.monsterID == Monster[i].Column[0]) {
								MonsterNum = i; break;
							}
							else if (i == Monster_Kosuu - 1) {
								MonsterNum = Monster_Kosuu;  break;//�Ō�܂Ń`�F�b�N���Ă���v����ID���Ȃ��Ƃ��C�u�Y���Ȃ��v�ƂȂ�B
							}
						}


						//�������X�^�[�摜�T�C�Y�̎擾
						for (int i = 0; i < Monster_Kosuu + 2; i++) {//�����X�^�[�i���o�[�i�����X�^�[�̗v�f�ԍ��j�̊m��
							GetGraphSize(Monster[i].Img, &MonsterImgWidth[i], &MonsterImgHeight[i]); //�����X�^�[�̉摜�̏c���T�C�Y���擾����monsterwide�Cmonsterhight�ɏ����o��
						}
						//�^�C�g���o�[�̃e�L�X�g�̍X�V
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_Mondai);//�f�B���N�g������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
					}
					
				}
			}

			//�f�B�X�v���G���A�̕\��
			ShowArea(&DisplayArea, 1);



			/*
					DrawFormatString(Statusbar.Nest[0], Statusbar.Nest[1] - 24, black, "%s", LocalDir);//�f�B���N�g���̕\��
					DrawFormatString(Statusbar.Nest[0] + 400, Statusbar.Nest[1], black, "%s", ActiveMath::FileTitle_Font);//�t�H���g�Z�b�g�̕\��
					DrawFormatString(Statusbar.Nest[0] + 600, Statusbar.Nest[1], black, "%s", ActiveMath::FileTitle_FontImg);//�t�H���g�摜�Z�b�g�̕\��
					DrawFormatString(Statusbar.Nest[0] + 800, Statusbar.Nest[1], black, "%s", ActiveMath::FileTitle_Tag);//�^�O�Z�b�g�̕\��
			*/
			////////////���̓p�b�h//////////
			int ShowMsgBoxFlag = 0;//�O�F���b�Z�[�W�{�b�N�X��\�����Ȃ��@�O�ȊO�F���b�Z�[�W�{�b�N�X��\������@�����C��␳���C����C���␳���̂S����̂�ShowMsgBox�ŕʓr�ʂɕ\��

			if (ShowPadM(Message_p, MsgBoxCtrl_p, MsgSizeE, &InputHandleMath, ShowMsgBoxFlag, EditorIndex, EditorIndexKosuu, EditorButton_ph, EditorButtonKosuu, EditorBaseButton, EditorBaseButtonKosuu, EditorPadArea, &PadManager) == 1) {
				if (PadManager.InputButton_p != NULL && PadManager.InputButton_p->ButtonType == 4) {

					char Dir[MAX_PATH] = { 0 };//�f�B���N�g�����w�肷�邽�߂̕ϐ�
					int FileType = 0;//�摜�t�@�C��
					//�f�B���N�g���̌���
					if (!strcmp(PadManager.InputButton_p->PutText, "#img_lm{") || !strcmp(PadManager.InputButton_p->PutText, "#img_le{")) {//
						strcpy(Dir, LocalDir); strcat(Dir, "\\Img");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Img�ƂȂ�
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#img_am{") || !strcmp(PadManager.InputButton_p->PutText, "#img_ae{")) {//
						strcpy(Dir, Dir_AppImg);
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#img_nm{") || !strcmp(PadManager.InputButton_p->PutText, "#img_ne{")) {//
						strcpy(Dir, MsgDir);
					}

					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_l{")) {//
						strcpy(Dir, LocalDir); strcat(Dir, "\\Sound");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Sound�ƂȂ�
						FileType = 1;//�����t�@�C��
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_a{")) {//
						strcpy(Dir, Dir_AppSound);
						FileType = 1;//�����t�@�C��
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_n{")) {//
						strcpy(Dir, MsgDir);
						FileType = 1;//�����t�@�C��
					}
					//�f�B���N�g���̍쐬
					CreateDirectory(Dir, NULL);//Dir�̃f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCDir���̊����̃t�@�C���͏����Ȃ��B

					//�t�@�C���I���_�C�A���O
					char FilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
					char FileTitle[MAX_PATH];//�t�@�C�������擾����ϐ�
					if (*Dir != '\0' && GetImgFileName(Dir, FilePath, FileTitle, MAX_PATH, MAX_PATH, FileType)) {//�_�C�A���O�ɂ����t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
						char SoutaiPath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
						//�t�@�C���擾�ɐ���������t�@�C�����R�s�[���āCDir����݂��R�s�[�t�@�C���̑��΃p�X�i�܂�����̓t�@�C�����j���擾
						//�R�s�[�����t�@�C���̃t�@�C���p�X���쐬
						char CopyFilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
						strcpy(CopyFilePath, Dir);
						strcat(CopyFilePath, "\\");
						strcat(CopyFilePath, FileTitle);
						if (strcmp(FilePath, CopyFilePath)) {
							char CopyFilePath2[MAX_PATH] = { 0 };
							strcpy(CopyFilePath2, CopyFilePath);
							//�t�@�C�����R�s�[
							for (int num = 1; num < 10; num++) {//�i1�`9�܂ł̓����t�@�C�����쐬�\�j
								if (CopyFile(FilePath, CopyFilePath2, TRUE)) break;
								strcpy(CopyFilePath2, CopyFilePath);
								int point = strlen(CopyFilePath2);
								while (CopyFilePath2[point] != '.') point--;
								char kakuchoshi[5] = { 0 };
								for (int i = 0; CopyFilePath2[point + i] != '\0'; i++) kakuchoshi[i] = CopyFilePath2[point + i];
								CopyFilePath2[point] = '(';
								CopyFilePath2[point + 1] = '\0';
								char number[100];
								_itoa(num + 1, number, 10);
								strcat(CopyFilePath2, number);
								strcat(CopyFilePath2, ")");
								strcat(CopyFilePath2, kakuchoshi);
							}
							//���΃p�X���擾  ��(9)�܂ő��݂��Ă���Ȃ�R�[�h�ɂ�(10)���������܂�邪�摜�͍쐬����Ȃ��B
							PathRelativePathTo(SoutaiPath, Dir, FILE_ATTRIBUTE_DIRECTORY, CopyFilePath2, FILE_ATTRIBUTE_ARCHIVE);
						}
						else strcpy(SoutaiPath, FileTitle);//MsgDir���̉摜��I�������ꍇ�͉摜���R�s�[�����CFileTitle�����΃p�X�ƂȂ�

						////////////////////////////////////////////////////////////////////////////////////
						//�}�����镶����̍쐬
						char PutText[150];
						strcpy(PutText, PadManager.InputButton_p->PutText);
						strcat(PutText, SoutaiPath);
						strcat(PutText, "}");

						int PutTextMojisuu = strlen(PutText);//�}�����镶�������J�E���g
						int MessageMojisuu = strlen(Message_p);//���b�Z�[�W�̕��������擾

						//��������
						if (MessageMojisuu + PutTextMojisuu < MsgSizeE) {// return -1;//�T�C�Y�I�[�o�[���Ȃ��悤��
							int point = MsgBoxCtrl_p->Tag[0].PositionP;//tag[0].PositionP��*ActiveElement
							for (int i = MessageMojisuu; i >= point; i--) Message_p[i + PutTextMojisuu] = Message_p[i];//���������镶����̕��������ɂ��炷�B//�Ԃ�������
							for (int i = 0; i < PutTextMojisuu; i++) Message_p[point + i] = PutText[i]; //�A�N�e�B�u�ȗv�f�ȍ~�̔z��v�f�ɁC����������������� //�������}������i�A�N�e�B�u�ȗv�f����C���炵�ĊJ�����ʒu�܂Łj
							MsgBoxCtrl_p->Tag[0].PositionP += PutTextMojisuu;//tag[0].PositionP��*ActiveElement
							MsgBoxCtrl_p->Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
						}
					}
				}
			}


			//////////���t�@�C����������Ȃ珈�����Ȃ������̏�[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��
			if (FilePath_Mondai_h[0] != '\0') {//

				///////�i�R�j�����X�^�[�e�[�u��
				//����
				if (MonsterFlag == 1) {

					if (monstertableall.tablewaku[0] < ActiveMath::MouseX && ActiveMath::MouseX < monstertableall.tablewaku[2] && monstertableall.tablewaku[1] < ActiveMath::MouseY && ActiveMath::MouseY < monstertableall.tablewaku[3]) {//�e�[�u���͈͓̔��̂Ƃ�
						DrawBox(monstertableall.tablewaku[0], monstertableall.tablewaku[1], monstertableall.tablewaku[2], monstertableall.tablewaku[3], cursorColorbuff, true);//�J�[�\���̕\��

						if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1 && tablesuu > 0) {
							ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; //�|�b�v�A�b�v���Ŕ������Ȃ��悤�Ɂi�|�b�v�A�b�v�͈̔͊O�ŃN���b�N���Ă��邱�ƂɂȂ邩��|�b�v�A�b�v�������ɏ����Ă��܂����߁j�i�O�͂��߁B���̃��[�v�łɂ܂��P�ɂȂ��Ă��܂��j
							activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
							monstertableallsyokika(PulldownList_Monster[0] + 5, PulldownList_Monster[1] + 10 + SystemFontSize, MonsterTable_pd, tablesuu);//�����X�^�[�e�[�u���̏�����

							PulldownList_Monster[3] = MonsterTable_pd[tablesuu - 1].tablewaku[3] + 5;//��胍�[�h���ƂɃ����X�^�[�����[�h����̂ŁC�\���O�Ƀ��X�g�̉��[�𖈉�ς���
							Toolbar[0].Active = 2; Toolbar[1].Active = 2;  DisplayArea.Active = 2; SyoumonArea.Active = 2;//����
							for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 2;
							MonsterFlag = 2;//�I�����
							copyno = -1;//�R�s�[���ԍ��̎������i����Ɋ֌W�̂Ȃ������ɓ������̂ŁC�R�s�[���ԍ��͎������j
							SyoumonArea.Active = 0;//�|�P�F��\���@�O�F�����@�P�F�ҋ@

						}
					}
				}
				DrawString(monstertableall.tablewaku[0], monstertableall.tablewaku[1] - SystemFontSize -2, "�����X�^�[:", gray);//���o���̕\��
																														//�e�[�u���̕\��
																														//////�g�̕⊮�ƑS�̘g ��
				DrawBox(monstertableall.column[0][2], monstertableall.column[0][1], monstertableall.tablewaku[2], monstertableall.name[3], gray, false);//�g�̕⊮
				DrawBox(monstertableall.tablewaku[0], monstertableall.tablewaku[1], monstertableall.tablewaku[2], monstertableall.tablewaku[3], gray, false);//�S�̘g
				DrawBox(monstertableall.tablewaku[0] + 1, monstertableall.tablewaku[1] + 1, monstertableall.tablewaku[2] - 1, monstertableall.tablewaku[3] - 1, gray, false);//�S�̘g
				DrawBox(monstertableall.yousono[0], monstertableall.yousono[1], monstertableall.yousono[2], monstertableall.yousono[3], gray, false);//�����X�^�[�v�f�ԍ��̘g
				DrawFormatString(monstertableall.yousono[0] + 4, monstertableall.yousono[1] + 4, white, "%d", MonsterNum);//�u�����X�^�[�̗v�f�ԍ��|�Q�v�̕\���@�|2�͖��ݒ�ƊY���Ȃ��̕�


				//�����̈�̎擾
				RECT DrawAreaBuff;
				GetDrawArea(&DrawAreaBuff);
				int Range[4] = { DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom };//�����̈���擾���邽�߂̔z��
				//�������o���\�̈��ݒ�@�@���̕`��\�̈�� ���� �����X�^�[�摜�̗̈��
				Overlap(Range, monstertableall.gazou);//
				//���`��\�̈�̊m��
				SetDrawArea(Range[0], Range[1], Range[2], Range[3]);
				//�������X�^�[�摜
				int centerX = monstertableall.gazou[0] + 44; int centerY = monstertableall.gazou[1] + 44;////�����X�^�[�摜�̘g�̒��S
				int Rate = 3;//������2/3�̑傫���ŕ\���i���S���獶�E��1/3�̈ʒu�j
				if (Monster[MonsterNum].Img != -1) DrawExtendGraph(centerX - MonsterImgWidth[MonsterNum] / Rate, centerY - MonsterImgHeight[MonsterNum] / Rate, centerX + MonsterImgWidth[MonsterNum] / Rate, centerY + MonsterImgHeight[MonsterNum] / Rate, Monster[MonsterNum].Img, true);
				else DrawExtendGraph(centerX - Undefined_MonsterImgWidth / Rate, centerY - Undefined_MonsterImgHeight / Rate, centerX + Undefined_MonsterImgWidth / Rate, centerY + Undefined_MonsterImgHeight / Rate, Undefined_MonsterImg, true);

					//���`��\�̈�����ɖ߂�
				SetDrawArea(DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom);




				DrawBox(monstertableall.gazou[0], monstertableall.gazou[1], monstertableall.gazou[2], monstertableall.gazou[3], gray, false);//�����X�^�[�摜�̘g
																																									//�\��
				int titlecolor2 = GetColor(0, 51, 102);
				int titlecolor = GetColor(0, 102, 153);
				DrawBox(monstertableall.columntitle[0][0], monstertableall.columntitle[0][1], monstertableall.column[0][2], monstertableall.column[0][3], gray, false);////�J�����O�i�h�c)�^�C�g���ƃJ�����O�i�h�c�j�̘A���g
				DrawBox(monstertableall.columntitle[0][0] + 1, monstertableall.columntitle[0][1] + 1, monstertableall.columntitle[0][2] - 1, monstertableall.columntitle[0][3] - 1, titlecolor2, true);//�J�����O�i�h�c�j�^�C�g���̔w�i
				DrawString(monstertableall.columntitle[0][0] + 4, monstertableall.columntitle[0][1] + 4, ColumnTitle[0], white);//�J�����O�i�h�c�j�^�C�g���̕\��
				DrawFormatString(monstertableall.column[0][0] + 4, monstertableall.column[0][1] + 4, white, "%d", mondai.monsterID);//�J�����O�i�h�c�j�̕\�� MonsterH[monsterno][0]

				DrawBox(monstertableall.nametitle[0], monstertableall.nametitle[1], monstertableall.name[2], monstertableall.name[3], gray, false);//�����X�^�[���^�C�g���ƃ����X�^�[���̘A���g
				DrawBox(monstertableall.nametitle[0] + 1, monstertableall.nametitle[1] + 1, monstertableall.nametitle[2] - 1, monstertableall.nametitle[3] - 1, titlecolor2, true);//�����X�^�[���^�C�g���̔w�i
				DrawString(monstertableall.nametitle[0] + 4, monstertableall.nametitle[1] + 4, "���O", white);//�����X�^�[���^�C�g���̕\��
				if (Monster[MonsterNum].Name[0] != '\0') DrawFormatString(monstertableall.name[0] + 4, monstertableall.name[1] + 4, white, "%s", Monster[MonsterNum].Name);//�����X�^�[���̕\��
				else DrawFormatString(monstertableall.name[0] + 4, monstertableall.name[1] + 4, white, "%s", Undefined_MonsterName);//�����X�^�[���̕\��
				for (int k = 1; k < 15; k++) {//MONSTER_COLUMNMAX��20������1�`19�܂ł��邪�C�e�[�u���ɕ\���ł���̂�1�`14�܂łƂ���
					DrawBox(monstertableall.columntitle[k][0], monstertableall.columntitle[k][1], monstertableall.column[k][2], monstertableall.column[k][3], gray, false);//�J�����i���Ԗځj�^�C�g���ƃJ�����i���Ԗځj�̘A���g
					if (k < Column_Kosuu) {//�J�����̌��̕������l��\������
						DrawBox(monstertableall.columntitle[k][0] + 1, monstertableall.columntitle[k][1] + 1, monstertableall.columntitle[k][2] - 1, monstertableall.columntitle[k][3] - 1, titlecolor, true);//�J�����i���Ԗځj�^�C�g���̔w�i
						DrawFormatString(monstertableall.columntitle[k][0] + 4, monstertableall.columntitle[k][1] + 4, white, "%s", ColumnTitle[k]);//�J�����i���Ԗځj�^�C�g���̕\��
						DrawFormatString(monstertableall.column[k][0] + 4, monstertableall.column[k][1] + 4, white, "%d", Monster[MonsterNum].Column[k]);//�J�����i���Ԗځj�̕\��
					}
				}
				////////�i�S�j���͂̏���

				//DrawLine(0, 80, 1000, 80, yellow, 1);//�`�F�b�N�p
				//DrawLine(0, 193, 1000, 193, red, 1);//�`�F�b�N�p

				int StrLen;
				///////���
				//�����c�[���o�[�G���A
				static struct AREACONTROL D_Toolbar = { 0 };
				D_Toolbar.ParentArea_p = &DisplayArea;
				D_Toolbar.Location[1] = monstertableall.tablewaku[3] - 80-16+5;//�����X�^�[�e�[�u�����G���A�R���g���[���ɓ�������u�@- 80�@�i�u�|�i�c�[���o�[24+�p�b�h�G���A56�j�v�j�v�̕����͕s�v����������B;
				D_Toolbar.Width = 953;
				D_Toolbar.Height = 24;
				D_Toolbar.BackTransparency = 80;
				D_Toolbar.BackColor = GetColor(255, 255, 255);//204, 204, 204
				D_Toolbar.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
				//�����c�[���{�^���t�H�[��
				static struct BUTTONFORM Mondai_ToolForm = { 0 };
				Mondai_ToolForm.Margin[0] = 1; Mondai_ToolForm.Margin[1] = 0; Mondai_ToolForm.Margin[2] = 1; Mondai_ToolForm.Margin[3] = 0;//
				Mondai_ToolForm.CursorColor = GetColor(255, 255, 204);
				//�����c�[���{�^��
				const int D_ToolKosuu = 1;
				static struct BUTTONCONTROL D_Tool[D_ToolKosuu] = { 0 };
				strcpy(D_Tool[0].String, "�ڍוҏW");
				if (D_Tool[0].WaitingImg == -1) {
					D_Tool[0].WaitingImg = LoadGraph(".\\System\\Fixed\\edit24.png");
					D_Tool[0].CursorImg = LoadGraph(".\\System\\Fixed\\edit24b.png");
					D_Tool[0].PushedImg = D_Tool[0].CursorImg;
				}
				for (int i = 0; i < D_ToolKosuu; i++) {
					D_Tool[i].ParentArea_p = &D_Toolbar;
					if (i == 0) D_Tool[i].Location[0] = 100;
					else D_Tool[i].Location[0] = -111111;

					D_Tool[i].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
					D_Tool[i].ButtonForm_p = &Mondai_ToolForm;
				}
				char DirectoryNow[MAX_PATH];
				GetCurrentDirectory(MAX_PATH, DirectoryNow);//����̃J�����g�f�B���N�g�������m��


				//���c�[���o�[
				ShowArea(&D_Toolbar, 1);
				DrawStringInArea(5, 5, &D_Toolbar, "���:", black);//���o���̕\��
				int D_Tool_PushType = 0; int D_Tool_Prev = -2; int D_Tool_Next = -2;
				if (ShowButton(D_Tool, D_ToolKosuu, &ClickedNo, D_Tool_PushType, D_Tool_Prev, D_Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
					if (ClickedNo == 0) {//�v���r���[
						//�{���̒l�ɖ߂�
						for (int i = 0; i < MsgBoxForm_Kosuu; i++) MsgBoxForm[i] = MsgBoxForm_Copy[i];
						//�ڍוҏW���[�h
						int MsgBoxCtrlNumber = 0;
						int AreaNumber = 0;
						//�v���r���[���[�h��
						MessagePreviewMode(MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, MsgBoxForm, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, MsgBoxFormNumber,
							mondai.daimon, DAIMON_FIELDSIZE + 1, DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview_Kosuu, AreaNumber,
							FilePath_Mondai_h, FileTitle_Mondai, &mondai, EditorMode_p, &ExitModeFlag
						);
						if (ExitModeFlag) return 0;
						nukeru = 1;
					}
				}
				//���̕\��
				HMsgBoxHCtrl_D.Location[1] = D_Toolbar.Location[1] + D_Toolbar.Margin[1] + D_Toolbar.Height + D_Toolbar.Margin[3];//�����X�^�[�e�[�u�����G���A�R���g���[���ɓ�������u�@- 72�@�v�̕����͕s�v����������B
				ShowMsgBox(mondai.daimon, &HMsgBoxHCtrl_D); //���̏����o��, &MessageManager
				ChangeImgAlign(mondai.daimon, &HMsgBoxHCtrl_D);//�摜�̃N���b�N�ŏ㉺�ʒu�̕ύX�i�N���b�N��̃^�O�ǎ�莞�ɋL�^�����^�O���̗v�f�ԍ����g�p�j
				if (HMsgBoxHCtrl_D.Tag[0].PositionP == 0) {//tag[0].PositionP��ActiveElement�̑�p
					//���ȊO�̃A�N�e�B�u���N���A����
					HMsgBoxHCtrl_DS.Tag[0].PositionP = -1;
					if (activesyoumonH >= 0) HMsgBoxHCtrl_S[activesyoumonH].Tag[0].PositionP = -1;//������A�N�e�B�u�ɂ���B
					if (activesyoumonseikaiH >= 0) HMsgBoxHCtrl_SS[activesyoumonseikaiH].Tag[0].PositionP = -1;//���␳�����A�N�e�B�u�ɂ���B
					activesyoumonH = -1;
					activesyoumonseikaiH = -1;
					//�p�b�h�Ŏg���郁�b�Z�[�W����ɂ���
					Message_p = mondai.daimon; MsgSizeE = sizeof(mondai.daimon); MsgBoxCtrl_p = &HMsgBoxHCtrl_D;
					MasterHeight = MsgBoxCtrl_Master[0].Height;


					//�p�b�h�̃{�^���G���A�ƃx�[�X�{�^���G���A���u�P�F�ҋ@��ԁv�ɂ���
					EditorPadArea[1].Active = 1; EditorPadArea[2].Active = 1;
				}


				/*Ctrl+Q�ŕ\������悤�ɉ��ǂ���@�@///�}�[�W���̊O���̃��C���̊m�F�p�Ӂ�
				int box[4] = {
				HMsgBoxHCtrl_D.Parent->Nest[0] + HMsgBoxHCtrl_D.Location[0],
				HMsgBoxHCtrl_D.Parent->Nest[1] + HMsgBoxHCtrl_D.Location[1],
				box[0] + HMsgBoxHCtrl_D.OuterWidth,
				box[1] + HMsgBoxHCtrl_D.OuterHeight
				};
				DrawBox(box[0], box[1], box[2], box[3], white, false);
				////�}�[�W���̊O���̃��C���̊m�F�p��*/

				///////��␳��
				//����␳���c�[���o�[�G���A
				static struct AREACONTROL DS_Toolbar = { 0 };
				DS_Toolbar.ParentArea_p = &DisplayArea;
				DS_Toolbar.Location[1] = HMsgBoxHCtrl_D.Location[1] + HMsgBoxHCtrl_D.OuterHeight+5;//

				DS_Toolbar.Width = 953;
				DS_Toolbar.Height = 24;//(D_Tool[i].Padding[1] = 3) + (D_Tool[i].Padding[3] = 3) = 6
				DS_Toolbar.BackTransparency = 80;
				DS_Toolbar.BackColor = GetColor(225, 225, 225);//204, 204, 204
				DS_Toolbar.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
				//����␳���c�[���{�^��
				const int DS_ToolKosuu = 1;
				static struct BUTTONCONTROL DS_Tool[DS_ToolKosuu] = { 0 };
				strcpy(DS_Tool[0].String, "�ڍוҏW");
				if (DS_Tool[0].WaitingImg == -1) {
					DS_Tool[0].WaitingImg = D_Tool[0].WaitingImg;
					DS_Tool[0].CursorImg = D_Tool[0].CursorImg;
					DS_Tool[0].PushedImg = D_Tool[0].CursorImg;
				}

				for (int i = 0; i < DS_ToolKosuu; i++) {
					DS_Tool[i].ParentArea_p = &DS_Toolbar;
					if (i == 0) DS_Tool[i].Location[0] = 100;//
					else DS_Tool[i].Location[0] = -111111;
					DS_Tool[i].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
					DS_Tool[i].ButtonForm_p = &Mondai_ToolForm;
				}
				//��␳���c�[���o�[
				ShowArea(&DS_Toolbar, 1);
				DrawStringInArea(5, 5, &DS_Toolbar, "��␳��:", black);//���o���̕\��

				int DS_Tool_PushType = 0; int DS_Tool_Prev = -2; int DS_Tool_Next = -2;
				if (ShowButton(DS_Tool, DS_ToolKosuu, &ClickedNo, DS_Tool_PushType, DS_Tool_Prev, DS_Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
					//���b�Z�[�W�v���r���[���[�h
					if (ClickedNo == 0) {
						//�{���̒l�ɖ߂�
						for (int i = 0; i < MsgBoxForm_Kosuu; i++) MsgBoxForm[i] = MsgBoxForm_Copy[i];
						//�v���r���[���[�h
						int MsgBoxCtrlNumber = 1;
						int AreaNumber = 1;
						MessagePreviewMode(MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, MsgBoxForm, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, MsgBoxFormNumber,
							mondai.daimonseikai, DAIMONSEIKAI_FIELDSIZE + 1, DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview_Kosuu, AreaNumber,
							FilePath_Mondai_h, FileTitle_Mondai, &mondai, EditorMode_p, &ExitModeFlag
						);
						if (ExitModeFlag) return 0;
						nukeru = 1;
					}
				}
				HMsgBoxHCtrl_DS.Location[1] = DS_Toolbar.Location[1] + DS_Toolbar.Margin[1] + DS_Toolbar.Height + DS_Toolbar.Margin[3];
				//��␳���̕\��
				ShowMsgBox(mondai.daimonseikai, &HMsgBoxHCtrl_DS); //��␳���̏����o��
				ChangeImgAlign(mondai.daimonseikai, &HMsgBoxHCtrl_DS);//�摜�̃N���b�N�ŏ㉺�ʒu�̕ύX�i�N���b�N��̃^�O�ǎ�莞�ɋL�^�����^�O���̗v�f�ԍ����g�p�j
				if (HMsgBoxHCtrl_DS.Tag[0].PositionP == 0) {//tag[0].PositionP��ActiveElement�̑�p
					//��␳���ȊO�̃A�N�e�B�u���N���A����
					HMsgBoxHCtrl_D.Tag[0].PositionP = -1;
					if (activesyoumonH >= 0) HMsgBoxHCtrl_S[activesyoumonH].Tag[0].PositionP = -1;//������A�N�e�B�u�ɂ���B
					if (activesyoumonseikaiH >= 0) HMsgBoxHCtrl_SS[activesyoumonseikaiH].Tag[0].PositionP = -1;//���␳�����A�N�e�B�u�ɂ���B
					activesyoumonH = -1;
					activesyoumonseikaiH = -1;
					//�p�b�h�Ŏg���郁�b�Z�[�W���␳���ɂ���
					Message_p = mondai.daimonseikai; MsgSizeE = sizeof(mondai.daimonseikai); MsgBoxCtrl_p = &HMsgBoxHCtrl_DS;
					MasterHeight = MsgBoxCtrl_Master[1].Height;
					//�p�b�h�̃{�^���G���A�ƃx�[�X�{�^���G���A���u�P�F�ҋ@��ԁv�ɂ���
					EditorPadArea[1].Active = 1; EditorPadArea[2].Active = 1;
				}

				int daimonbottom = HMsgBoxHCtrl_DS.Location[1] + HMsgBoxHCtrl_DS.OuterHeight + DisplayArea.Padding[3]+5;//DisplayArea.Nest[3]

				//�f�B�X�v���C�G���A�Q�@�i�Œ肳�ꂽ�̈�j
				DisplayArea2.Location[1] = daimonbottom;
				DisplayArea2.Height = Statusbar.Location[1] - (DisplayArea.Nest[1] + DisplayArea2.Location[1]);//

				ShowArea(&DisplayArea2, 1);

				//����G���A�@�i�f�B�X�v���C�G���A�Q�̒��ɂ���X�N���[������̈�j
				SyoumonArea.Location[1] = Rot * 50;//����G���A���}�E�X�ŃX�N���[������

				ShowArea(&SyoumonArea, 1);

				////////////////////////////////////////////////////////////////
				//����C���␳���{�b�N�X�̕\���i�P�t���[���O�̒l���g���Ă��邱�Ƃɒ��Ӂj
				if (SyoumonCutFlag == 1) {
					syoumonsuu--;
					SyoumonCutFlag = 0;
				}
				////////����C���␳��
				for (int s = 0; s < syoumonsuu; s++) {
					//����
					//������c�[���o�[�G���A
					static struct AREACONTROL S_Toolbar = { 0 };
					S_Toolbar.ParentArea_p = &SyoumonArea;
					if (s == 0) S_Toolbar.Location[1] = 5;
					else S_Toolbar.Location[1] = HMsgBoxHCtrl_SS[s - 1].Location[1] + HMsgBoxHCtrl_SS[s - 1].OuterHeight+5;//
					S_Toolbar.Width = 953;
					S_Toolbar.Height = 24;// systemfontsize + 6;//(D_Tool[s].Padding[1] = 3) + (D_Tool[s].Padding[3] = 3) = 6
					S_Toolbar.BackTransparency = 80;
					S_Toolbar.BackColor = GetColor(255, 255, 255);//204, 204, 204
					S_Toolbar.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
					//������c�[���{�^��
					SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
					const int S_ToolKosuu = 8;//Max�CKosuu
					static struct BUTTONCONTROL S_Tool[S_ToolKosuu] = { 0 };

					strcpy(S_Tool[0].String, "�؂���");
					if (S_Tool[0].WaitingImg == -1) {
						S_Tool[0].WaitingImg = LoadGraph(".\\System\\Fixed\\cut24.png");
						S_Tool[0].CursorImg = LoadGraph(".\\System\\Fixed\\cut24b.png");
						S_Tool[0].PushedImg = S_Tool[0].CursorImg;
					}

					strcpy(S_Tool[1].String, "�R�s�[");
					if (S_Tool[1].WaitingImg == -1) {
						S_Tool[1].WaitingImg = LoadGraph(".\\System\\Fixed\\copy24.png");
						S_Tool[1].CursorImg = LoadGraph(".\\System\\Fixed\\copy24b.png");
						S_Tool[1].PushedImg = S_Tool[1].CursorImg;
					}

					strcpy(S_Tool[2].String, "�\��t��");
					if (S_Tool[2].WaitingImg == -1) {
						S_Tool[2].WaitingImg = LoadGraph(".\\System\\Fixed\\paste24.png");
						S_Tool[2].CursorImg = LoadGraph(".\\System\\Fixed\\paste24b.png");
						S_Tool[2].PushedImg = S_Tool[2].CursorImg;
					}

					strcpy(S_Tool[3].String, "�V��������̑}��");
					if (S_Tool[3].WaitingImg == -1) {
						S_Tool[3].WaitingImg = LoadGraph(".\\System\\Fixed\\insertnew24.png");
						S_Tool[3].CursorImg = LoadGraph(".\\System\\Fixed\\insertnew24b.png");
						S_Tool[3].PushedImg = S_Tool[3].CursorImg;
					}
					strcpy(S_Tool[4].String, "�؂���E�R�s�[��������̑}��");
					if (S_Tool[4].WaitingImg == -1) {
						S_Tool[4].WaitingImg = LoadGraph(".\\System\\Fixed\\insert24.png");
						S_Tool[4].CursorImg = LoadGraph(".\\System\\Fixed\\insert24b.png");
						S_Tool[4].PushedImg = S_Tool[4].CursorImg;
					}
					strcpy(S_Tool[5].String, "�R�s�[���̏���Ɠ���ւ�");
					if (S_Tool[5].WaitingImg == -1) {
						S_Tool[5].WaitingImg = LoadGraph(".\\System\\Fixed\\exchange24.png");
						S_Tool[5].CursorImg = LoadGraph(".\\System\\Fixed\\exchange24b.png");
						S_Tool[5].PushedImg = S_Tool[5].CursorImg;
					}
					strcpy(S_Tool[6].String, "�N���A�[");
					if (S_Tool[6].WaitingImg == -1) {
						S_Tool[6].WaitingImg = LoadGraph(".\\System\\Fixed\\clear24.png");
						S_Tool[6].CursorImg = LoadGraph(".\\System\\Fixed\\clear24b.png");
						S_Tool[6].PushedImg = S_Tool[6].CursorImg;
					}
					strcpy(S_Tool[7].String, "�ڍוҏW");
					if (S_Tool[7].WaitingImg == -1) {
						S_Tool[7].WaitingImg = D_Tool[0].WaitingImg;
						S_Tool[7].CursorImg = D_Tool[0].CursorImg;
						S_Tool[7].PushedImg = D_Tool[0].PushedImg;
					}

					for (int i = 0; i < S_ToolKosuu; i++) {
						S_Tool[i].ParentArea_p = &S_Toolbar;
						if (i == 0) S_Tool[i].Location[0] = 100;
						else S_Tool[i].Location[0] = -111111;
						S_Tool[i].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
						S_Tool[i].ButtonForm_p = &Mondai_ToolForm;
					}

					ShowArea(&S_Toolbar, 1);
					DrawFormatStringInArea(5, 5, &S_Toolbar, black, "����%d:", s + 1);//���o���̕\��
					int S_Tool_PushType = 0; int S_Tool_Prev = -2; int S_Tool_Next = -2;
					if (ShowButton(S_Tool, S_ToolKosuu, &ClickedNo, S_Tool_PushType, S_Tool_Prev, S_Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
					// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)

						if (ClickedNo == 0) {//�؂���
							activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�{�^���������O�̕ҏW���ڂ̃A�N�e�B�u�����Z�b�g

							strcpy(mondai.syoumon[SYOUMON_MAX], mondai.syoumon[s]);
							strcpy(mondai.syoumonseikai[SYOUMON_MAX], mondai.syoumonseikai[s]);
							if (s < syoumonsuu - 1) {
								for (int m = s; m < syoumonsuu - 1; m++) {
									strcpy(mondai.syoumon[m], mondai.syoumon[m + 1]);
									strcpy(mondai.syoumonseikai[m], mondai.syoumonseikai[m + 1]);

									HMsgBoxHCtrl_S[m].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
									HMsgBoxHCtrl_SS[m].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								}
							}
							strcpy(mondai.syoumon[syoumonsuu - 1], "<p></p>");
							strcpy(mondai.syoumonseikai[syoumonsuu - 1], "<math></math>");
							HMsgBoxHCtrl_S[syoumonsuu - 1].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							HMsgBoxHCtrl_SS[syoumonsuu - 1].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���

							copyno = -1;//�R�s�[���ԍ��̎�����
							SyoumonCutFlag = 1;//����ŏI�c�[���{�^�������ꍞ��ł��Ȃ��悤�ɁC���␔�����炷�͎̂��̃t���[���B
							//���ŏI�̏���؂��莞�Ɂu�؂���v�{�^�����C����ŏI�c�[���{�^���́u����ǉ��v�Əd�Ȃ��Ă��܂��̂��h����
						}
						else if (ClickedNo == 1) {//�R�s�[
							activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
							strcpy(mondai.syoumon[SYOUMON_MAX], mondai.syoumon[s]);
							strcpy(mondai.syoumonseikai[SYOUMON_MAX], mondai.syoumonseikai[s]);
							copyno = s; //�R�s�[���ԍ��̎擾
						}
						else if (ClickedNo == 2) {//�\��t��
							if (mondai.syoumon[SYOUMON_MAX][0] != '\0') {
								activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�{�^���������O�̕ҏW���ڂ̃A�N�e�B�u�����Z�b�g
									//�\��t������
								strcpy(mondai.syoumon[s], mondai.syoumon[SYOUMON_MAX]);
								strcpy(mondai.syoumonseikai[s], mondai.syoumonseikai[SYOUMON_MAX]);
								//�\��t������Ԃ������o���i�^�O��ǂ݂Ƃ�j
								HMsgBoxHCtrl_S[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								HMsgBoxHCtrl_SS[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							}
						}
						else if (ClickedNo == 3) {//�}�� && S_Tool[1].Nest[3] > DisplayArea2.Nest[1]
							activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g

							for (int m = syoumonsuu; m >= s; m--) {
								strcpy(mondai.syoumon[m + 1], mondai.syoumon[m]);
								strcpy(mondai.syoumonseikai[m + 1], mondai.syoumonseikai[m]);
							}
							strcpy(mondai.syoumon[s], "<p></p>");
							strcpy(mondai.syoumonseikai[s], "<math></math>");
							syoumonsuu++;
							if (copyno >= s) copyno++;//�}�����Ă��ꂽ�������ԍ������炷
							for (int p = s; p < syoumonsuu; p++) {//�}�������ӏ��ȍ~�͏����o�����Ƀ^�O��ǂݎ��
								HMsgBoxHCtrl_S[p].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								HMsgBoxHCtrl_SS[p].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							}
						}
						else if (ClickedNo == 4) {//�}���\�t && S_Tool[5].Nest[3] > DisplayArea2.Nest[1]
							if (mondai.syoumon[SYOUMON_MAX][0] != '\0') {
								activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
								for (int m = syoumonsuu; m >= s; m--) {
									strcpy(mondai.syoumon[m + 1], mondai.syoumon[m]);
									strcpy(mondai.syoumonseikai[m + 1], mondai.syoumonseikai[m]);
									HMsgBoxHCtrl_S[m].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
									HMsgBoxHCtrl_SS[m].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								}
								strcpy(mondai.syoumon[s], mondai.syoumon[SYOUMON_MAX]);
								strcpy(mondai.syoumonseikai[s], mondai.syoumonseikai[SYOUMON_MAX]);
								HMsgBoxHCtrl_S[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								HMsgBoxHCtrl_SS[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���

								syoumonsuu++;
								if (copyno >= s) copyno++;//�}�����Ă��ꂽ�������ԍ������炷

							}
						}
						else if (ClickedNo == 5) {//����ւ� && S_Tool[6].Nest[3] > DisplayArea2.Nest[1]
							if (copyno >= 0) {
								activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
																																								 ////////
								strcpy(mondai.syoumon[copyno], mondai.syoumon[s]);
								strcpy(mondai.syoumonseikai[copyno], mondai.syoumonseikai[s]);
								strcpy(mondai.syoumon[s], mondai.syoumon[SYOUMON_MAX]);
								strcpy(mondai.syoumonseikai[s], mondai.syoumonseikai[SYOUMON_MAX]);

								HMsgBoxHCtrl_S[copyno].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								HMsgBoxHCtrl_SS[copyno].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								HMsgBoxHCtrl_S[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								HMsgBoxHCtrl_SS[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
								copyno = s; //�R�s�[���ԍ��̎擾
							}
						}
						else if (ClickedNo == 6) {//�N���A�[ && S_Tool[7].Nest[3] > DisplayArea2.Nest[1]
							activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�{�^���������O�̕ҏW���ڂ̃A�N�e�B�u�����Z�b�g
							//���b�Z�[�W�̃N���A�[
							strcpy(mondai.syoumon[s], "<p></p>");
							strcpy(mondai.syoumonseikai[s], "<math></math>");
							//�N���A�[������Ԃ������o���i�^�O��ǂ݂Ƃ�j
							HMsgBoxHCtrl_S[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							HMsgBoxHCtrl_SS[s].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							copyno = -1;//�R�s�[���ԍ��̖�����

						}
						else if (ClickedNo == 7) {//�v���r���[ && S_Tool[0].Nest[3] > DisplayArea2.Nest[1]
							//����H�H��activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
							//�{���̒l�ɖ߂�
							for (int i = 0; i < MsgBoxForm_Kosuu; i++) MsgBoxForm[i] = MsgBoxForm_Copy[i];
							//�v���r���[���[�h
							int MsgBoxCtrlNumber = 2;
							int AreaNumber = 2;
							//�v���r���[���[�h
							MessagePreviewMode(MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, MsgBoxForm, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, MsgBoxFormNumber,
								mondai.syoumon[s], SYOUMON_FIELDSIZE + 1, DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview_Kosuu, AreaNumber,
								FilePath_Mondai_h, FileTitle_Mondai, &mondai, EditorMode_p, &ExitModeFlag
							);
							if (ExitModeFlag) return 0;
							nukeru = 1;
						}
					}


					//����
					HMsgBoxHCtrl_S[s].Location[1] = S_Toolbar.Location[1] + S_Toolbar.Margin[1] + S_Toolbar.Height + S_Toolbar.Margin[3];

					ShowMsgBox(mondai.syoumon[s], &HMsgBoxHCtrl_S[s]); //����̏����o��
					ChangeImgAlign(mondai.syoumon[s], &HMsgBoxHCtrl_S[s]);//�摜�̃N���b�N�ŏ㉺�ʒu�̕ύX�i�N���b�N��̃^�O�ǎ�莞�ɋL�^�����^�O���̗v�f�ԍ����g�p�j

					if (HMsgBoxHCtrl_S[s].Tag[0].PositionP == 0) {//tag[0].PositionP��ActiveElement�̑�p
						//����ȊO�̃A�N�e�B�u���N���A����
						HMsgBoxHCtrl_D.Tag[0].PositionP = -1;
						HMsgBoxHCtrl_DS.Tag[0].PositionP = -1;
						if (activesyoumonH >= 0 && activesyoumonH != s) HMsgBoxHCtrl_S[activesyoumonH].Tag[0].PositionP = -1;//������A�N�e�B�u�ɂ���B�i����������N���b�N�����Ƃ��������j
						if (activesyoumonseikaiH >= 0) HMsgBoxHCtrl_SS[activesyoumonseikaiH].Tag[0].PositionP = -1;//���␳�����A�N�e�B�u�ɂ���B

						activesyoumonH = s;
						activesyoumonseikaiH = -1;
						//�p�b�h�Ŏg���郁�b�Z�[�W������ɂ���
						Message_p = mondai.syoumon[s]; MsgSizeE = sizeof(mondai.syoumon[s]); MsgBoxCtrl_p = &HMsgBoxHCtrl_S[s];
						MasterHeight = MsgBoxCtrl_Master[2].Height;


						//�p�b�h�̃{�^���G���A�ƃx�[�X�{�^���G���A���u�P�F�ҋ@��ԁv�ɂ���
						EditorPadArea[1].Active = 1; EditorPadArea[2].Active = 1;
					}
					//else MasterHeight = 0;

					/*Ctrl+Q�ŕ\������悤�ɉ��ǂ���////�}�[�W���̊O���̃��C���̊m�F�p�Ӂ�
					DrawBox(HMsgBoxHCtrl_S[s].Parent->Nest[0] + HMsgBoxHCtrl_S[s].Location[0], HMsgBoxHCtrl_S[s].Parent->Nest[1] + HMsgBoxHCtrl_S[s].Location[1],
					HMsgBoxHCtrl_S[s].Parent->Nest[0] + HMsgBoxHCtrl_S[s].Location[0] + HMsgBoxHCtrl_S[s].OuterWidth, HMsgBoxHCtrl_S[s].Parent->Nest[1] + HMsgBoxHCtrl_S[s].Location[1] + HMsgBoxHCtrl_S[s].OuterHeight, white, false);
					////�}�[�W���̊O���̃��C���̊m�F�p��*/



					//�����␳���c�[���o�[�G���A
					static struct AREACONTROL SS_Toolbar = { 0 };
					SS_Toolbar.ParentArea_p = &SyoumonArea;
					SS_Toolbar.Location[1] = HMsgBoxHCtrl_S[s].Location[1] + HMsgBoxHCtrl_S[s].OuterHeight+5;//
					SS_Toolbar.Width = 953;
					SS_Toolbar.Height = 24;//(D_Tool[s].Padding[1] = 3) + (D_Tool[s].Padding[3] = 3) = 6
					SS_Toolbar.BackTransparency = 80;
					SS_Toolbar.BackColor = GetColor(255, 255, 255);//204, 204, 204
					SS_Toolbar.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
					//�����␳���c�[���{�^��
					const int SS_ToolKosuu = 1;
					static struct BUTTONCONTROL SS_Tool[SS_ToolKosuu] = { 0 };
					strcpy(SS_Tool[0].String, "�ڍוҏW");
					if (SS_Tool[0].WaitingImg == -1) {
						SetCurrentDirectory(AppDir);
						SS_Tool[0].WaitingImg = D_Tool[0].WaitingImg;
						SS_Tool[0].CursorImg = D_Tool[0].CursorImg;
						SS_Tool[0].PushedImg = D_Tool[0].PushedImg;
					}

					for (int i = 0; i < SS_ToolKosuu; i++) {
						SS_Tool[i].ParentArea_p = &SS_Toolbar;
						if (i == 0) SS_Tool[i].Location[0] = 100;//
						else SS_Tool[i].Location[0] = -111111;
						SS_Tool[i].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
						SS_Tool[i].ButtonForm_p = &Mondai_ToolForm;

					}

					ShowArea(&SS_Toolbar, 1);
					DrawFormatStringInArea(5, 5, &SS_Toolbar, black, "���␳��%d:", s + 1);//���o���̕\��
					int SS_Tool_PushType = 0; int SS_Tool_Prev = -2; int SS_Tool_Next = -2;
					if (ShowButton(SS_Tool, SS_ToolKosuu, &ClickedNo, SS_Tool_PushType, SS_Tool_Prev, SS_Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
					// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
						if (ClickedNo == 0) {
							//�{���̒l�ɖ߂�
							for (int i = 0; i < MsgBoxForm_Kosuu; i++) MsgBoxForm[i] = MsgBoxForm_Copy[i];
							//�v���r���[���[�h
							int MsgBoxCtrlNumber = 3;
							int AreaNumber = 3;
							//�v���r���[���[�h
							MessagePreviewMode(MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, MsgBoxForm, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, MsgBoxFormNumber,
								mondai.syoumon[s], SYOUMON_FIELDSIZE + 1, DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview_Kosuu, AreaNumber,
								FilePath_Mondai_h, FileTitle_Mondai, &mondai, EditorMode_p, &ExitModeFlag
							);
							if (ExitModeFlag) return 0;
							nukeru = 1;
						}
					}
					//���␳��
					HMsgBoxHCtrl_SS[s].Location[1] = SS_Toolbar.Location[1] + SS_Toolbar.Margin[1] + SS_Toolbar.Height + SS_Toolbar.Margin[3];


					ShowMsgBox(mondai.syoumonseikai[s], &HMsgBoxHCtrl_SS[s]);//���␳���̏����o��
					ChangeImgAlign(mondai.syoumonseikai[s], &HMsgBoxHCtrl_SS[s]);//�摜�̃N���b�N�ŏ㉺�ʒu�̕ύX�i�N���b�N��̃^�O�ǎ�莞�ɋL�^�����^�O���̗v�f�ԍ����g�p�j

					if (HMsgBoxHCtrl_SS[s].Tag[0].PositionP == 0) {//Tag[0].PositionP��ActiveElement�̑�p
						//���␳���ȊO�̃A�N�e�B�u���N���A����
						HMsgBoxHCtrl_D.Tag[0].PositionP = -1;
						HMsgBoxHCtrl_DS.Tag[0].PositionP = -1;
						if (activesyoumonH >= 0) HMsgBoxHCtrl_S[activesyoumonH].Tag[0].PositionP = -1;//������A�N�e�B�u�ɂ���B
						if (activesyoumonseikaiH >= 0 && activesyoumonseikaiH != s) HMsgBoxHCtrl_SS[activesyoumonseikaiH].Tag[0].PositionP = -1;//���␳�����A�N�e�B�u�ɂ���B�i�������␳�����N���b�N�����Ƃ��������j
						activesyoumonH = -1;
						activesyoumonseikaiH = s;
						//�p�b�h�Ŏg���郁�b�Z�[�W�����␳���ɂ���
						Message_p = mondai.syoumonseikai[s]; MsgSizeE = sizeof(mondai.syoumonseikai[s]); MsgBoxCtrl_p = &HMsgBoxHCtrl_SS[s];
						MasterHeight = MsgBoxCtrl_Master[3].Height;

						//�p�b�h�̃{�^���G���A�ƃx�[�X�{�^���G���A���u�P�F�ҋ@��ԁv�ɂ���
						EditorPadArea[1].Active = 1; EditorPadArea[2].Active = 1;
					}
					//else MasterHeight = 0;

					/////////////////////////
					if (copyno == s) {//�R�s�[���̃}�[�N��\���i�R�s�[�����Ƃ��낪�킩��悤�Ɂj
						const int Speed = 70;//�_�ł̑����i�P��������̓_�ŉ񐔁j//�_�Ŏ�����3600 / Speed
						if (0 <= frameH % (3600 / Speed) && frameH % (3600 / Speed) < (1800 / Speed)) {
							//�����̈�̎擾
							RECT DrawAreaBuff;
							GetDrawArea(&DrawAreaBuff);
							int Range[4] = { DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom };//�����̈���擾���邽�߂̔z��
							//�������o���\�̈��ݒ�@�@���̕`��\�̈�� ���� �����X�^�[�摜�̗̈��
							Overlap(Range, SyoumonArea.Range);//
							//���`��\�̈�̊m��
							SetDrawArea(Range[0], Range[1], Range[2], Range[3]);
							//���R�s�[�}�[�N�̏����o��
							//����̃R�s�[�}�[�N
							int S_B[4] = { HMsgBoxHCtrl_S[s].Location[0] + HMsgBoxHCtrl_S[s].MsgBoxForm_p->Margin[0] + SyoumonArea.Nest[0],
								HMsgBoxHCtrl_S[s].Location[1] + HMsgBoxHCtrl_S[s].MsgBoxForm_p->Margin[1] + SyoumonArea.Nest[1],
								S_B[0] + HMsgBoxHCtrl_S[s].Width,
								S_B[1] + HMsgBoxHCtrl_S[s].Height
							};
							//���␳���̃R�s�[�}�[�N
							int SS_B[4] = { HMsgBoxHCtrl_SS[s].Location[0] + HMsgBoxHCtrl_SS[s].MsgBoxForm_p->Margin[0] + SyoumonArea.Nest[0],
								HMsgBoxHCtrl_SS[s].Location[1] + HMsgBoxHCtrl_SS[s].MsgBoxForm_p->Margin[1] + SyoumonArea.Nest[1],
								SS_B[0] + HMsgBoxHCtrl_SS[s].Width,
								SS_B[1] + HMsgBoxHCtrl_SS[s].Height
							};
							SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 20 / 100);//����
							DrawBox(S_B[0], S_B[1], S_B[2], S_B[3], gray30, true);//������͕��̘g�\��
							DrawBox(SS_B[0], SS_B[1], SS_B[2], SS_B[3], gray30, true);//������͕��̘g�\��
							SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂�
							//���`��\�̈�����ɖ߂�
							SetDrawArea(DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom);
						}
					}
				}//for�i����Ɋւ���N���b�N�����j�̏I��

				 //������ŏI�G���A
				static struct AREACONTROL SE_Toolbar = { 0 };
				SE_Toolbar.ParentArea_p = &SyoumonArea;
				SE_Toolbar.Location[0] = 0;
				SE_Toolbar.Location[1] = HMsgBoxHCtrl_SS[syoumonsuu - 1].Location[1] + HMsgBoxHCtrl_SS[syoumonsuu - 1].OuterHeight+5;//

				SE_Toolbar.BorderThickness = 0;
				SE_Toolbar.Padding[0] = 0;
				SE_Toolbar.Padding[1] = 0;
				SE_Toolbar.Padding[2] = 0;
				SE_Toolbar.Padding[3] = 0;
				SE_Toolbar.Width = 953;
				SE_Toolbar.Height = 20;//(D_Tool[i].Padding[1] = 3) + (D_Tool[i].Padding[3] = 3) = 6
				SE_Toolbar.BackColor = NULL;//204, 204, 204
				SE_Toolbar.BorderColor = NULL;// = GetColor(102, 102, 102);
				SE_Toolbar.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
				//������ŏI�c�[���{�^���t�H�[��
				static struct BUTTONFORM SE_ToolForm = { 0 };
				SE_ToolForm.Margin[0] = 1; SE_ToolForm.Margin[1] = 0; SE_ToolForm.Margin[2] = 1; SE_ToolForm.Margin[3] = 0;//
				SE_ToolForm.BorderThickness = 0;
				SE_ToolForm.BorderColor = NULL;// GetColor(0, 102, 102);//255, 51, 51
				SE_ToolForm.WaitingColor = GetColor(128, 128, 128); //GetColor(204, 204, 204);
				SE_ToolForm.CursorColor = GetColor(255, 255, 204);
				SE_ToolForm.PushedColor = NULL;// GetColor(153, 153, 153);

				//������ŏI�c�[���{�^��
				const int SE_ToolKosuu = 2;
				static struct BUTTONCONTROL SE_Tool[SE_ToolKosuu] = { 0 };
				strcpy(SE_Tool[0].Title, "����ǉ�");
				strcpy(SE_Tool[1].Title, "����ǉ��\�t");
				for (int b = 0; b < SE_ToolKosuu; b++) {
					SE_Tool[b].ParentArea_p = &SE_Toolbar;
					SE_Tool[b].Location[0] = 0;//
					if (b > 0) SE_Tool[b].Location[0] = SE_Tool[b - 1].Location[0] + SE_ToolForm.Margin[0] + SE_Tool[b - 1].Width + SE_ToolForm.Margin[2];
					SE_Tool[b].Location[1] = 0;
					SE_Tool[b].Padding[0] = 6; SE_Tool[b].Padding[1] = 3; SE_Tool[b].Padding[2] = 6; SE_Tool[b].Padding[3] = 3;//
					SE_Tool[b].Width = SE_Tool[b].Width = GetDrawStringWidth(SE_Tool[b].Title, strlen(SE_Tool[b].Title)) + SE_Tool[b].Padding[0] + SE_Tool[b].Padding[2] + SE_ToolForm.BorderThickness * 2;
					SE_Tool[b].Height = 24;
					SE_Tool[b].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
					SE_Tool[b].ButtonForm_p = &SE_ToolForm;
					////////
				}
				ShowArea(&SE_Toolbar, 1);
				int SE_Tool_PushType = 0; int SE_Tool_Prev = -2; int SE_Tool_Next = -2;
				if (ShowButton(SE_Tool, SE_ToolKosuu, &ClickedNo, SE_Tool_PushType, SE_Tool_Prev, SE_Tool_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
					//����ǉ�
					if (ClickedNo == 0) {
						activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
						strcpy(mondai.syoumon[syoumonsuu], "<p></p>");
						strcpy(mondai.syoumonseikai[syoumonsuu], "<math></math>");
						//���b�Z�[�W����̏�Ԃ������o���i�^�O��ǂ݂Ƃ�j
						HMsgBoxHCtrl_S[syoumonsuu].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
						HMsgBoxHCtrl_SS[syoumonsuu].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
						syoumonsuu++;
					}
					//����ǉ��\�t
					else if (ClickedNo == 1) {
						if (mondai.syoumon[SYOUMON_MAX][0] != '\0') {

							activereset(&Message_p, &HMsgBoxHCtrl_D, &HMsgBoxHCtrl_DS, HMsgBoxHCtrl_S, HMsgBoxHCtrl_SS, &activesyoumonH, &activesyoumonseikaiH);//�A�N�e�B�u�ȍ��ڂ̓��͊m��C��Ԃ̃��Z�b�g�C���ځC����C���␳���̃A�N�e�B�u�̃��Z�b�g
							//�\��t������
							strcpy(mondai.syoumon[syoumonsuu], mondai.syoumon[SYOUMON_MAX]);
							strcpy(mondai.syoumonseikai[syoumonsuu], mondai.syoumonseikai[SYOUMON_MAX]);
							//�\��t������Ԃ������o���i�^�O��ǂ݂Ƃ�j
							HMsgBoxHCtrl_S[syoumonsuu].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							HMsgBoxHCtrl_SS[syoumonsuu].Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
							syoumonsuu++;
						}
					}
				}

			}
			//////�X�e�[�^�X�o�[�̕\��
			ShowArea(&Statusbar, 1);
			StatusShow(Statusbar.Nest[0], Statusbar.Nest[1], MsgBoxCtrl_p, MasterHeight, FilePath_Mondai_h);

			//////////���t�@�C����������Ȃ珈�����Ȃ������̏�[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��////�N������C�A�v���͕����Ƀt�@�C���̂ݕ����Ƃ��B


			////////�i�S�j�v���_�E�����j���[�̏���////////////////////////////


			if (List0.Active == 1) {//�t�@�C���֘A�̃v���_�E�����X�g�̏���
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[0].Location[0] + ToolAForm.Margin[0],
					ToolA[0].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[0].Width,
					box[1] + ToolA[0].Height
				};
				if (ToolA[0].ParentArea_p != NULL) {
					box[0] += ToolA[0].ParentArea_p->Nest[0];
					box[1] += ToolA[0].ParentArea_p->Nest[1];
					box[2] += ToolA[0].ParentArea_p->Nest[0];
					box[3] += ToolA[0].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List0.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[0].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[0].Padding[1], black, ToolA[0].Title); //�����̕\��
				//���X�g����
				ShowList(&List0);
				////�V�K�쐬//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�iNULL�j�C�t�@�C���^�C�g���i����j�C�G�f�B�^�[���[�h�i����}�}�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				int r = 0;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						char GetDir[MAX_PATH];
						//�_�C�A���O����f�B���N�g���̑I��
						if (LocalDir[0] == '\0') {
							strcpy(LocalDir, AppDir);
							strcat(LocalDir, "\\OriginalFile\\MondaiData");
						}
						if (GetOpenDirectoryName(LocalDir, GetDir, MAX_PATH)) {
							strcpy(FilePath_Mondai_h, GetDir);//) strcpy(FileTitle_Mondai, "����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
							strcat(FilePath_Mondai_h, "\\����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
							//�i�g���q�Ȃ��Ȃ̂Œ��ӁB�f�B���N�g�����Ɂu����.txt�v������΂�����J���Ă��܂����߁j

							//�f�B���N�g���̒�����Monster�Ƃ����f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCMonster���̊����̃t�@�C���͏����Ȃ��B
							SetCurrentDirectory(GetDir);
							CreateDirectory("Monster", NULL);
							CreateDirectory("Img", NULL);
							CreateDirectory("Sound", NULL);
						}
						char DirectoryNow1[MAX_PATH];
						GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p
						for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
						return 0;//���ҏW���[�h���甲����
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�@�C�����J���i���t�@�C���j
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O����t�@�C�������擾
						if (LocalDir[0] == '\0') {
							strcpy(LocalDir, AppDir);
							strcat(LocalDir, "\\OriginalFile\\MondaiData");
						}
						char filepath[MAX_PATH]; char filetitle[MAX_PATH];
						if (GetOpenFileNameACK(LocalDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I�����̃J�����g�f�B���N�g���͖��t�@�C��������f�B���N�g���B�u�`\\OriginalFile\\MondaiData�v�Ƃ͌���Ȃ��̂Œ��ӁB
						//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
							//�J�����t�@�C���̃��[�h�𒲂ׂ�
							ClearDrawScreen();
							switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
							case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
								strcpy(FilePath_Mondai_h, filepath);//�t�@�C���p�X�̊m��
								//if (*EditorMode_p != 1) LocalDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
								for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
								return 0;//���ҏW���[�h���甲����
							case -1:
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
								WaitKey(); break;
							default://�����icase -2�j�j
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
								WaitKey();
							}
						}
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷

				////�㏑���ۑ��i���t�@�C���j
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//���b�Z�[�W�̕ۑ�
						OverwriteMondai(FilePath_Mondai_h, FileTitle_Mondai, MAX_PATH, MAX_PATH, &mondai);//�㏑���ۑ��i�܂��͖��O��t���ĕۑ��j
						//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_Mondai);//�t�@�C������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
						//���b�Z�[�W�{�b�N�X�R���g���[���ƃ��b�Z�[�W�{�b�N�X�t�H�[���̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxFormNumber);
						SaveMsgBoxForm(".\\MsgBoxForm.txt", MsgBoxForm_Copy, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
						//�������X�^�[�̂h�c���̕��בւ�
						char charbuff[MAX_PATH] = { 0 }; //�摜�t�@�C��
						int intbuff;
						struct Monster MinsterBuff;
						for (int i = 0; i < Monster_Kosuu; i++) {
							for (int j = Monster_Kosuu - 1; j > i; j--) {
								if (Monster[j - 1].Column[0] > Monster[j].Column[0] && Monster[j].Column[0] != 0) {

									MinsterBuff = Monster[j];
									Monster[j] = Monster[j - 1];
									Monster[j - 1] = MinsterBuff;

									strcpy(charbuff, MonsterImg_Path[j]);//�摜�p�X�̕��בւ�
									strcpy(MonsterImg_Path[j], MonsterImg_Path[j - 1]);
									strcpy(MonsterImg_Path[j - 1], charbuff);

									intbuff = MonsterImgWidth[j];
									MonsterImgWidth[j] = MonsterImgWidth[j - 1];
									MonsterImgWidth[j - 1] = intbuff;

									intbuff = MonsterImgHeight[j];
									MonsterImgHeight[j] = MonsterImgHeight[j - 1];
									MonsterImgHeight[j - 1] = intbuff;
								}
							}
						}
						//�������X�^�[�t�@�C���̕ۑ�
						SetCurrentDirectory(LocalDir);

						//char FilePath_Monster[MAX_PATH];//�����X�^�[�t�@�C���p�X���擾����ϐ�
						//strcpy(FilePath_Monster, LocalDir);//
						//if (LocalDir[0] != '\0') strcat(FilePath_Monster, "\\Monster\\monstertable.csv");//���f�B���N�g�����J���Ȃ�p�X���J���ɂȂ�
						////�����X�^�[�̃Z�[�u�i�t�@�C���p�X���J���Ȃ炷���ɔ����邩�牽���N����Ȃ��j
						SaveMonster(".\\Monster\\monstertable.csv", Monster, Monster_Kosuu, MaxMonsterID, ColumnTitle, Column_Kosuu, MonsterImg_Path);	//////////
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				//���O��t���ĕۑ�
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SaveAsNewMondai(FilePath_Mondai_h, FileTitle_Mondai, MAX_PATH, MAX_PATH, &mondai); //���O��t���ĕۑ�
						//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_Mondai);//�t�@�C������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
						//���b�Z�[�W�{�b�N�X�R���g���[���ƃ��b�Z�[�W�{�b�N�X�t�H�[���̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxFormNumber);
						SaveMsgBoxForm(".\\MsgBoxForm.txt", MsgBoxForm_Copy, MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�
						//�������X�^�[�̂h�c���̕��בւ�
						char charbuff[MAX_PATH] = { 0 }; //�摜�t�@�C��
						int intbuff;
						struct Monster MinsterBuff;
						for (int i = 0; i < Monster_Kosuu; i++) {
							for (int j = Monster_Kosuu - 1; j > i; j--) {
								if (Monster[j - 1].Column[0] > Monster[j].Column[0] && Monster[j].Column[0] != 0) {

									MinsterBuff = Monster[j];
									Monster[j] = Monster[j - 1];
									Monster[j - 1] = MinsterBuff;

									strcpy(charbuff, MonsterImg_Path[j]);//�摜�p�X�̕��בւ�
									strcpy(MonsterImg_Path[j], MonsterImg_Path[j - 1]);
									strcpy(MonsterImg_Path[j - 1], charbuff);

									intbuff = MonsterImgWidth[j];
									MonsterImgWidth[j] = MonsterImgWidth[j - 1];
									MonsterImgWidth[j - 1] = intbuff;

									intbuff = MonsterImgHeight[j];
									MonsterImgHeight[j] = MonsterImgHeight[j - 1];
									MonsterImgHeight[j - 1] = intbuff;
								}
							}
						}
						//�������X�^�[�t�@�C���̕ۑ�
						SetCurrentDirectory(LocalDir);

						//char FilePath_Monster[MAX_PATH];//�����X�^�[�t�@�C���p�X���擾����ϐ�
						//strcpy(FilePath_Monster, LocalDir);//
						//if (LocalDir[0] != '\0') strcat(FilePath_Monster, "\\Monster\\monstertable.csv");//���f�B���N�g�����J���Ȃ�p�X���J���ɂȂ�
						////�����X�^�[�̃Z�[�u�i�t�@�C���p�X���J���Ȃ炷���ɔ����邩�牽���N����Ȃ��j
						SaveMonster(".\\Monster\\monstertable.csv", Monster, Monster_Kosuu, MaxMonsterID, ColumnTitle, Column_Kosuu, MonsterImg_Path);	//////////
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////////�����X�^�[�ҏW
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						char FilePath_Monster[MAX_PATH];//�����X�^�[�t�@�C���p�X���擾����ϐ�
						strcpy(FilePath_Monster, LocalDir);//
						if (LocalDir[0] != '\0') strcat(FilePath_Monster, "\\Monster\\monstertable.csv");//���f�B���N�g�����J���Ȃ�p�X���J���ɂȂ�
						ClearDrawScreen();
						if (!EditMonster(FilePath_Monster, Monster, &Monster_Kosuu, &MaxMonsterID, ColumnTitle, &Column_Kosuu, MonsterImg_Path, DisplayArea.BackImg)) {
							
							//�����X�^�[�ҏW���[�h
							if (Monster_Kosuu > TableMax) tablesuu = TableMax;//
							else tablesuu = Monster_Kosuu;

							SetCurrentDirectory(AppDir);//0720
							strcpy(Monster[Monster_Kosuu].Name, "�Y���Ȃ�");
							Monster[Monster_Kosuu].Img = LoadGraph(".\\System\\EditMondai\\notappricable.png");
							strcpy(Monster[Monster_Kosuu + 1].Name, "���ݒ�");
							Monster[Monster_Kosuu + 1].Img = LoadGraph(".\\System\\EditMondai\\notset.png");

							//�������X�^�[�ԍ��̊m��
							for (int i = 0; i < Monster_Kosuu; i++) {//�����X�^�[�i���o�[�i�����X�^�[�̗v�f�ԍ��j�̊m��
								if (mondai.monsterID == 0) {//ID���J���̂Ƃ��C�u���ݒ�v�ƂȂ�B
									MonsterNum = Monster_Kosuu + 1; break;
								}
								else if (mondai.monsterID == Monster[i].Column[0]) {
									MonsterNum = i; break;
								}
								else if (i == Monster_Kosuu - 1) {
									MonsterNum = Monster_Kosuu;  break;//�Ō�܂Ń`�F�b�N���Ă���v����ID���Ȃ��Ƃ��C�u�Y���Ȃ��v�ƂȂ�B
								}
							}

							//�������X�^�[�摜�T�C�Y�̎擾
							for (int i = 0; i < Monster_Kosuu + 2; i++) {//�����X�^�[�i���o�[�i�����X�^�[�̗v�f�ԍ��j�̊m��
								GetGraphSize(Monster[i].Img, &MonsterImgWidth[i], &MonsterImgHeight[i]); //�����X�^�[�̉摜�̏c���T�C�Y���擾����monsterwide�Cmonsterhight�ɏ����o��
							}
							//�^�C�g���o�[�̃e�L�X�g�̍X�V
							strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
							strcat(Titlebar_text, FileTitle_Mondai);//�f�B���N�g������A��
							SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
						}
					}


				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				///////�z�[���ɖ߂�//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//LocalDir[0] = '\0';//�Ⴄ���[�h�ɐi�񂾂��ƁC���̃��[�h�ɖ߂��Ă����Ƃ��ɁC�t�H���g�E�^�O�ݒ���ă��[�h���������߁B
						*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
						for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
						return 0;
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////////�A�v���P�[�V�����̏I��
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight
					&& List0Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						DxLib_End(); return 0;
					}
				}
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				if (List0Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����@�ireturn�Ŋ֐����甲������̈ȊO�́C���ׂĂ����Ń��X�g���甲����j
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List0.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea.Active = 1; SyoumonArea.Active = 1;//
					MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
				}

			}
			//////�X�^�C���̃v���_�E�����X�g
			if (List1.Active == 1) {//�v���_�E�����X�g
				ShowList(&List1);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[1].Location[0] + ToolAForm.Margin[0],
					ToolA[1].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[1].Width,
					box[1] + ToolA[1].Height
				};
				if (ToolA[1].ParentArea_p != NULL) {
					box[0] += ToolA[1].ParentArea_p->Nest[0];
					box[1] += ToolA[1].ParentArea_p->Nest[1];
					box[2] += ToolA[1].ParentArea_p->Nest[0];
					box[3] += ToolA[1].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List1.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[1].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[1].Padding[1], black, ToolA[1].Title); //�����̕\��

				 ////�X�^�C���̕ۑ�0802����
				int  r = 0;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//char dir[MAX_PATH]; strcpy(dir, LocalDir); strcat(dir, "\\FontTagSettings.txt");
						//SaveFontTagSetPath(dir);//�X�^�C���Z�b�g�̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontSet, SourcePath, FileTitle_Font, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�摜�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�摜�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontImgSet, SourcePath, FileTitle_FontImg, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontImgSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�^�O�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ń^�O�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_TagSet, SourcePath, FileTitle_Tag, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_TagSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�W���C�p�b�h�̊��蓖��
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight
					&& List1Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�ŃW���C�p�b�h�̊��蓖�Ẵt�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_Joypad, SourcePath, FileTitle_Joypad, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_TagSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				if (List1Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List1.Nest[1] += List1.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List1.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea.Active = 1; SyoumonArea.Active = 1;
					MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
				}
			}
			//////�ݒ�̃v���_�E�����X�g
			if (List2.Active == 1) {//�v���_�E�����X�g190802
				ShowList(&List2);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[2].Location[0] + ToolAForm.Margin[0],
					ToolA[2].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[2].Width,
					box[1] + ToolA[2].Height
				};
				if (ToolA[2].ParentArea_p != NULL) {
					box[0] += ToolA[2].ParentArea_p->Nest[0];
					box[1] += ToolA[2].ParentArea_p->Nest[1];
					box[2] += ToolA[2].ParentArea_p->Nest[0];
					box[3] += ToolA[2].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List2.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[2].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[2].Padding[1], black, ToolA[2].Title); //�����̕\��

				////�w�i�̕ύX
				int  r = 0;
				if (List2.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List2.Nest[0] + List2.RowWidth && List2.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List2.Nest[1] + List2.RowHeight
					&& List2Row[r].Active > 0) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List2.Nest[0], List2.Nest[1], List2.Nest[0] + List2.RowWidth, List2.Nest[1] + List2.RowHeight, List2.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SettingEditorBackFlag = 1;
					}
				}
				if (List2Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * 30 / 100);//��A�N�e�B�u�̂Ƃ��͔w�i�𓧂���//aa0/
				DrawFormatString(List2.Nest[0] + List2.BorderThickness + List2.RowPadding[0], List2.Nest[1] + List2.BorderThickness + List2.RowPadding[1], black, List2Row[r].Title); //�����̕\��
				if (List2Row[r].Active == 0) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�m�[�u�����h�ɖ߂��i��P������DX_BLENDMODE_NOBLEND�̂Ƃ���Q�����͈Ӗ��������Ȃ��j//aa0/
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List1.Active = -1; List2.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea.Active = 1; SyoumonArea.Active = 1;
					MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
				}
			}

			//�w�i�̕ύX
			if (SettingEditorBackFlag > 0) {
				//���X�g����I�������u��
				if (SettingEditorBackFlag == 1) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 0;DisplayArea2.Active = 0;
					MonsterFlag = 0;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��

				}
				//�w�i�̕ύX�t�H�[���̕\���@���X�g����I�����āi�ۑ��͖߂��Ă�������DisplayArea_Preview_FilePath�ɏ����ʂ��Ă���j
				//DisplayArea�͂P�CBorderColorRGB�͂S�CBackColorRGB�͂S�CBackImgPath�͂S���邪�C���ׂĂP�iDisplayArea_Kosuu�j�����\������
				int Value = SettingEditorBack(&DisplayArea, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Kosuu, &SettingEditorBackFlag);
				//�w�i�̕ύX�t�H�[�����ŕۑ���������
				if (Value == 1) {
					//�v���r���[�p�̃f�B�X�v���C�G���A�ɏ����ʂ�
					DisplayArea_Preview[0].BackColor = DisplayArea.BackColor;//���b�Z�[�W���̓G���A
					DisplayArea_Preview[0].BackImg = DisplayArea.BackImg;//���b�Z�[�W���̓G���A

					//�ݒ�p�t�@�C���̕ۑ�
					SetCurrentDirectory(AppDir);
					SaveEditorSettings(DisplayArea_Preview_FilePath, DisplayArea_Preview, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview_Kosuu);//�X�^�C���Z�b�g�̕ۑ�

					//�e�G���A�̃A�N�e�B�u��
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 1;DisplayArea2.Active = 1;
					MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
				}
				//�w�i�̕ύX�t�H�[�����ŃL�����Z����������
				else if (Value == -1) {
					//�e�G���A�̃A�N�e�B�u��
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 1; DisplayArea2.Active = 1;
					MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
				}
			}

			if (MonsterFlag == 2) {//�����X�^�[�e�[�u���N���b�N��̏���
				//////�����X�^�[�e�[�u��
				static int wakuseniro = GetColor(185, 205, 229);
				DrawBox(PulldownList_Monster[0], PulldownList_Monster[1], PulldownList_Monster[2], PulldownList_Monster[3], wakuseniro, true);//�v���_�E�����X�g�g
				DrawString(PulldownList_Monster[0] + 5, PulldownList_Monster[1] + 5, PulldownList_Monster_text, black);//�v���_�E�����X�g�̃^�C�g��
				DrawBox(PulldownList_Monster[0] + 5, PulldownList_Monster[1] + 10 + SystemFontSize, PulldownList_Monster[2] - 5, PulldownList_Monster[3] - 5, black, true);//�v���_�E�����X�g

				if (popupRot < 0) popupRot = 0;//�}�E�X�̉�]�ʂ�0��菬�����Ȃ�Ȃ��悤��
				else if (popupRot > Monster_Kosuu - tablesuu) popupRot = Monster_Kosuu - tablesuu;//�}�E�X�̉�]�ʂ��傫���Ȃ�߂��Ȃ��悤��

				for (int i = 0; i < tablesuu; i++) {
					if (MonsterTable_pd[i].tablewaku[0] < ActiveMath::MouseX && ActiveMath::MouseX < MonsterTable_pd[i].tablewaku[2] && MonsterTable_pd[i].tablewaku[1] < ActiveMath::MouseY && ActiveMath::MouseY < MonsterTable_pd[i].tablewaku[3]) {//�����X�^�[���͈͓̔��̂Ƃ�
						DrawBox(MonsterTable_pd[i].tablewaku[0], MonsterTable_pd[i].tablewaku[1], MonsterTable_pd[i].tablewaku[2], MonsterTable_pd[i].tablewaku[3], cursorColorbuff, true);//�|�b�v�A�b�v�J�[�\���̕\��
						if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
							MonsterNum = popupRot + i;//�����X�^�[�ԍ��̎擾
							mondai.monsterID = Monster[MonsterNum].Column[0];//���ҏW��ʂ�monsterID������������@MonsterH[popupRot + i][0]
							Toolbar[0].Active = 1; Toolbar[1].Active = 1; EditorPadArea[0].Active = 1; DisplayArea.Active = 1; SyoumonArea.Active = 1;//�L��
							MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��

							break;
						}
					}

					////////�g�̕⊮�ƑS�̘g
					DrawBox(MonsterTable_pd[i].column[0][2], MonsterTable_pd[i].column[0][1], MonsterTable_pd[i].tablewaku[2], MonsterTable_pd[i].name[3], gray, false);//�g�̕⊮
					DrawBox(MonsterTable_pd[i].tablewaku[0], MonsterTable_pd[i].tablewaku[1], MonsterTable_pd[i].tablewaku[2], MonsterTable_pd[i].tablewaku[3], gray, false);//�S�̘g
					DrawBox(MonsterTable_pd[i].tablewaku[0] + 1, MonsterTable_pd[i].tablewaku[1] + 1, MonsterTable_pd[i].tablewaku[2] - 1, MonsterTable_pd[i].tablewaku[3] - 1, gray, false);//�S�̘g

					DrawBox(MonsterTable_pd[i].yousono[0], MonsterTable_pd[i].yousono[1], MonsterTable_pd[i].yousono[2], MonsterTable_pd[i].yousono[3], gray, false);//�����X�^�[�v�f�ԍ��̘g
					DrawFormatString(MonsterTable_pd[i].yousono[0] + 4, MonsterTable_pd[i].yousono[1] + 4, white, "%d", popupRot + i);//�e�[�u���v�f�ԍ��̕\��

					//�����̈�̎擾
					RECT DrawAreaBuff;
					GetDrawArea(&DrawAreaBuff);
					int Range[4] = { DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom };//�����̈���擾���邽�߂̔z��

					//���`��\�̈�̎w��ƌ��̕`��\�̈�̎擾
					Overlap(Range, MonsterTable_pd[i].gazou);//
					//���`��\�̈�̊m��
					SetDrawArea(Range[0], Range[1], Range[2], Range[3]);
					//�������X�^�[�摜
					int centerX = MonsterTable_pd[i].gazou[0] + 44; int centerY = MonsterTable_pd[i].gazou[1] + 44;////�����X�^�[�摜�̘g�̒��S
					int Rate = 3;//������2/3�̑傫���ŕ\���i���S���獶�E��1/3�̈ʒu�j
					if (Monster[popupRot + i].Img != -1) DrawExtendGraph(centerX - MonsterImgWidth[popupRot + i] / Rate, centerY - MonsterImgHeight[popupRot + i] / Rate, centerX + MonsterImgWidth[popupRot + i] / Rate, centerY + MonsterImgHeight[popupRot + i] / Rate, Monster[popupRot + i].Img, true);  //�����X�^�[�摜��`�悷��
					else DrawExtendGraph(centerX - Undefined_MonsterImgWidth / Rate, centerY - Undefined_MonsterImgHeight / Rate, centerX + Undefined_MonsterImgWidth / Rate, centerY + Undefined_MonsterImgHeight / Rate, Undefined_MonsterImg, true);
					//���`��\�̈�����ɖ߂�
					SetDrawArea(DrawAreaBuff.left, DrawAreaBuff.top, DrawAreaBuff.right, DrawAreaBuff.bottom);
					//////
					DrawBox(MonsterTable_pd[i].gazou[0], MonsterTable_pd[i].gazou[1], MonsterTable_pd[i].gazou[2], MonsterTable_pd[i].gazou[3], gray, false);//�����X�^�[�摜�̘g


					int titlecolor2 = GetColor(0, 51, 102);
					int titlecolor = GetColor(0, 102, 153);

					DrawBox(MonsterTable_pd[i].columntitle[0][0], MonsterTable_pd[i].columntitle[0][1], MonsterTable_pd[i].column[0][2], MonsterTable_pd[i].column[0][3], gray, false);////�J�����O�i�h�c)�^�C�g���ƃJ�����O�i�h�c�j�̘A���g
					DrawBox(MonsterTable_pd[i].columntitle[0][0] + 1, MonsterTable_pd[i].columntitle[0][1] + 1, MonsterTable_pd[i].columntitle[0][2] - 1, MonsterTable_pd[i].columntitle[0][3] - 1, titlecolor2, true);//�J�����O�i�h�c�j�^�C�g���̔w�i
					DrawString(MonsterTable_pd[i].columntitle[0][0] + 4, MonsterTable_pd[i].columntitle[0][1] + 4, ColumnTitle[0], white);//�J�����O�i�h�c�j�^�C�g���̕\��
					DrawFormatString(MonsterTable_pd[i].column[0][0] + 4, MonsterTable_pd[i].column[0][1] + 4, white, "%d", Monster[popupRot + i].Column[0]);//�h�c�̕\��

					DrawBox(MonsterTable_pd[i].nametitle[0], MonsterTable_pd[i].nametitle[1], MonsterTable_pd[i].name[2], MonsterTable_pd[i].name[3], gray, false);//�����X�^�[���^�C�g���ƃ����X�^�[���̘A���g
					DrawBox(MonsterTable_pd[i].nametitle[0] + 1, MonsterTable_pd[i].nametitle[1] + 1, MonsterTable_pd[i].nametitle[2] - 1, MonsterTable_pd[i].nametitle[3] - 1, titlecolor2, true);//�����X�^�[���^�C�g���̔w�i
					DrawString(MonsterTable_pd[i].nametitle[0] + 4, MonsterTable_pd[i].nametitle[1] + 4, "���O", white);//�����X�^�[���^�C�g���̕\��
					if (Monster[popupRot + i].Name[0] != '\0') DrawFormatString(MonsterTable_pd[i].name[0] + 4, MonsterTable_pd[i].name[1] + 4, white, "%s", Monster[popupRot + i].Name);//�����X�^�[���̕\��
					else DrawFormatString(MonsterTable_pd[i].name[0] + 4, MonsterTable_pd[i].name[1] + 4, white, "%s", Undefined_MonsterName);//�����X�^�[���̕\��
					for (int k = 1; k < 15; k++) {
						DrawBox(MonsterTable_pd[i].columntitle[k][0], MonsterTable_pd[i].columntitle[k][1], MonsterTable_pd[i].column[k][2], MonsterTable_pd[i].column[k][3], gray, false);//�J�����i���Ԗځj�^�C�g���ƃJ�����i���Ԗځj�̘A���g
						if (k < Column_Kosuu) {
							DrawBox(MonsterTable_pd[i].columntitle[k][0] + 1, MonsterTable_pd[i].columntitle[k][1] + 1, MonsterTable_pd[i].columntitle[k][2] - 1, MonsterTable_pd[i].columntitle[k][3] - 1, titlecolor, true);//�J�����i���Ԗځj�^�C�g���̔w�i
							DrawFormatString(MonsterTable_pd[i].columntitle[k][0] + 4, MonsterTable_pd[i].columntitle[k][1] + 4, white, "%s", ColumnTitle[k]);//�J�����i���Ԗځj�^�C�g���̕\��
							DrawFormatString(MonsterTable_pd[i].column[k][0] + 4, MonsterTable_pd[i].column[k][1] + 4, white, "%d", Monster[popupRot + i].Column[k]);//�J�����i���Ԗځj�̕\��
						}
					}
				}//for���̏I��

				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					if (ActiveMath::MouseX < PulldownList_Monster[0] || PulldownList_Monster[2] < ActiveMath::MouseX || ActiveMath::MouseY < PulldownList_Monster[1] || PulldownList_Monster[3] < ActiveMath::MouseY) {//�|�b�v�A�b�v�͈̔͊O�̂Ƃ��@�@�������Ȃ��Ŕ�����
						Toolbar[0].Active = 1; Toolbar[1].Active = 1; DisplayArea.Active = 1; SyoumonArea.Active = 1;//�L��
						for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;
						MonsterFlag = 1;//�|�P�F�����@�O�F�ҋ@�@�P�F�I���@���@//�|�P�F��\���@�O�F�����@�P�F�ҋ@�@�Q�F�I��
					}
				}
			}

			//���J�[�\���I�[�o�[
			static const int BackColor = GetColor(230, 255, 230);//R:255 G:255 B:204
			int LocationX = ActiveMath::MouseX; int LocationY = ActiveMath::MouseY + 20;
			Math_CursorOver(LocationX, LocationY, 2, black, BackColor, NULL);//Math_ButtonTitleShow(const int LocationX, const int LocationY, const int Padding, const int StringColor, const int BackColor, const int Type)
			//���}���`�K�C�h
			MultiGuide();//�S���b�Z�[�W�ŋ��L���邽�߁CMathWritingP���ɓ���Ȃ����ƁB
			//���T���v���̐��������i�R���g���[���{R�j
			if (ActiveMath::Key[KEY_INPUT_R] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {
				for (int i = 0; i < ToolBKosuu; i++) ToolB[i].Active = 1;
				for (int i = 0; i < List0RowKosuu; i++) List0Row[i].Active = 1;
				for (int i = 0; i < List1RowKosuu; i++) List1Row[i].Active = 1;
				for (int i = 0; i < List2RowKosuu; i++) List2Row[i].Active = 1;
			}

		}//���ҏWfor���[�v�̏I��

	}//while
	return 0;
}
//////////�����ҏW���[�h�̏I��聪//////////////////�����ҏW���[�h�̏I��聪//////////�����ҏW���[�h�̏I��聪///////////�����ҏW���[�h�̏I��聪/////////


/////�����b�Z�[�W�ҏW���[�h��////////////�����b�Z�[�W�ҏW���[�h��////////////�����b�Z�[�W�ҏW���[�h��////////////�����b�Z�[�W�ҏW���[�h��//////
int EditMessage(int* EditorMode_p, char* FilePath_Message_h) {
	int InputHandleMath = MakeKeyInput(100, TRUE, FALSE, FALSE);//�V�����L�[���̓f�[�^�̍쐬  ESC�L�[�ɂ��L�����Z���@�\�̗L��TRUE�@���p�����݂̂̓���FALSE�@���l�����݂̂̓���FALSE
	//////////�c�[���{�^��////////////
	//���c�[���o�[
	static struct AREACONTROL Toolbar[2] = { 0 };
	for (int AreaN = 0; AreaN < 2; AreaN++) {
		for (int i = 0; i < 4; i++) Toolbar[AreaN].Padding[i] = 1;
		Toolbar[AreaN].BackColor = GetColor(51, 102, 153);//204, 204, 204 R:51 G:102 B:153//102, 153, 204
		Toolbar[AreaN].Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
		/////////
	}
	Toolbar[1].Location[0] = -111111;
	Toolbar[0].Width = 208;
	Toolbar[0].Height = 28;
	////
	Toolbar[1].Width = 416;
	Toolbar[1].Height = 28;


	//���{�^��A�t�H�[��
	static struct BUTTONFORM ToolAForm = { 0 };
	for (int i = 0; i < 4; i++) ToolAForm.Margin[i] = 1;
	ToolAForm.CursorColor = GetColor(255, 255, 204);

	//���c�[���{�^��A
	const int ToolAKosuu = 3;//�{�^���z��̗v�f���i���ۂ��傫���l�ł��悢�j
	static struct BUTTONCONTROL ToolA[ToolAKosuu] = { 0 };
	strcpy(ToolA[0].Title, "�t�@�C��");
	strcpy(ToolA[1].Title, "�J�X�^�}�C�Y");
	strcpy(ToolA[2].Title, "�ݒ�");
	for (int BtnN = 0; BtnN < ToolAKosuu; BtnN++) {
		ToolA[BtnN].ParentArea_p = &Toolbar[0];
		if (BtnN > 0) ToolA[BtnN].Location[0] = -111111;
		for (int i = 0; i < 4; i++) ToolA[BtnN].Padding[i] = 5;
		ToolA[BtnN].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolA[BtnN].ButtonForm_p = &ToolAForm;
	}


	//���{�^��B�t�H�[��
	static struct BUTTONFORM ToolBForm = { 0 };
	for (int i = 0; i < 4; i++) ToolBForm.Margin[i] = 1;
	ToolBForm.CursorColor = GetColor(255, 255, 204);

	//���c�[���{�^��B
	SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	const int ToolBKosuu = 5;//�{�^���z��̗v�f��
	static struct BUTTONCONTROL ToolB[ToolBKosuu] = { 0 };
	strcpy(ToolB[0].String, "�z�[����ʂɖ߂�");
	if (ToolB[0].WaitingImg == -1) {
		ToolB[0].WaitingImg = LoadGraph(".\\System\\Fixed\\home24.png");
		ToolB[0].CursorImg = LoadGraph(".\\System\\Fixed\\home24b.png");
		ToolB[0].PushedImg = ToolB[0].CursorImg;
	}
	strcpy(ToolB[1].String, "�V�K�쐬");
	if (ToolB[1].WaitingImg == -1) {
		ToolB[1].WaitingImg = LoadGraph(".\\System\\Fixed\\new24.png");
		ToolB[1].CursorImg = LoadGraph(".\\System\\Fixed\\new24b.png");
		ToolB[1].PushedImg = ToolB[1].CursorImg;
	}
	strcpy(ToolB[2].String, "�t�@�C�����J��");
	if (ToolB[2].WaitingImg == -1) {
		ToolB[2].WaitingImg = LoadGraph(".\\System\\Fixed\\open24.png");
		ToolB[2].CursorImg = LoadGraph(".\\System\\Fixed\\open24b.png");
		ToolB[2].PushedImg = ToolB[2].CursorImg;
	}
	strcpy(ToolB[3].String, "�㏑���ۑ�");
	if (ToolB[3].WaitingImg == -1) {
		ToolB[3].WaitingImg = LoadGraph(".\\System\\Fixed\\save24.png");
		ToolB[3].CursorImg = LoadGraph(".\\System\\Fixed\\save24b.png");
		ToolB[3].PushedImg = ToolB[3].CursorImg;
	}
	strcpy(ToolB[4].String, "�ڍוҏW");
	if (ToolB[4].WaitingImg == -1) {
		ToolB[4].WaitingImg = LoadGraph(".\\System\\Fixed\\edit24.png");
		ToolB[4].CursorImg = LoadGraph(".\\System\\Fixed\\edit24b.png");
		ToolB[4].PushedImg = ToolB[4].CursorImg;
	}
	for (int BtnN = 0; BtnN < ToolBKosuu; BtnN++) {
		ToolB[BtnN].ParentArea_p = &Toolbar[1];
		if (BtnN > 0)  ToolB[BtnN].Location[0] = -111111;
		ToolB[BtnN].Active = 1;//�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�ҋ@��ԁ@�Q�F�I�����
		ToolB[BtnN].ButtonForm_p = &ToolBForm;
	}

	//�G�f�B�^�[�̐ݒ�i�v���r���[�p�f�B�X�v���C�G���A�j�̎擾
	int SettingEditorBackFlag = 0;
	char BackImgPath[MAX_PATH] = { 0 };//�w�i�摜�t�@�C�����擾�p
	int BorderColorRGB[3] = { 0 };//�w�i�F��RGB�擾�p
	int BackColorRGB[3] = { 0 };//�w�i�F��RGB�擾�p
	const int DisplayArea_Preview_Kosuu = 1;
	static struct AREACONTROL DisplayArea_Preview = { 0 };
	SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	char DisplayArea_Preview_FilePath[MAX_PATH] = ".\\System\\BackImg\\BackImgPath_Msg.txt";
	LoadEditorSettings(DisplayArea_Preview_FilePath, &BorderColorRGB, &BackColorRGB, &BackImgPath, &DisplayArea_Preview, DisplayArea_Preview_Kosuu);
	//�G�f�B�^�[�̐ݒ�i�v���r���[�p�f�B�X�v���C�G���A�j�̎擾
	//int SettingEditorBackFlag = 0;
	//const int DisplayArea_Preview_Kosuu = 4;
	//char BackImgPath[DisplayArea_Preview_Kosuu][MAX_PATH] = { 0 };//�w�i�摜�t�@�C�����擾�p
	//int BorderColorRGB[DisplayArea_Preview_Kosuu][3] = { 0 };//�w�i�F��RGB�擾�p
	//int BackColorRGB[DisplayArea_Preview_Kosuu][3] = { 0 };//�w�i�F��RGB�擾�p
	//static struct AREACONTROL DisplayArea_Preview[DisplayArea_Preview_Kosuu] = { 0 };
	//SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
	//char DisplayArea_Preview_FilePath[MAX_PATH] = ".\\System\\BackImg\\BackImgPath_Mondai.txt";
	//LoadEditorSettings(DisplayArea_Preview_FilePath, BorderColorRGB, BackColorRGB, BackImgPath, DisplayArea_Preview, DisplayArea_Preview_Kosuu);


	//���f�B�X�v���C�G���A
	int DisplayArea_Kosuu = 1;
	static struct AREACONTROL DisplayArea = { 0 };
	DisplayArea.Location[1] = 84;//28+56
	DisplayArea.Padding[0] = 14;// + systemfontsize
	DisplayArea.Padding[1] = 14;
	DisplayArea.Padding[2] = 0;//�����X�^�[�e�[�u���̕���953������Ƃ肠����1000-19-953��28�Ƃ���B�Z���^�[�ɂȂ�悤�ɂ��ƂłȂ����B�ق��̃{�b�N�X���B
	DisplayArea.Padding[3] = 0;
	DisplayArea.Width = WindowWidth;
	DisplayArea.Height = 690;//WindowHeight(798)-28-56-24
	DisplayArea.Active = 1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	DisplayArea.BackColor = DisplayArea_Preview.BackColor;
	DisplayArea.BackImg = DisplayArea_Preview.BackImg;



	//���X�e�[�^�X�o�[
	static struct AREACONTROL Statusbar = { 0 };
	Statusbar.Width = WindowWidth;
	Statusbar.Height = 24;//������v���̂���Location[1]����ɏ�����
	Statusbar.Location[1] = WindowHeight - Statusbar.Height;
	for (int i = 0; i < 4; i++) Statusbar.Padding[i] = 5;
	Statusbar.BackColor = GetColor(240, 240, 240);


	//�v���_�E�����X�g
	int ListStrLen;//�^�C�g���̕�����
	int ListStrWidth;//�^�C�g���̕�
	const int list_BackColor = GetColor(204, 204, 153);
	const int list_BorderColor = GetColor(153, 153, 102);
	const int List_CursorColor = GetColor(255, 255, 204);
	//���t�@�C���̃v���_�E�����X�g
	const int List0RowKosuu = 6;
	ListStrWidth = GetDrawStringWidth("�A�v���P�[�V�����̏I��", strlen("�A�v���P�[�V�����̏I��"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List0 = { 0 };
	List0.ParentButton_p = &ToolA[0];//�t�@�C���{�^��
	List0.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List0.Padding[i] = 2;
	List0.BackColor = list_BackColor;
	List0.BorderColor = list_BorderColor;
	List0.CursorColor = List_CursorColor;

	List0.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List0.RowKosuu = List0RowKosuu;
	for (int i = 0; i < 4; i++) List0.RowPadding[i] = 5;
	List0.RowWidth = ListStrWidth + List0.RowPadding[0] + List0.RowPadding[2];
	List0.RowHeight = SystemFontSize + List0.RowPadding[1] + List0.RowPadding[3];
	/////////
	List0.Width = List0.RowWidth + List0.Padding[0] + List0.Padding[2] + List0.BorderThickness * 2;
	List0.Height = List0.RowHeight * List0.RowKosuu + List0.Padding[1] + List0.Padding[3] + List0.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List0Row[List0RowKosuu] = { 0 };
	for (int i = 0; i < List0RowKosuu; i++) List0Row[i].List_p = &List0;
	strcpy(List0Row[0].Title, "�V�K�쐬");
	strcpy(List0Row[1].Title, "�t�@�C�����J��");
	strcpy(List0Row[2].Title, "�㏑���ۑ�");
	strcpy(List0Row[3].Title, "���O��t���ĕۑ�");
	strcpy(List0Row[4].Title, "�z�[���ɖ߂�");
	strcpy(List0Row[5].Title, "�A�v���P�[�V�����̏I��");

	//���X�^�C���̃v���_�E�����X�g
	const int List1RowKosuu = 4;
	ListStrWidth = GetDrawStringWidth("�t�H���g�摜�Z�b�g�̕ύX", strlen("�t�H���g�摜�Z�b�g�̕ύX"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List1 = { 0 };
	List1.ParentButton_p = &ToolA[1];//�t�@�C���{�^��
	List1.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List1.Padding[i] = 2;
	List1.BackColor = list_BackColor;
	List1.BorderColor = list_BorderColor;
	List1.CursorColor = List_CursorColor;
	List1.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List1.RowKosuu = List1RowKosuu;
	for (int i = 0; i < 4; i++) List1.RowPadding[i] = 5;
	List1.RowWidth = ListStrWidth + List1.RowPadding[0] + List1.RowPadding[2];
	List1.RowHeight = SystemFontSize + List1.RowPadding[1] + List1.RowPadding[3];
	/////////
	List1.Width = List1.RowWidth + List1.Padding[0] + List1.Padding[2] + List1.BorderThickness * 2;
	List1.Height = List1.RowHeight * List1.RowKosuu + List1.Padding[1] + List1.Padding[3] + List1.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List1Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List1RowKosuu; i++) List1Row[i].List_p = &List1;
	strcpy(List1Row[0].Title, "�X�^�C���̕ۑ�");
	strcpy(List1Row[1].Title, "�t�H���g�Z�b�g�̕ύX");
	strcpy(List1Row[2].Title, "�t�H���g�摜�Z�b�g�̕ύX");
	strcpy(List1Row[3].Title, "�^�O�Z�b�g�̕ύX");


	//���ݒ�̃v���_�E�����X�g
	const int List2RowKosuu = 1;
	ListStrWidth = GetDrawStringWidth("�w�i�̕ύX", strlen("�w�i�̕ύX"));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
	static struct LISTCONTROL List2 = { 0 };
	List2.ParentButton_p = &ToolA[2];//�ݒ�{�^��
	List2.BorderThickness = 1;
	for (int i = 0; i < 4; i++) List2.Padding[i] = 2;
	List2.BackColor = list_BackColor;
	List2.BorderColor = list_BorderColor;
	List2.CursorColor = List_CursorColor;
	List2.Active = -1; //�|�P�F��\���@�O�F�g�p�s��ԁ@�P�F�g�p�\���
	/////////
	List2.RowKosuu = List2RowKosuu;
	for (int i = 0; i < 4; i++) List2.RowPadding[i] = 5;
	List2.RowWidth = ListStrWidth + List2.RowPadding[0] + List2.RowPadding[2];
	List2.RowHeight = SystemFontSize + List2.RowPadding[1] + List2.RowPadding[3];
	/////////
	List2.Width = List2.RowWidth + List2.Padding[0] + List2.Padding[2] + List2.BorderThickness * 2;
	List2.Height = List2.RowHeight * List2.RowKosuu + List2.Padding[1] + List2.Padding[3] + List2.BorderThickness * 2;
	/////////
	static struct LISTROWCTRL List2Row[List1RowKosuu] = { 0 };
	for (int i = 0; i < List2RowKosuu; i++) List2Row[i].List_p = &List2;//������
	strcpy(List2Row[0].Title, "�w�i�̕ύX");



	//���[�h�̃e�L�X�g
	char AppMode_text[MAX_PATH];
	strcpy(AppMode_text, ApplicationTitle);//�A�v���P�[�V����������
	strcat(AppMode_text, " - ���b�Z�[�W�ҏW���[�h - ");//���[�h����A��
	//�^�C�g���o�[
	char Titlebar_text[MAX_PATH];
	strcpy(Titlebar_text, AppMode_text);
	//
	char FileTitle_Message[MAX_PATH] = { 0 };//���b�Z�[�W�t�@�C�������擾����ϐ�
	if (FilePath_Message_h[0] != '\0') GetTitleFromPath(FileTitle_Message, FilePath_Message_h);//���ꃍ�[�h�̑O�Ɉړ��ł���H�H�H616�@//�t�@�C���p�X����t�@�C�������擾�i�t�@�C���p�X��"�V�K"�̂Ƃ��̓t�@�C������"�V�K"�j
	//�t�@�C���p�X�֘A//
	static char FilePath_Settings[MAX_PATH];//�X�^�C�����̐ݒ�t�@�C���̃t���p�X�i���t�@�C�����J���s�x�C���t�@�C���Ɠ����f�B���N�g�����́@"�ݒ�.txt"�@�t�@�C���̃t���p�X�ƂȂ�j
	static char FilePath_MsgBoxForm[MAX_PATH];//���b�Z�[�W�{�b�N�X�R���g���[���t�@�C���̃t���p�X�i���t�@�C�����J���s�x�C���t�@�C���Ɠ����f�B���N�g�����́@"MsgBoxForm.txt"�@�t�@�C���̃t���p�X�ƂȂ�j
	static char FilePath_MsgBoxCtrl[MAX_PATH];//���b�Z�[�W�v���p�e�B�t�@�C���̃t���p�X�i���t�@�C�����J���s�x�C���t�@�C���Ɠ����f�B���N�g�����́@"Propaty.txt"�@�t�@�C���̃t���p�X�ƂȂ�j
											  //�^�C�g���\��
	////
	//static char MessageDir[MAX_PATH] = { 0 };
	//static char FilePath_keep[MAX_PATH] = { 0 };//���ꂢ��H�H�H616
	////////���̓{�b�N�X�̒�`�Ə�������////
/*
	if (FilePath_Message_h[0] == '\0' && strcmp(FileTitle_Message, "����") != 0 && filepathMessage_buff[0] != '\0') {//�g���Ă���̂��H�H�H
		strcpy(FilePath_Message_h, filepathMessage_buff);//�t�@�C�������Ȃ���΁i�t�@�C������"����"�̂Ƃ��͏����j�O��J���Ă����t�@�C�������w��i�O��̋L�^���Ȃ��Ƃ��̓J���ƂȂ�)
	}
*/
//���b�Z�[�W
	const int MsgCharMax = 2000;//�ǂݍ��݉\�ȕ�����
	char Message[MsgCharMax + 1] = { 0 }; //���b�Z�[�W������
	//���b�Z�[�W�t�H�[��
	const int MsgBoxForm_Kosuu = 1;//�t�H�[���̌���if (FilePath_Message_h[0] != '\0')���ł��悢���R���g���[���Ɠ����ꏊ�̂ق����킩��₷���̂ŃR�R�ɂ���
	static struct MsgBoxForm MsgBoxForm;//�}�X�^�[�i���b�Z�[�W�̕\���ɂ͂�����g�p����B���b�Z�[�W�̕ҏW�ł͒l���ꎞ�I�ɏ���������j
	static struct MsgBoxForm MsgBoxForm_Copy;//�R�s�[�i���b�Z�[�W�̕ҏW�ňꎞ�I�ɏ����������l���C���ɖ߂����߂Ɏg�p�B�܂����b�Z�[�W�t�H�[���̕ۑ��ɂ͂�����g�p�B�j
	static struct MsgBoxForm_RGB_SoundPath MsgBoxForm_RGB_SoundPath;//�F�C�����̓n���h���ł͂Ȃ��C�F��RGB�l�C������LocalDir����̑��΃p�X���L�^�i�l�̕ύX��ۑ��Ŏg�p�j


	//���b�Z�[�W�{�b�N�X�R���g���[��
	const int MsgBoxCtrl_Kosuu = 1;
	static struct MsgBoxCtrl MsgBoxCtrl_Master;//���b�Z�[�W�{�b�N�X�i�}�X�^�[�j//���t�g�o�[�iHeight�j�C���b�Z�[�W�v���r���[�i�|�C���^�[�A�h���X�j�C�p�b�h�v���r���[�i�|�C���^�[�A�h���X�j�Ŏg�p
	static struct MsgBoxCtrl MsgBoxCtrl_Msg;//���b�Z�[�W�{�b�N�X
	int MsgBoxCtrlNumber = 0;
	int MsgBoxFormNumber = 0;

	//���b�Z�[�W�C�ݒ�C�w�i�摜�C���b�Z�[�W�v���p�e�B�̃��[�h
	if (FilePath_Message_h[0] != '\0') {
		//���b�Z�[�W�̃��[�h
		char buff2[256];
		strcpy(buff2, LocalDir);
		int LoadMsgError;
		switch (LoadMsgError = LoadMsg(FilePath_Message_h, Message, MsgCharMax + 1, 1)) {//�P�FLocalDir�CMsgDir�̎擾
		//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W���T�C�Y�I�[�o�[���Ă��܂��B", black, gray60);
		}
		if (LoadMsgError < -1) {//-1�F���b�Z�[�W�̃t�@�C�������݂��Ȃ��̂̓G���[�Ƃ��Ȃ��i�V�K�쐬�̂Ƃ��t�@�C�������݂��Ȃ��ɊY�����邽�߁j
			WaitKey();
			FilePath_Message_h[0] = '\0';//�t�@�C���p�X������
			ClearDrawScreen();
			return -1;
		}
		char buff1[256];
		strcpy(buff1, LocalDir);
		//���b�Z�[�W�Z�b�g�iMsgBoxForm�CMsgBoxCtrl�CFontTagSettings�j�̃��[�h�iMessageDir���擾�j
		int Error;
		switch (Error = LoadMsgSet(LocalDir, &MsgBoxForm, MsgBoxForm_Kosuu, &MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, 1, 1)) {
		//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		case -3: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//�@�i�Ȃ��j
		//case -11: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -12: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		case -13: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60);//�@�i�Ȃ��j
		//case -21: FontTagSettingsCreateFlag = 0;//�X�^�C���ۑ����ɐV�K�쐬���Ȃ�//ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;
		//case -22: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		//case -31: JoypadSettingsCreateFlag = 0;//ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�W���C�p�b�h�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;
		//case -32: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�W���C�p�b�h�ݒ�̃p�����[�^������܂���B", black, gray60);//�@�i�Ȃ��j
		}
		if (Error < -1 && Error != -11 && Error != -21 && Error != -31) {//-1, -11, -21�C31�̓G���[�Ƃ��Ȃ�
			DxLib::WaitKey();
			FilePath_Message_h[0] = '\0';//�t�@�C���p�X������
			ClearDrawScreen();
			return -1;
		}


		//���I�����̓����X�^�[�f�B���N�g��

		//MsgBoxForm_RGB_SoundPath_Master�̎擾�i�F�̒l�C���̃p�X�j
		char Path[MAX_PATH];
		strcpy(Path, LocalDir);
		strcat(Path, "\\MsgBoxForm.txt");
		LoadMsgBoxForm_RGB_SoundPath(Path, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);//�t�@�[���̃Z�[�u�����邽�߁CLoadMsgBoxForm_RGB_SoundPath�����[�h���Ă����K�v������B
		//char DirectoryNow1[MAX_PATH];
		//GetCurrentDirectory(MAX_PATH, DirectoryNow1);//�`�F�b�N�p



		InputHandleMath = MakeKeyInput(100, TRUE, FALSE, FALSE);//�V�����L�[���̓f�[�^�̍쐬  ESC�L�[�ɂ��L�����Z���@�\�̗L��TRUE�@���p�����݂̂̓���FALSE�@���l�����݂̂̓���FALSE
		SetActiveKeyInput(InputHandleMath);// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
		//�^�C�g���o�[�̃e�L�X�g�Ƀt�@�C������s��
		strcat(Titlebar_text, FileTitle_Message);
	}
	SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������



	//�v���r���[���[�hint Area_Kosuu = 1;  
	int ExitModeFlag = 0;
	int AreaNumber = 0;
	MessagePreviewMode(&MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, &MsgBoxForm, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, &MsgBoxFormNumber,
		Message, MsgCharMax + 1, DisplayArea_Preview_FilePath, &DisplayArea_Preview, &BorderColorRGB, &BackColorRGB, &BackImgPath, DisplayArea_Preview_Kosuu, AreaNumber,
		FilePath_Message_h, FileTitle_Message, NULL, EditorMode_p, &ExitModeFlag//���ҏW���[�ǂ̂Ƃ���NULL�̂Ƃ��낪, &mondai�i����͖��t�@�C����ۑ�����̂ɕK�v������j
	);
	return 0;

	while (!ProcessMessage()) {
		//���p�b�h�}�l�[�W���[�ƃC���f�b�N�X�{�^���̃A�N�e�B�u�̃��Z�b�g
		struct PadManager PadManager;
		//�p�b�h�̏������i�I�����Ă���C���f�b�N�X�{�^����0�ԂɃ��Z�b�g�j
		for (int i = 0; i < EditorIndexKosuu; i++) EditorIndex[i].Active = 1;
		EditorIndex[0].Active = 2;

		//�����b�Z�[�W�{�b�N�X�t�H�[���̒l��ҏW�p�ɏ���������
		//�{���̒l�����������i�t�H�[���̓��[�h�������̂��g�����߁C����������O�Ɍ��̒l���R�s�[���Ă����j
		MsgBoxForm_Copy = MsgBoxForm;
		//�ҏW�p�ɂ���������
		int Value1 = 4;//�S�F��~ MsgBoxForm[i].Option % 10;
		int Value2 = 4;//�S�F�{�b�N�X���� MsgBoxForm[i].Option % 100 / 10;
		int Value3 = 4;//���P���ڂ�4�����炱���͉��ł��悢 MsgBoxForm[i].Option % 1000 / 100;
		int Value4 = MsgBoxForm.Option % 10000 / 1000;//������4���ڂ������������Ȃ��B�O�F�܂�Ԃ��Ȃ��@�P�F�܂�Ԃ����� �@�Q�F�܂�Ԃ�����i�킩���j
		int Value5 = 3;//�R�F�\�����̃��b�Z�[�W���[�iHeight�̒l���ω��j MsgBoxForm[i].Option % 100000 / 10000;

		if (FilePath_Message_h[0] != '\0') {
			MsgBoxForm.Option = Value5 * 10000 + Value4 * 1000 + Value3 * 100 + Value2 * 10 + Value1 * 1;
			MsgBoxForm.OutputSpeed = -2;//�����̏o�̓X�s�[�h�i�v���X�F�P�b�Ԃɐi�ޕ������@�}�C�i�X�F�N���b�N�ɔ�������j
							 //�܂�i�v���X�F�p�J�p�J����B�J�[�\���Ȃ��B�@0�F�p�J�p�J�Ȃ��B�J�[�\���Ȃ��B�@-1�F�p�J�p�J�Ȃ��B�N���b�N�ォ��J�[�\������B�@-2�ȉ��F�p�J�p�J�Ȃ��B������J�[�\������B�j
			for (int c = 0; c < 4; c++) MsgBoxForm.Margin[c] = 0;

			//���ҏW�p�̃��b�Z�[�W�{�b�N�X���쐬�ictrl�̓R�s�[�������̂��g�p����@��胂�[�h�ŏ���𑽐��������������߁j�i�R�s�[���Ă��|�C���^�[�Ń����N���Ă���t�H�[���͕ς��Ȃ��j
			MsgBoxCtrl_Msg = MsgBoxCtrl_Master;//�}�X�^�[�͖�肪�ς�����Ƃ���v���r���[�ŁC�N���A�[���邽�߂Ɏg�p
			MsgBoxCtrl_Msg.Location[0] = 0;
			MsgBoxCtrl_Msg.Location[1] = 0;
			MsgBoxCtrl_Msg.ParentArea_p = &DisplayArea;//�G���A�̎w��
			MsgBoxCtrl_Msg.OuterWidth = MsgBoxCtrl_Msg.Width + MsgBoxCtrl_Msg.MsgBoxForm_p->Margin[0] + MsgBoxCtrl_Msg.MsgBoxForm_p->Margin[2];
			MsgBoxCtrl_Msg.OuterHeight = MsgBoxCtrl_Msg.Height + MsgBoxCtrl_Msg.MsgBoxForm_p->Margin[1] + MsgBoxCtrl_Msg.MsgBoxForm_p->Margin[3];
		}

		int nukeru = 0;
		//////////�����b�Z�[�W�ҏW���C�����[�v�̎n�܂聫////////////////////�����b�Z�[�W�ҏW���C�����[�v�̎n�܂聫///////////////////�����b�Z�[�W�ҏW���C�����[�v�̎n�܂聫///////////////////�����b�Z�[�W�ҏW���C�����[�v�̎n�܂聫/////////
		for (int frameH = 0;!nukeru && !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !MathgpUpdateMouse() && !MathgpUpdateKey(); frameH++) {//�}�E�X�E�L�[�{�[�h
			//������������ҋ@
			SleepToFitFPS(FPS);
			//�c�[���o�[
			ShowArea(Toolbar, 2);
			////�@�c�[���o�[A�@////
			static int ClickedNoA = -1;//�����ꂽ�{�^���ԍ�
			//���c�[���i�v���_�E�����X�g�j
			int ToolA_PushType = 0; int ToolA_Prev = -2; int ToolA_Next = -2;
			if (ShowButton(ToolA, ToolAKosuu, &ClickedNoA, ToolA_PushType, ToolA_Prev, ToolA_Next) == 1) {//�N���b�N�����������P�̂Ƃ�
				//�t�@�C���܂��̓X�^�C�����������u��
				if (ClickedNoA >= 0) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 0;
					//���X�g���J���Ă��Ȃ���Ԃł̃N���b�N��
					//Mouse[MOUSE_INPUT_LEFT] = 2�́C�v���_�E�����X�g�������ɏ����Ă��܂��̂�h���i���X�g�͈̔͊O�N���b�N�ɊY�����邽�߁j�i�O�͂��߁B���̃��[�v�łɂ܂��P�ɂȂ��Ă��܂��j
					if (ClickedNoA == 0 && List0.Active != 1) { List0.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 1 && List1.Active != 1) { List1.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
					else if (ClickedNoA == 2 && List2.Active != 1) { List2.Active = 1; ActiveMath::Mouse[MOUSE_INPUT_LEFT] = 2; }
				}

			}

			//�t�@�C���܂��̓X�^�C��������������
			else if (List0.Active == 1 || List1.Active == 1 || List2.Active == 1) {//�v���_�E����ԂŃJ�[�\�����w���{�^��������Ƃ�
				for (int i = 0; i < ToolAKosuu; i++) {
					if (ToolA[i].Active == 3) {//�J�[�\�����w���Ă���Ƃ���PulldownFlag������������
						if (i == 0) { List0.Active = 1; List1.Active = -1; List2.Active = -1; }
						else if (i == 1) { List0.Active = -1; List1.Active = 1; List2.Active = -1; }
						else if (i == 2) { List0.Active = -1; List1.Active = -1; List2.Active = 1; }
						break;
					}
				}
			}
			////�@�c�[���o�[B�@////
			//���c�[���{�^��
			//AreaControlShow(&ToolbarB, 1);
			int ClickedNo = -1;//�����ꂽ�{�^���ԍ�

			int ToolB_PushType = 0; int ToolB_Prev = -2; int ToolB_Next = -2;
			if (ShowButton(ToolB, ToolBKosuu, &ClickedNo, ToolB_PushType, ToolB_Prev, ToolB_Next) == 1) {// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
			///////�z�[��//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				if (ClickedNo == 0) {
					*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
					return 0;
				}
				///////�V�K�쐬
				else if (ClickedNo == 1) {//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�iNULL�j�C�t�@�C���^�C�g���i����j�C�G�f�B�^�[���[�h�i����}�}�j�Ń��b�Z�[�W�ҏW���[�h���甲����
					char FirstDir[MAX_PATH];
					char GetDir[MAX_PATH];
					//�_�C�A���O����f�B���N�g���̑I��
					strcpy(FirstDir, AppDir);
					strcat(FirstDir, "\\OriginalFile\\MessageData");
					if (GetOpenDirectoryName(FirstDir, GetDir, MAX_PATH)) {
						strcpy(FilePath_Message_h, GetDir);//) strcpy(FileTitle_Mondai, "����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
						strcat(FilePath_Message_h, "\\����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
						//�i�g���q�Ȃ��Ȃ̂Œ��ӁB�f�B���N�g�����Ɂu����.txt�v������΂�����J���Ă��܂����߁j

						//�f�B���N�g���̒�����Monster�Ƃ����f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCMonster���̊����̃t�@�C���͏����Ȃ��B
						SetCurrentDirectory(GetDir);
						CreateDirectory("Img", NULL);
						CreateDirectory("Sound", NULL);
					}
					return 0;//���b�Z�[�W�ҏW���[�h���甲����
				}

				///////�t�@�C�����J��
				else if (ClickedNo == 2) {//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�i�擾�j�C�t�@�C���^�C�g���i�擾�j�C�G�f�B�^�[���[�h�ԍ��i�擾�j�Ń��b�Z�[�W�ҏW���[�h���甲����
					char FirstDir[MAX_PATH];
					//�_�C�A���O����t�@�C�������擾
					if (LocalDir[0] == '\0') {
						strcpy(FirstDir, AppDir);
						strcat(FirstDir, "\\OriginalFile\\MessageData");
					}
					else strcpy(FirstDir, LocalDir);
					char filepath[MAX_PATH]; char filetitle[MAX_PATH];
					if (GetOpenFileNameACM(FirstDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
					//���I�����̃J�����g�f�B���N�g���̓��b�Z�[�W�t�@�C��������f�B���N�g���B�u�`\\OriginalFile\\MessageData�v�Ƃ͌���Ȃ��̂Œ��ӁB
					//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
						//�J�����t�@�C���̃��[�h�𒲂ׂ�
						ClearDrawScreen();
						switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
						case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
							strcpy(FilePath_Message_h, filepath);//�t�@�C���p�X�̊m��
							return 0;//���ҏW���[�h���甲����
						case -1:
							ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
							DxLib::WaitKey(); break;
						default://�����icase -2�j�j
							ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
							DxLib::WaitKey();
						}

					}
				}
				///////�㏑���ۑ�
				else if (ClickedNo == 3) {
					OverwriteMessage(FilePath_Message_h, FileTitle_Message, MAX_PATH, MAX_PATH, Message, MsgBoxCtrl_Msg.Tag[0].Post);//�㏑���ۑ��i�܂��͖��O��t���ĕۑ��j;//tag[0].Post��TagKosuu�itagnomax�j�Ƃ��đ�p
					//���b�Z�[�W�{�b�N�X�R���g���[���ƃ��b�Z�[�W�{�b�N�X�t�H�[���̕ۑ�
					SetCurrentDirectory(LocalDir);
					SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", &MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, &MsgBoxFormNumber);
					SaveMsgBoxForm(".\\MsgBoxForm.txt", &MsgBoxForm_Copy, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);
					SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

					//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
					strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
					strcat(Titlebar_text, FileTitle_Message);//�t�@�C������A��
					SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
				}
				///////���b�Z�[�W�v���r���[
				else if (ClickedNo == 4) {
					//�{���̒l�ɖ߂�
					MsgBoxForm = MsgBoxForm_Copy;


					int Area_Kosuu = 0;  int AreaNumber = 0;

					//�v���r���[���[�h
					MessagePreviewMode(&MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, MsgBoxCtrlNumber, &MsgBoxForm, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu, &MsgBoxFormNumber,
						Message, MsgCharMax + 1, DisplayArea_Preview_FilePath, &DisplayArea_Preview, &BorderColorRGB, &BackColorRGB, &BackImgPath, Area_Kosuu, AreaNumber,
						FilePath_Message_h, FileTitle_Message, NULL, EditorMode_p, &ExitModeFlag//���ҏW���[�ǂ̂Ƃ���NULL�̂Ƃ��낪, &mondai�i����͖��t�@�C����ۑ�����̂ɕK�v������j
					);
					if (ExitModeFlag) return 0;
					DisplayArea.BackColor = DisplayArea_Preview.BackColor;
					DisplayArea.BackImg = DisplayArea_Preview.BackImg;

					nukeru = 1;
				}
			}
			////////////���̓p�b�h//////////
			int ShowMsgBoxFlag = 0;
			if (ShowPadM(Message, &MsgBoxCtrl_Msg, MsgCharMax + 1, &InputHandleMath, ShowMsgBoxFlag, EditorIndex, EditorIndexKosuu, EditorButton_ph, EditorButtonKosuu, EditorBaseButton, EditorBaseButtonKosuu, EditorPadArea, &PadManager) == 1) {
				if (PadManager.InputButton_p != NULL && PadManager.InputButton_p->ButtonType == 4) {

					char Dir[MAX_PATH] = { 0 };//�f�B���N�g�����w�肷�邽�߂̕ϐ�
					int FileType = 0;//�摜�t�@�C��
					//�f�B���N�g���̌���
					if (!strcmp(PadManager.InputButton_p->PutText, "#img_lm{") || !strcmp(PadManager.InputButton_p->PutText, "#img_le{")) {//
						strcpy(Dir, LocalDir); strcat(Dir, "\\Img");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Img�ƂȂ�
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#img_am{") || !strcmp(PadManager.InputButton_p->PutText, "#img_ae{")) {//
						strcpy(Dir, Dir_AppImg);
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#img_nm{") || !strcmp(PadManager.InputButton_p->PutText, "#img_ne{")) {//
						strcpy(Dir, MsgDir);
					}

					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_l{")) {//
						strcpy(Dir, LocalDir); strcat(Dir, "\\Sound");//�f�B���N�g���́C���b�Z�[�W�f�B���N�g��\\Sound�ƂȂ�
						FileType = 1;//�����t�@�C��
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_a{")) {//
						strcpy(Dir, Dir_AppSound);
						FileType = 1;//�����t�@�C��
					}
					else if (!strcmp(PadManager.InputButton_p->PutText, "#sound_n{")) {//
						strcpy(Dir, MsgDir);
						FileType = 1;//�����t�@�C��
					}
					//�f�B���N�g���̍쐬
					CreateDirectory(Dir, NULL);//Dir�̃f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCDir���̊����̃t�@�C���͏����Ȃ��B

					//�t�@�C���I���_�C�A���O
					char FilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
					char FileTitle[MAX_PATH];//�t�@�C�������擾����ϐ�
					if (*Dir != '\0' && GetImgFileName(Dir, FilePath, FileTitle, MAX_PATH, MAX_PATH, FileType)) {//�_�C�A���O�ɂ����t�@�C�����̎擾�i�J�����g�f�B���N�g�����I���摜�̃f�B���N�g���ɕς��̂Œ��Ӂj
						char SoutaiPath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
						//�t�@�C���擾�ɐ���������t�@�C�����R�s�[���āCDir����݂��R�s�[�t�@�C���̑��΃p�X�i�܂�����̓t�@�C�����j���擾
						//�R�s�[�����t�@�C���̃t�@�C���p�X���쐬
						char CopyFilePath[MAX_PATH] = { 0 };//�t�@�C���p�X���擾����ϐ�
						strcpy(CopyFilePath, Dir);
						strcat(CopyFilePath, "\\");
						strcat(CopyFilePath, FileTitle);
						if (strcmp(FilePath, CopyFilePath)) {
							char CopyFilePath2[MAX_PATH] = { 0 };
							strcpy(CopyFilePath2, CopyFilePath);
							//�t�@�C�����R�s�[
							for (int num = 1; num < 10; num++) {//�i1�`9�܂ł̓����t�@�C�����쐬�\�j
								if (CopyFile(FilePath, CopyFilePath2, TRUE)) break;
								strcpy(CopyFilePath2, CopyFilePath);
								int point = strlen(CopyFilePath2);
								while (CopyFilePath2[point] != '.') point--;
								char kakuchoshi[5] = { 0 };
								for (int i = 0; CopyFilePath2[point + i] != '\0'; i++) kakuchoshi[i] = CopyFilePath2[point + i];
								CopyFilePath2[point] = '(';
								CopyFilePath2[point + 1] = '\0';
								char number[100];
								_itoa(num + 1, number, 10);
								strcat(CopyFilePath2, number);
								strcat(CopyFilePath2, ")");
								strcat(CopyFilePath2, kakuchoshi);
							}
							//���΃p�X���擾  ��(9)�܂ő��݂��Ă���Ȃ�R�[�h�ɂ�(10)���������܂�邪�摜�͍쐬����Ȃ��B
							PathRelativePathTo(SoutaiPath, Dir, FILE_ATTRIBUTE_DIRECTORY, CopyFilePath2, FILE_ATTRIBUTE_ARCHIVE);
						}
						else strcpy(SoutaiPath, FileTitle);//MsgDir���̉摜��I�������ꍇ�͉摜���R�s�[�����CFileTitle�����΃p�X�ƂȂ�

						////////////////////////////////////////////////////////////////////////////////////
						//�}�����镶����̍쐬
						char PutText[150];
						strcpy(PutText, PadManager.InputButton_p->PutText);
						strcat(PutText, SoutaiPath);
						strcat(PutText, "}");

						int PutTextMojisuu = strlen(PutText);//�}�����镶�������J�E���g
						int MessageMojisuu = strlen(Message);//���b�Z�[�W�̕��������擾

						//��������
						if (MessageMojisuu + PutTextMojisuu < MsgCharMax + 1) {// return -1;//�T�C�Y�I�[�o�[���Ȃ��悤��
							int point = MsgBoxCtrl_Msg.Tag[0].PositionP;//tag[0].PositionP��*ActiveElement
							for (int i = MessageMojisuu; i >= point; i--) Message[i + PutTextMojisuu] = Message[i];//���������镶����̕��������ɂ��炷�B//�Ԃ�������
							for (int i = 0; i < PutTextMojisuu; i++) Message[point + i] = PutText[i]; //�A�N�e�B�u�ȗv�f�ȍ~�̔z��v�f�ɁC����������������� //�������}������i�A�N�e�B�u�ȗv�f����C���炵�ĊJ�����ʒu�܂Łj
							MsgBoxCtrl_Msg.Tag[0].PositionP += PutTextMojisuu;//tag[0].PositionP��*ActiveElement
							MsgBoxCtrl_Msg.Tag[0].TagSign = 1;//tag[0].TagSign��ActiveTagSign�@�l���P�̂Ƃ������^�O�Ȃǂ̏���ǂݍ���
						}

					}
				}
			}

			//�f�B�X�v���G���A
			ShowArea(&DisplayArea, 1);






			//////////���t�@�C����������Ȃ珈�����Ȃ������̏�[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��////�N������C�A�v���͕����Ƀt�@�C���̂ݕ����Ƃ��B
			//if (FileTitle_Message[0] != '\0'){//�����̏����ł������� || strcmp(FileTitle_Message, "����") == 0
			if (FilePath_Message_h[0] != '\0') {
				///////���b�Z�[�W�f�B�X�v���C�G���A

				int MsgBoxCtrl_Condition = ShowMsgBox(Message, &MsgBoxCtrl_Msg);
				ChangeImgAlign(Message, &MsgBoxCtrl_Msg);//�摜�̃N���b�N�ŏ㉺�ʒu�̕ύX�i�N���b�N��̃^�O�ǎ�莞�ɋL�^�����^�O���̗v�f�ԍ����g�p�j
				//���t�g�o�[�@�w�肳�ꂽ�R���g���[���̍����ɂ�鉺�[�̕\��
//				LeftbarShow(&MsgBoxCtrl_Msg, MsgBoxCtrl_Master.Height);

				const char MessageBuff[] = "<p>����<math>#frac(1;2#frac(1;2))</math>����</p>";
				int Width; int Height; int TagKosuu;
				static int ReturnValue = GetWidthForDrawMsg_S(MessageBuff, &Width, &Height, &TagKosuu);//���C�����C�^�O�̌����擾MessageS
				/////////////////////////GetWidthForDrawMsg_S
				const char MessageS[] = "<p>����<math>#frac(1;2#frac(1;2))</math>����</p>";
				int FontColorRGB[3] = { 100,500,50 };
				int FontColorHandle = GetColor(FontColorRGB[0], FontColorRGB[1], FontColorRGB[2]);
				const int TagHairetsuMax = 8;
				static struct Tag Tag[TagHairetsuMax + 1];//TagHairetsuMax + tag[0]�̕����v���X�P
				static char ParsedMsg[300] = { 0 };
				DrawMsg(0, 200, MessageS, FontColorRGB, FontColorHandle, &DisplayArea, TagHairetsuMax, Tag, ParsedMsg); //�P���o��

			}
			//////////���t�@�C����������Ȃ珈�����Ȃ������̏�[�i�t�@�C���p�X�͂Ȃ��Ă��t�@�C������"����"�ƂȂ��Ă���Ώ�������j��////�N������C�A�v���͕����Ƀt�@�C���̂ݕ����Ƃ��B

			//////�X�e�[�^�X�o�[
			ShowArea(&Statusbar, 1);
			StatusShow(Statusbar.Nest[0], Statusbar.Nest[1], &MsgBoxCtrl_Msg, MsgBoxCtrl_Master.Height, FilePath_Message_h);


			////////�i�S�j�v���_�E�����j���[�̏���////////////////////////////
			if (List0.Active == 1) {//�t�@�C���֘A�̃v���_�E�����X�g�̏���
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[0].Location[0] + ToolAForm.Margin[0],
					ToolA[0].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[0].Width,
					box[1] + ToolA[0].Height
				};
				if (ToolA[0].ParentArea_p != NULL) {
					box[0] += ToolA[0].ParentArea_p->Nest[0];
					box[1] += ToolA[0].ParentArea_p->Nest[1];
					box[2] += ToolA[0].ParentArea_p->Nest[0];
					box[3] += ToolA[0].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List0.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[0].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[0].Padding[1], black, ToolA[0].Title); //�����̕\��
				//���X�g����
				ShowList(&List0);
				////�V�K�쐬//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�iNULL�j�C�t�@�C���^�C�g���i����j�C�G�f�B�^�[���[�h�i����}�}�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				int r = 0;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {//�N���b�N�����Ƃ��̏���
						char FirstDir[MAX_PATH];
						char GetDir[MAX_PATH];
						//�_�C�A���O����f�B���N�g���̑I��
						strcpy(FirstDir, AppDir);
						strcat(FirstDir, ".\\OriginalFile\\MessageData");
						if (GetOpenDirectoryName(FirstDir, GetDir, MAX_PATH)) {
							strcpy(FilePath_Message_h, GetDir);//) strcpy(FileTitle_Mondai, "����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
							strcat(FilePath_Message_h, "\\����");//�f�B���N�g�����擾�ł�����t�@�C���^�C�g�����u����v�ɂ���B�L�����Z���̂Ƃ��͂��̂܂܁B
							//�i�g���q�Ȃ��Ȃ̂Œ��ӁB�f�B���N�g�����Ɂu����.txt�v������΂�����J���Ă��܂����߁j

							//�f�B���N�g���̒�����Monster�Ƃ����f�B���N�g�����Ȃ���΍쐬�B����΃G���[�ƂȂ邾���ŁCMonster���̊����̃t�@�C���͏����Ȃ��B
							SetCurrentDirectory(GetDir);
							CreateDirectory("Img", NULL);
							CreateDirectory("Sound", NULL);
						}
						for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
						return 0;//���b�Z�[�W�ҏW���[�h���甲����
					}
				}
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�@�C�����J���i���t�@�C���j//�A�N�e�B�u�ȃf�B���N�g���i�擾�j�C�t�@�C���p�X�i�擾�j�C�t�@�C���^�C�g���i�擾�j�C�G�f�B�^�[���[�h�ԍ��i�擾�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						char FirstDir[MAX_PATH];
						//�_�C�A���O����t�@�C�������擾
						if (LocalDir[0] == '\0') {
							strcpy(FirstDir, AppDir);
							strcat(FirstDir, "\\OriginalFile\\MessageData");
						}
						else strcpy(FirstDir, LocalDir);
						char filepath[MAX_PATH]; char filetitle[MAX_PATH];
						if (GetOpenFileNameACM(FirstDir, filepath, filetitle, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I�����̃J�����g�f�B���N�g���̓��b�Z�[�W�t�@�C��������f�B���N�g���B�u�`\\OriginalFile\\MessageData�v�Ƃ͌���Ȃ��̂Œ��ӁB
						//���L�����Z�������Ƃ��̓p�X�ƃ^�C�g���͕ς��Ȃ��B���̂Ƃ����΃p�X�̂܂܂Ȃ̂ŉ��L�̑��΃p�X�擾�̏����͂��Ȃ����ƁB
							//�J�����t�@�C���̃��[�h�𒲂ׂ�
							ClearDrawScreen();
							switch (int Value = EditorModeChecker(EditorMode_p, filepath)) {//�����F�O�@���s�F�O�ȊO�i-1�F�Y���t�@�C���Ȃ��@-2�F�ǂ̃��[�h�ɂ��Y�����Ȃ��j
							case 0://�������C���[�h�����ɖ��ҏW���[�h���甲���āC����Ȃ���
								strcpy(FilePath_Message_h, filepath);//�t�@�C���p�X�̊m��
								for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
								return 0;//���ҏW���[�h���甲����
							case -1:
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�@�C�������݂��܂���B", black, gray60);
								WaitKey(); break;
							default://�����icase -2�j�j
								ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�Y������G�f�B�^�[���[�h���Ȃ��C���̃t�@�C�����J�����Ƃ��ł��܂���B", black, gray60);
								WaitKey();
							}
						}
					}
				}
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷

				//�㏑���ۑ�
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						OverwriteMessage(FilePath_Message_h, FileTitle_Message, MAX_PATH, MAX_PATH, Message, MsgBoxCtrl_Msg.Tag[0].Post);//�㏑���ۑ��i�܂��͖��O��t���ĕۑ��j
						//���b�Z�[�W�{�b�N�X�R���g���[���ƃ��b�Z�[�W�{�b�N�X�t�H�[���̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", &MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, &MsgBoxFormNumber);
						SaveMsgBoxForm(".\\MsgBoxForm.txt", &MsgBoxForm_Copy, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

						//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_Message);//�t�@�C������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
					}
				}
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				//���O��t���ĕۑ�
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SaveAsNewMessage(FilePath_Message_h, FileTitle_Message, MAX_PATH, MAX_PATH, Message, MsgBoxCtrl_Msg.Tag[0].Post); //���O��t���ĕۑ�
						//���b�Z�[�W�{�b�N�X�R���g���[���ƃ��b�Z�[�W�{�b�N�X�t�H�[���̕ۑ�
						SetCurrentDirectory(LocalDir);
						SaveMsgBoxCtrl(".\\MsgBoxCtrl.txt", &MsgBoxCtrl_Master, MsgBoxCtrl_Kosuu, &MsgBoxFormNumber);
						SaveMsgBoxForm(".\\MsgBoxForm.txt", &MsgBoxForm_Copy, &MsgBoxForm_RGB_SoundPath, MsgBoxForm_Kosuu);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

						//�^�C�g���o�[�̃e�L�X�g�̍X�V�i���O��t���ĕۑ��ɂȂ����Ƃ��̂��߁j
						strcpy(Titlebar_text, AppMode_text);//�A�v���P�[�V����������
						strcat(Titlebar_text, FileTitle_Message);//�t�@�C������A��
						SetMainWindowText(Titlebar_text);//�^�C�g���o�[�̏�������
					}
				}
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				///////�z�[���ɖ߂�//�A�N�e�B�u�ȃf�B���N�g���i�O�ŏ�����j�C�t�@�C���p�X�i�O�ŏ�����j�C�t�@�C���^�C�g���iNULL�j�C�G�f�B�^�[���[�h�i99�j�Ń��b�Z�[�W�ҏW���[�h���甲����
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						*EditorMode_p = 99;//�O�F���b�Z�[�W�ҏW���[�h�@�P�F���ҏW���[�h�@�Q�F�p�b�h�r���[�A�@�X�X�F�z�[���֖߂�
						for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
						return 0;
					}
				}
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				List0.Nest[1] += List0.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////////�A�v���P�[�V�����̏I��
				r++;
				if (List0.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List0.Nest[0] + List0.RowWidth && List0.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List0.Nest[1] + List0.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List0.Nest[0], List0.Nest[1], List0.Nest[0] + List0.RowWidth, List0.Nest[1] + List0.RowHeight, List0.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						DxLib_End(); return 0;
					}
				}
				DrawFormatString(List0.Nest[0] + List0.BorderThickness + List0.RowPadding[0], List0.Nest[1] + List0.BorderThickness + List0.RowPadding[1], black, List0Row[r].Title); //�����̕\��
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����@�ireturn�Ŋ֐����甲������̈ȊO�́C���ׂĂ����Ń��X�g���甲����j
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List0.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea.Active = 1;
				}
			}
				
			//////�X�^�C���̃v���_�E�����X�g
			if (List1.Active == 1) {//�v���_�E�����X�g190802
				ShowList(&List1);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[1].Location[0] + ToolAForm.Margin[0],
					ToolA[1].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[1].Width,
					box[1] + ToolA[1].Height
				};
				if (ToolA[1].ParentArea_p != NULL) {
					box[0] += ToolA[1].ParentArea_p->Nest[0];
					box[1] += ToolA[1].ParentArea_p->Nest[1];
					box[2] += ToolA[1].ParentArea_p->Nest[0];
					box[3] += ToolA[1].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List1.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[1].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[1].Padding[1], black, ToolA[1].Title); //�����̕\��

				////�X�^�C���̕ۑ�
				int  r = 0;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SetCurrentDirectory(LocalDir);
						SaveFontTagSetPath(".\\FontTagSettings.txt");//�X�^�C���Z�b�g�̕ۑ�

					}
				}
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontSet, SourcePath, FileTitle_Font, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�t�H���g�摜�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ńt�H���g�摜�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_FontImgSet, SourcePath, FileTitle_FontImg, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_FontImgSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				List1.Nest[1] += List1.RowHeight;//���̍s�̊J�n�ʒu�܂ł��炷
				////�^�O�Z�b�g
				r++;
				if (List1.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List1.Nest[0] + List1.RowWidth && List1.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List1.Nest[1] + List1.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List1.Nest[0], List1.Nest[1], List1.Nest[0] + List1.RowWidth, List1.Nest[1] + List1.RowHeight, List1.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						//�_�C�A���O�Ń^�O�Z�b�g�̃t�@�C���p�X���擾
						char SourcePath[MAX_PATH] = { 0 };
						if (GetOpenFileNameCsv(Dir_TagSet, SourcePath, FileTitle_Tag, MAX_PATH, MAX_PATH)) {//���[�U�[�� OK �{�^���������� 0 �ȊO�i���ۂ͂P�j�C�����łȂ���� 0 ���Ԃ�
						//���I������Dir_TagSet���J�����g�f�B���N�g���ƂȂ�

							//���������b�Z�[�W�v���r���[�̂����������珑���ʂ�

						}
					}
				}
				DrawFormatString(List1.Nest[0] + List1.BorderThickness + List1.RowPadding[0], List1.Nest[1] + List1.BorderThickness + List1.RowPadding[1], black, List1Row[r].Title); //�����̕\��
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List1.Active = -1; List2.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea.Active = 1;
				}
			}

			//////�ݒ�̃v���_�E�����X�g
			if (List2.Active == 1) {//�v���_�E�����X�g190802
				ShowList(&List2);
				//�{�^�������i�{�^���̏ォ��`��j
				int box[4] = {
					ToolA[2].Location[0] + ToolAForm.Margin[0],
					ToolA[2].Location[1] + ToolAForm.Margin[1],
					box[0] + ToolA[2].Width,
					box[1] + ToolA[2].Height
				};
				if (ToolA[2].ParentArea_p != NULL) {
					box[0] += ToolA[2].ParentArea_p->Nest[0];
					box[1] += ToolA[2].ParentArea_p->Nest[1];
					box[2] += ToolA[2].ParentArea_p->Nest[0];
					box[3] += ToolA[2].ParentArea_p->Nest[1];
				}
				DrawBox(box[0], box[1], box[2], box[3], List2.BorderColor, true);//�v���_�E�����X�g�̃{�^��
				DrawFormatString(box[0] + ToolAForm.BorderThickness + ToolA[2].Padding[0],
					box[1] + ToolAForm.BorderThickness + ToolA[2].Padding[1], black, ToolA[2].Title); //�����̕\��

				////�w�i�̕ύX
				int  r = 0;
				if (List2.Nest[0] < ActiveMath::MouseX && ActiveMath::MouseX < List2.Nest[0] + List2.RowWidth && List2.Nest[1] < ActiveMath::MouseY && ActiveMath::MouseY < List2.Nest[1] + List2.RowHeight) {//�{�^���͈͓̔��̂Ƃ�
					DrawBox(List2.Nest[0], List2.Nest[1], List2.Nest[0] + List2.RowWidth, List2.Nest[1] + List2.RowHeight, List2.CursorColor, true); //�J�[�\���̕\��
					if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
						SettingEditorBackFlag = 1;
					}
				}
				DrawFormatString(List2.Nest[0] + List2.BorderThickness + List2.RowPadding[0], List2.Nest[1] + List2.BorderThickness + List2.RowPadding[1], black, List2Row[r].Title); //�����̕\��
				//List0.Nest[1] += List0.RowHeight;////���̍s�̊J�n�ʒu�܂ł��炷�@�����Ă��Ȃ��Ă��悢
				///////���N���b�N�����Ƃ�    �v���_�E�����X�g���甲����
				if (ActiveMath::Mouse[MOUSE_INPUT_LEFT] == 1) {
					List1.Active = -1; List2.Active = -1; Toolbar[1].Active = 1;//�v���_�E�����X�g���甲���đҋ@��Ԃɂ���
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂�
					DisplayArea.Active = 1;
				}
			}

			//�w�i�̕ύX
			if (SettingEditorBackFlag > 0) {
				//���X�g����I�������u��
				if (SettingEditorBackFlag == 1) {
					Toolbar[1].Active = 0;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 0;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 0;

				}
				//�w�i�̕ύX�t�H�[���̕\���@���X�g����I�����āi�ۑ��͖߂��Ă�������DisplayArea_Preview_FilePath�ɏ����ʂ��Ă���j
				int Value = SettingEditorBack(&DisplayArea, &BorderColorRGB, &BackColorRGB, &BackImgPath, DisplayArea_Kosuu, &SettingEditorBackFlag);
				//�w�i�̕ύX�t�H�[�����ŕۑ���������
				if (Value == 1) {
					//�v���r���[�p�̃f�B�X�v���C�G���A�ɏ����ʂ�
					DisplayArea_Preview.BackColor = DisplayArea.BackColor;//���b�Z�[�W���̓G���A
					DisplayArea_Preview.BackImg = DisplayArea.BackImg;//���b�Z�[�W���̓G���A

					//�ݒ�p�t�@�C���̕ۑ�
					SetCurrentDirectory(AppDir);
					SaveEditorSettings(DisplayArea_Preview_FilePath, &DisplayArea_Preview, &BorderColorRGB, &BackColorRGB, &BackImgPath, DisplayArea_Preview_Kosuu);//�X�^�C���Z�b�g�̕ۑ�

					//�e�G���A�̃A�N�e�B�u��
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 1;
				}
				//�w�i�̕ύX�t�H�[�����ŃL�����Z����������
				else if (Value == -1) {
					//�e�G���A�̃A�N�e�B�u��
					Toolbar[1].Active = 1;//PulldownFlag�F�|�P�F�����@�O�ȏ�F�L���ȃc�[���ԍ�
					for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A�̒�~
					DisplayArea.Active = 1;
				}
			}

			//���J�[�\���I�[�o�[
			static const int BackColor = GetColor(230, 255, 230);//R:255 G:255 B:204
			Math_CursorOver(ActiveMath::MouseX, ActiveMath::MouseY + 20, 2, black, BackColor, NULL);//Math_ButtonTitleShow(const int LocationX, const int LocationY, const int Padding, const int StringColor, const int BackColor, const int Type)
			//���}���`�K�C�h
			MultiGuide();
			//���T���v���̐��������i�R���g���[���{R�j
			if (ActiveMath::Key[KEY_INPUT_R] == 1 && (ActiveMath::Key[KEY_INPUT_LCONTROL] > 0 || ActiveMath::Key[KEY_INPUT_RCONTROL] > 0)) {
				for (int i = 0; i < ToolBKosuu; i++) ToolB[i].Active = 1;
				for (int i = 0; i < List0RowKosuu; i++) List0Row[i].Active = 1;
				for (int i = 0; i < List1RowKosuu; i++) List1Row[i].Active = 1;
				for (int i = 0; i < List2RowKosuu; i++) List2Row[i].Active = 1;
			}

		}//for���C�����[�v�̏I��
	}//while
	return 0;
}
//////////�����b�Z�[�W�ҏW���[�h�̏I��聪//////////////////�����b�Z�[�W�ҏW���[�h�̏I��聪//////////�����b�Z�[�W�ҏW���[�h�̏I��聪///////////�����b�Z�[�W�ҏW���[�h�̏I��聪/////////

////�ҏW���[�h
int Editor(int *EditorMode_p, char *FilePath_p) {

	//char FilePath[MAX_PATH] = { 0 };
	//strcpy(FilePath, FilePath_p);
	//static int LoadEditorPadFlag = 0;
	LocalDir[0] = '\0';//�z�[����ʂ̃f�B���N�g���[���c��Ȃ��悤�Ƀ��Z�b�g�i�e���[�h�̃t�@�C�����J���ŁC�����t�H���_�[�����������邽�߁j

	while (!ProcessMessage()) {//!ScreenFlip() && // && !ClearDrawScreen()
	//�������ScreenFlip����C�e���[�h�̂O�t���[����ScreenFlip�܂ł̑҂����ԁi�t�@�C���̃��[�h�Ȃǁj�ɕ\��������́�
	//�i���ꂪ�Ȃ��Ɗe���[�h���甲���Ă����Ƃ��ɁC�Ȃ���ScreenFlip����Ă��ēr���������o����Ă��܂��j
		DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);
		const static char Msg[] = "���҂���������";
		const static int MsgWidth = GetDrawStringWidth(Msg, strlen(Msg));//�ő啶�����̍��ڂ��烊�X�g�̕����擾
		DrawString((WindowWidth - MsgWidth) / 2, (WindowHeight - SystemFontSize) / 2, Msg, white);
		ScreenFlip();
		ClearDrawScreen();

		for (int i = 0; i < 3; i++) EditorPadArea[i].Active = 1;//�C���f�b�N�X�G���A�C�{�^���G���A�C�x�[�X�{�^���G���A��ҋ@��Ԃɖ߂��i�v���_�E�����X�g�̂Ƃ��C��A�N�e�B�u�̂܂�return�Ŕ����Ă��܂�Ȃ��悤�Ɂj
///////////////////////

		//���e���[�h�̂O�t���[����ScreenFlip�ŕ\��������́�
		DrawBox(0, 0, WindowWidth, WindowHeight, gray60, true);
		/////////////////
			/////////////////
		SetCurrentDirectory(AppDir);//
		//���t�H���g�E�^�O�C����уW���C�p�b�h�̏����ݒ�
		LoadFontTagSettings(".\\System\\File\\FontTagSettings.txt"); //�t�H���g�C�t�H���g�摜�C�^�O�̐ݒ�̃��[�h
		LoadJoypadSettings(".\\System\\File\\JoypadSettings.txt"); //�W���C�p�b�h�̐ݒ�̃��[�h
		/*
		strcpy(Dir_FontSet, ".\\Setting\\�t�H���g�Z�b�g");
		GetFullPathName(Dir_FontSet, MAX_PATH, Dir_FontSet, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
		strcpy(Dir_FontImgSet, ".\\Setting\\�t�H���g�摜�Z�b�g");
		GetFullPathName(Dir_FontImgSet, MAX_PATH, Dir_FontImgSet, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
		strcpy(Dir_TagSet, ".\\Setting\\�^�O�Z�b�g");
		GetFullPathName(Dir_TagSet, MAX_PATH, Dir_TagSet, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
		strcpy(Dir_Joypad, ".\\Setting\\�W���C�p�b�h");
		GetFullPathName(Dir_Joypad, MAX_PATH, Dir_Joypad, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
		*/

		if (*EditorMode_p == 0) {//���b�Z�[�W�ҏW���[�h�֐i��
			EditMessage(EditorMode_p, FilePath_p);
		}
		else if (*EditorMode_p == 1) {//���ҏW���[�h�֐i��
			EditMondai(EditorMode_p, FilePath_p);//, PadArea, ButtonForm, Index, IndexKosuu, Button_ph, ButtonKosuu, BaseButton, BaseButtonKosuu);
			//if (*EditorMode_p != 1) LocalDir[0] = '\0';//�Ⴄ���[�h�ɐi�ނƂ��̓f�B���N�g�������Z�b�g���Ă������ƂŁC�t�H���g�^�O�ݒ�̃��[�h�Ȃǂƈꏏ�ɍX�V�B
			//�i�������[�h�̂Ƃ��̓��Z�b�g�����C#img��#sound�Ȃǂ̃^�O�̓ǎ��C�t�H���g�^�O�ݒ�̃��[�h�̏ȗ��C�t�@�C�����J���̏����t�H���_�Ƃ��Ďg���j
		}
		else if (*EditorMode_p == 2) {//�p�b�h�r���[�A�֐i��
			PadPreviewMode(EditorMode_p, FilePath_p);//, PadArea, ButtonForm, Index, IndexKosuu, Button_ph, ButtonKosuu, BaseButton, BaseButtonKosuu);
			//�i�p�b�h���[�h�̂Ƃ��͖���X�V����̂�LocalDir�̃��Z�b�g�͕s�v�j
		}
		else {
			FilePath_p[0] = '\0';
			break;//�z�[���֖߂�(*EditorMode_p == 99�i99�F�z�[���֖߂�j���܂�)
		}
	}//while�̏I���

	//�e���[�h���甲����while���甲���Ă����Ƃ��C�܂��́CProcessMessage()���G���[��while���甲���Ă����Ƃ�
	SetMainWindowText(ApplicationTitle);//�^�C�g���o�[�̏�������
	return 0;
}



/////���g�b�v��ʁ�////////////���g�b�v��ʁ�////////////���g�b�v��ʁ�////////////���g�b�v��ʁ�//////
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR lpCmdLine, int) {
	//�m�N�����̐ݒ�n�@
	//SetOutApplicationLogValidFlag(FALSE); //���O�o�͂��s�����ۂ��̃t���O(TRUE:�s�� FALSE : �s��Ȃ�)
	SetMainWindowText(ApplicationTitle);//�^�C�g���o�[�̏�������
	//��DX���C�u�����̐ݒ聫////
	SetWaitVSyncFlag(FALSE);//���������M�����I�t
	ChangeWindowMode(true); //�E�B���h�E���[�h�̐؂�ւ�
	if (DxLib_Init() == -1)return(-1); // DX���C�u��������������
	//���X�N���[���֌W
	SetDrawScreen(DX_SCREEN_BACK); // �`���𗠉�ʂɐݒ�
	SetGraphMode(WindowWidth, WindowHeight, ColorBitNum);//�E�C���h�E�T�C�Y�̎w��(WindowWidth = 1000,WindowHeight = 798,ColorBitNum = 32)
	//��AppDir�̎擾�i�v���W�F�N�g�̃��[�g�f�B���N�g���i�����_�̃J�����g�f�B���N�g���j�j�isln����N������sln�Cexe����N������exe�C�f�[�^�t�@�C������N�����̓f�[�^�t�@�C��������f�B���N�g���j
	//GetCurrentDirectory(sizeof(AppDir) / sizeof(TCHAR), AppDir);//�f�B���N�g���̎擾


	//////////////////////////////////////////////////
	//�����s�t�@�C���̃p�X����AppDir���擾�isln�Cexe�C�f�[�^�t�@�C������̋N���Ɋւ�炸�Cexe������f�B���N�g���j���ăJ�����g�f�B���N�g���Ɏw��
	{
		GetModuleFileName(NULL, AppDir, MAX_PATH); //���s�t�@�C���̃p�X���擾
		int Mojisuu = strlen(AppDir);
		int Point;
		for (Point = Mojisuu - 1; AppDir[Point] != '\\' && 0 <= Point; Point--); //�i���s�t�@�C�����̑O��\\�̈ʒu��T���j
		AppDir[Point] = '\0';//\\�ȉ��̕�����i���s�t�@�C�����j�������������̂�AppDir�ƂȂ�
		SetCurrentDirectory(AppDir); //�J�����g�f�B���N�g�����w��
	}
	//////////////////////////////////////////////////
	//��WinMain�̑�3��������t�@�C�������擾
	//strcpy(lpCmdLine, "\"ab cde\"");//�m�F�p
	char FilePath[MAX_PATH] = { 0 };
	{
		int Point = 1;
		while (lpCmdLine[Point] != '\"' && lpCmdLine[Point] != '\0') Point++;
		for (int i = 1; i < Point; i++) FilePath[i - 1] = lpCmdLine[i];
	}
	/*
	//�m�F�p
	DrawFormatString(10, 10, white, "AppDir: %s", AppDir);
	DrawFormatString(10, 30, white, "FilePath: %s", FilePath);
	WaitKey();
	DxLib_End();
	return -1;
	*/



	//�mActiveMath�̏������n�@
	//���V�X�e���t�H���g�֌W�̐ݒ�
	SetFontSize(SystemFontSize); //�V�X�e���t�H���g�T�C�Y�̎w��
	ChangeFont("���C���I"); //�t�H���g�̎w��
	SetFontThickness(0);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	//���N�����̕\��
	int TitleWidth = GetDrawStringWidth(ApplicationTitle, strlen(ApplicationTitle));//
	DrawString((WindowWidth - TitleWidth) / 2, (WindowHeight - SystemFontSize) / 2, ApplicationTitle, white);//�A�v���P�[�V�����^�C�g����\��





	//���ҏW�p�p�b�h�̃��[�h�i�p�b�h�G���A�C���͗p�C���f�b�N�X�C���͗p�{�^���C���͗p��{�{�^���j
	int Error;
	switch (Error = LoadPad(".\\EditorPadSet\\EditorPadSet.acp", EditorPadArea, &EditorPadAreaKosuu, EditorPadAreaMax, NULL,//��5�����p�b�h�G���A��Parent

		EditorButtonForm, &EditorButtonFormKouu, EditorButtonFormMax,
		EditorIndex, &EditorIndexKosuu, EditorIndexMax,
		EditorButton_ph, EditorButtonKosuu, EditorButtonMax,
		EditorBaseButton, &EditorBaseButtonKosuu, EditorBaseButtonMax,
		NULL, NULL, 0, NULL, NULL, NULL, NULL, 0, 0//��15����&MsgBoxForm�C��16����MsgBoxFormKosuu�C��17����&MsgBoxCtrl�C��18����MsgBoxFormKosuu
	)) {
	case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃G���A�Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
	case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃G���A�̃p�����[�^������܂���B", black, gray60); break;
	case -3: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃G���A�̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
	case -11: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃{�^���t�H�[���Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
	case -12: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃{�^���t�H�[���̃p�����[�^������܂���B", black, gray60); break;
	case -13: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃{�^���t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
	case -21: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃C���f�b�N�X�Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
	case -22: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃C���f�b�N�X�̃p�����[�^������܂���B", black, gray60); break;
	case -23: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃C���f�b�N�X�̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
	case -31: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃{�^���Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;
	case -32: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃{�^���̃p�����[�^������܂���B", black, gray60); break;
	case -33: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃{�^���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
	case -41: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃x�[�X�{�^���Z�b�g�̃t�@�C�������݂��܂���B", black, gray60); break;

	case -42: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃x�[�X�{�^���̃p�����[�^������܂���B", black, gray60); break;
	case -43: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�ҏW�p�p�b�h�̃x�[�X�{�^���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;


	case -51: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�{�b�N�X�t�H�[���̃t�@�C�������݂��܂���B", black, gray60); break;
	case -52: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�{�b�N�X�t�H�[���̃p�����[�^������܂���B", black, gray60); break;
	case -53: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�{�b�N�X�t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
	case -61: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃t�@�C�������݂��܂���B", black, gray60); break;
	case -62: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃p�����[�^������܂���B", black, gray60); break;
	case -63: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;
	case -72: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃p�����[�^������܂���B", black, gray60); break;
	//�u-71�F�t�H���g�E�^�O�ݒ�̃t�@�C�����t�@�C�������݂��Ȃ��v�̓G�f�B�^�[�̓��͗p�p�b�h�̂悤�Ƀ��b�Z�[�W���Ńt�H���g�����߂���C�ʓr���[�h����悤�Ȃ��̂�FontTagSettings�����݂��Ȃ����߁C�G���[�ɂ͂��Ȃ�
	}
	if (Error < 0) {
		WaitKey();
		// �c�w���C�u�����g�p�̏I������
		DxLib_End();
		return -1;
	}
	//���I�����̓p�b�h�t�@�C���Ɠ����̃f�B���N�g��
	//�ҏW�p�p�b�h�̃��[�h
	SetCurrentDirectory(AppDir);




	//�m�e�G���A�E�c�[���{�^���ނ̏������n�@
	//���f�B�X�v���C�G���A
	static struct AREACONTROL DisplayArea = { 0 };
	DisplayArea.BackColor = GetColor(112, 128, 144);
	DisplayArea.Width = WindowWidth;
	DisplayArea.Height = WindowHeight - 30;
	DisplayArea.BackImg = LoadGraph(".\\System\\Fixed\\HomeBGI.png");

	//�����j���[�G���A
	static struct AREACONTROL MenuArea = { 0 };
	MenuArea.BackTransparency = 70;
	MenuArea.BackColor = GetColor(255, 255, 255);
	MenuArea.Width = 20 + 220 * 3;
	MenuArea.Height = 10 + 10 + 160 + 5 + 34 + 5 + 5 + 34 + 10+39;//200+39+39+100+100
	MenuArea.Location[0] = (WindowWidth - MenuArea.Width) / 2;
	MenuArea.Location[1] = (WindowHeight - MenuArea.Height) / 2;
	for (int i = 0; i < 4; i++) MenuArea.Padding[i] = 20;



	////////
	//���g�b�v���j���[�{�^���t�H�[��
	static struct BUTTONFORM TopMenuButtonForm = { 0 };
	TopMenuButtonForm.WaitingColor = GetColor(255, 255, 255);
	TopMenuButtonForm.CursorColor = GetColor(255, 255, 204);
	TopMenuButtonForm.BackTransparency = 50;
	TopMenuButtonForm.Margin[0] = 10; TopMenuButtonForm.Margin[1] = 10; TopMenuButtonForm.Margin[2] = 10; TopMenuButtonForm.Margin[3] = 0;
	//���g�b�v���j���[�{�^��
	const int TopMenuButtonKosuu = 3;
	static struct BUTTONCONTROL TopMenuButton[TopMenuButtonKosuu] = { 0 };
	strcpy(TopMenuButton[0].Title, "���b�Z�[�W�ҏW���[�h");
	strcpy(TopMenuButton[1].Title, "���ҏW���[�h");
	strcpy(TopMenuButton[2].Title, "�p�b�h�r���[�A");
	for (int b = 0; b < TopMenuButtonKosuu; b++) {
		TopMenuButton[b].ParentArea_p = &MenuArea;
		TopMenuButton[b].ButtonForm_p = &TopMenuButtonForm;
		if (b == 0) TopMenuButton[b].Location[0] = -TopMenuButtonForm.Margin[0];
		else TopMenuButton[b].Location[0] = -111111;
		if (b == 0) TopMenuButton[b].Location[1] = -TopMenuButtonForm.Margin[1];
		else TopMenuButton[b].Location[1] = -222222;

		for (int i = 0; i < 4; i++) TopMenuButton[b].Padding[i] = 10;
		TopMenuButton[b].Width = 200;
		TopMenuButton[b].Height = 160;
		TopMenuButton[b].Active = 1;
	}

	//���T�u���j���[�{�^���t�H�[��
	static struct BUTTONFORM SubMenuBtnForm = { 0 };
	SubMenuBtnForm.WaitingColor = GetColor(128, 128, 128);
	SubMenuBtnForm.CursorColor = GetColor(255, 255, 255);
	SubMenuBtnForm.BackTransparency = 70;
	for (int i = 0; i < 4; i++) SubMenuBtnForm.Margin[i] = 1;
	SubMenuBtnForm.BorderThickness = 1;
	SubMenuBtnForm.BorderColor = red;

	//���T�u���j���[�{�^��
	const int SubMenuBtnKosuu = 6;
	static struct BUTTONCONTROL SubMenuBtn[SubMenuBtnKosuu] = { 0 };
	strcpy(SubMenuBtn[0].Title, "�T���v��A1");
	strcpy(SubMenuBtn[1].Title, "�T���v��A2");
	strcpy(SubMenuBtn[2].Title, "�T���v��A3");
	strcpy(SubMenuBtn[3].Title, "�T���v��B1");
	strcpy(SubMenuBtn[4].Title, "�T���v��C1");
	strcpy(SubMenuBtn[5].Title, "�I��");

	for (int b = 0; b < 5; b++) {
		SubMenuBtn[b].ParentArea_p = &MenuArea;
		SubMenuBtn[b].ButtonForm_p = &SubMenuBtnForm;
		for (int i = 0; i < 4; i++) SubMenuBtn[b].Padding[i] = 10;
		SubMenuBtn[b].Active = 1;
	}


	SubMenuBtn[0].Location[0] = -SubMenuBtnForm.Margin[0];
	SubMenuBtn[0].Location[1] = 161;

	SubMenuBtn[1].Location[0] = -111111;
	SubMenuBtn[1].Location[1] = 161;


	SubMenuBtn[2].Location[0] = -SubMenuBtnForm.Margin[0];
	SubMenuBtn[2].Location[1] = -111111;

	SubMenuBtn[3].Location[0] = 220;
	SubMenuBtn[3].Location[1] = 161;
	
	SubMenuBtn[4].Location[0] = 440;
	SubMenuBtn[4].Location[1] = 161;

	//���I���{�^���t�H�[��
	static struct BUTTONFORM EndBtnForm = { 0 };
	EndBtnForm.WaitingColor = GetColor(255, 0, 51);
	EndBtnForm.CursorColor = GetColor(255, 255, 255);
	EndBtnForm.BackTransparency = 70;
	//���I���{�^��
	int EndBtn = 5;
	SubMenuBtn[EndBtn].ParentArea_p = &MenuArea;
	SubMenuBtn[EndBtn].ButtonForm_p = &EndBtnForm;
	SubMenuBtn[EndBtn].Location[0] = 592;
	SubMenuBtn[EndBtn].Location[1] = 240;
	for (int i = 0; i < 4; i++) SubMenuBtn[EndBtn].Padding[i] = 10;
	SubMenuBtn[EndBtn].Active = 1;




	//���X�e�[�^�X�o�[
	static struct AREACONTROL Statusbar = { 0 };
	Statusbar.Width = WindowWidth;
	Statusbar.Height = 30;//������v���̂���Location[1]����ɏ�����
	Statusbar.Location[0] = 0;
	Statusbar.Location[1] = WindowHeight - Statusbar.Height;
	for (int i = 0; i < 4; i++) Statusbar.Padding[i] = 8;
	Statusbar.BackColor = GetColor(240, 240, 240);

	//���b�Z�[�W�t�H�[��
	const int MsgBoxForm_kosuu = 1;//�t�H�[���̌���if (FilePath_Message_h[0] != '\0')���ł��悢���R���g���[���Ɠ����ꏊ�̂ق����킩��₷���̂ŃR�R�ɂ���
	static struct MsgBoxForm MsgBoxForm;
	//���b�Z�[�W�{�b�N�X
	const int MsgBoxCtrl_kosuu = 1;
	static struct MsgBoxCtrl MsgBoxCtrl;


	int InputHandleMath = MakeKeyInput(100, TRUE, FALSE, FALSE);//�V�����L�[���̓f�[�^�̍쐬  ESC�L�[�ɂ��L�����Z���@�\�̗L��TRUE�@���p�����݂̂̓���FALSE�@���l�����݂̂̓���FALSE



	//���b�Z�[�W
	const int MsgSize = 2000;  //MsgSize�͏I�[�������܂܂Ȃ��B�I�[�������܂߂� MsgSize + 1 �͕ϐ���MsgSizeE�ƕ\�����ƂƂ���B
	char Msg[MsgSize + 1] = { 0 }; //���b�Z�[�W������
	char FilePath_Msg[MAX_PATH];
	GetFullPathName(".\\System\\HomeMsg\\HomeMsg.acm", MAX_PATH, FilePath_Msg, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
	int LoadMsgError;
	switch (LoadMsgError = LoadMsg(FilePath_Msg, Msg, MsgSize + 1, 1)) {
	//case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�̃t�@�C�������݂��܂���B", black, gray60); break;
	case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W���T�C�Y�I�[�o�[���Ă��܂��B", black, gray60);
	}
	if (LoadMsgError < -1) {//-1�F���b�Z�[�W�̃t�@�C�������݂��Ȃ��̂̓G���[�Ƃ��Ȃ�
		DxLib::WaitKey();
		// �c�w���C�u�����g�p�̏I������
		DxLib_End();
		return -2;
	}
	//�f�B���N�g���̎擾�i�t�@�C�����̑O��\\�̈ʒu��T���j
	char LocalDir_Copy[MAX_PATH];
	strcpy(LocalDir_Copy, LocalDir);



	while (!ProcessMessage()) {
		//���̃��[�h����ڂ��Ă����Ƃ��ɐݒ���ă��[�h������������CLoadMsgSet��while�̓���
		//�J�����g�f�B���N�g���̎w��
		SetCurrentDirectory(AppDir);//���̃��[�h����ڂ��Ă����Ƃ��ɈႤ�f�B���N�g���ɂȂ��Ă��邩��K�������Ŏw��
		strcpy(LocalDir, LocalDir_Copy);
		//���b�Z�[�W�C�ݒ�C�w�i�摜�C���b�Z�[�W�v���p�e�B�̃��[�h
		int Error2;
		switch (Error2 = LoadMsgSet(LocalDir, &MsgBoxForm, MsgBoxForm_kosuu,
			&MsgBoxCtrl, MsgBoxCtrl_kosuu, 1, 0//�t�H���g�^�O�ݒ�����[�h����C�W���C�p�b�h�ݒ�����[�h���Ȃ�
		)) {
		case -1: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -2: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		case -3: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�t�H�[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//�@�i�Ȃ��j
		case -11: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃t�@�C�������݂��܂���B", black, gray60); break;
		case -12: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̃p�����[�^������܂���B", black, gray60); break;//�@�i�Ȃ��j
		case -13: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "���b�Z�[�W�R���g���[���̌����T�C�Y�I�[�o�[���Ă��܂��B", black, gray60); break;//�@�i�Ȃ��j
		case -21: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;
		case -22: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�t�H���g�E�^�O�ݒ�̃p�����[�^������܂���B", black, gray60);//�@�i�Ȃ��j
		case -31: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�W���C�p�b�h�ݒ�̃t�@�C�������݂��܂���B", black, gray60); break;//���W���C�p�b�h�ݒ�����[�h���Ȃ��̂ł����ł̓G���[�ɂȂ�Ȃ�
		case -32: ShowMsgDsignedBox(-1, -1, 600, "�G���[", white, gray30, "�W���C�p�b�h�ݒ�̃p�����[�^������܂���B", black, gray60);//�@�i�Ȃ��j

		}
		if (Error2 < 0) {
			DxLib::WaitKey();
			// �c�w���C�u�����g�p�̏I������
			DxLib_End();
			return -1;
		}

		//���I�����̓����X�^�[�f�B���N�g��
		SetCurrentDirectory(AppDir);

		//////////////




		MsgBoxCtrl.ParentArea_p = &MenuArea;//�G���A�̎w��
		MsgBoxCtrl.Tag[0].PositionP = -1;//�J�[�\����\���̂��߁Btag[0].PositionP��ActiveElement��\���B
		int EditorMode = -1;
		//AreaControlShow(&DisplayArea, 1);//�O���[�v�ڗp�i�Ȃ��Ă����܂�ς��Ȃ��j

		for (int frameH = 0; !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !MathgpUpdateMouse() && !MathgpUpdateKey(); frameH++) {//&& !MathgpUpdateJoypad() 
			//������������ҋ@
			SleepToFitFPS(FPS);
			//���f�B�X�v���C�G���A
			ShowArea(&DisplayArea, 1);
			//�����j���[�G���A
			ShowArea(&MenuArea, 1);
			//���g�b�v���j���[�{�^���̃^�C�g�������̐F�t��
			for (int i = 0; i < 3; i++) {
				DrawBox(MenuArea.Nest[0] + TopMenuButton[i].Location[0] + TopMenuButtonForm.Margin[0],
					MenuArea.Nest[1] + TopMenuButton[i].Location[1] + TopMenuButtonForm.Margin[1],
					MenuArea.Nest[0] + TopMenuButton[i].Location[0] + TopMenuButtonForm.Margin[0] + TopMenuButton[i].Width,
					MenuArea.Nest[1] + TopMenuButton[i].Location[1] + TopMenuButtonForm.Margin[1] + 34, gray30, true
				);
			}
			//���ҏW���[�h�I���{�^��
			int ClickedNo = -1;//�����ꂽ�{�^���ԍ�
			int TopMenu_PushType = 0; int TopMenu_Prev = -2; int TopMenu_Next = -2;
			// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
			if (ShowButton(TopMenuButton, TopMenuButtonKosuu, &ClickedNo, TopMenu_PushType, TopMenu_Prev, TopMenu_Next) == 1) {
				//�ҏW���[�h�ԍ����m��
				if (ClickedNo == 0)	EditorMode = 0;//���b�Z�[�W�ҏW���[�h
				else if (ClickedNo == 1) EditorMode = 1;//���ҏW���[�h
				else if (ClickedNo == 2) EditorMode = 2;//�p�b�h�r���[�A
			}

			int LocationX = TopMenuButton[0].Nest[0] + 10;
			int LocationY = TopMenuButton[0].Nest[1] + 40;
			DrawString(LocationX, LocationY, "�������܂ޕ��͂��쐬����", black); //�����̕\��
			DrawString(LocationX, LocationY + 20, "���Ƃ��ł��܂��B", black); //�����̕\��
			////
			LocationX = TopMenuButton[1].Nest[0] + 10;//�iLocationY�͓����l������ȗ��jLocationY = TopMenuButton[1].Nest[1] + 40;
			DrawString(LocationX, LocationY, "���C�����X�^�[���쐬��", black); //�����̕\��
			DrawString(LocationX, LocationY + 20, "�邱�Ƃ��ł��܂��B", black); //�����̕\��
			////
			LocationX = TopMenuButton[2].Nest[0] + 10;//�iLocationY�͓����l������ȗ��jLocationY = TopMenuButton[2].Nest[1] + 40;
			DrawString(LocationX, LocationY, "�����̓��͗p�p�b�h���m�F", black); //�����̕\��
			DrawString(LocationX, LocationY + 20, "���邱�Ƃ��ł��܂��B", black); //�����̕\��
			//���T���v���\���{�^��
			if (ShowButton(SubMenuBtn, SubMenuBtnKosuu, &ClickedNo, TopMenu_PushType, TopMenu_Prev, TopMenu_Next) == 1) {
				// ButtonType�i�O�F�ʏ�{�^���@�P�F�C���f�b�N�X�j//ChangeType�i�O�F�}�E�X�@�P�F�\���L�[�ő���@�Q�F[5][6]�L�[�ő���@�R�F[5][6]�L�[�ő���)
				///////���b�Z�[�W�ҏW���[�h�̃T���v��
				if (ClickedNo == 0) {
					//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
					GetFullPathName(".\\System\\Sample\\Message\\01\\Sample_Msg01.acm", MAX_PATH, FilePath, NULL);
				}
				else if (ClickedNo == 1) {
					GetFullPathName(".\\System\\Sample\\Message\\02\\Sample_Msg02.acm", MAX_PATH, FilePath, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
				}
				else if (ClickedNo == 2) {
					GetFullPathName(".\\System\\Sample\\Message\\03\\Sample_Msg03.acm", MAX_PATH, FilePath, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
				}
				///////���ҏW���[�h�̃T���v��
				else if (ClickedNo == 3) {
					GetFullPathName(".\\System\\Sample\\Mondai\\Sample_Mondai01.ack", MAX_PATH, FilePath, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
				}
				///////�p�b�h�r���[�A�̃T���v��
				else if (ClickedNo == 4) {
					GetFullPathName(".\\System\\Sample\\Pad\\Sample_Pad01.acp", MAX_PATH, FilePath, NULL);//���΃p�X�����΃p�X���擾�i���΃p�X�C�p�X�����i�[����o�b�t�@�̃T�C�Y�C��΃p�X�C�t�@�C�����̃A�h���X�j
				}
				///////�A�v���P�[�V�����̏I��
				else if (ClickedNo == 5) {
					DxLib_End();// �c�w���C�u�����g�p�̏I������
					return 0;//�\�t�g�̏I��
				}
			}

			//�����[�h�ԍ��̎擾
			if (FilePath[0] != '\0') EditorModeChecker(&EditorMode, FilePath);
			//���ҏW���[�h�̐U�蕪���ɐi��
			if (EditorMode == 0) { Editor(&EditorMode, FilePath); break;	}///////���b�Z�[�W�ҏW���[�h
			else if (EditorMode == 1) { Editor(&EditorMode, FilePath); break; }///////���ҏW���[�h
			else if (EditorMode == 2) { Editor(&EditorMode, FilePath); break; }///////�p�b�h�r���[�A

			//���b�Z�[�W
			int Value = ShowMsgBox(Msg, &MsgBoxCtrl);

			//���X�e�[�^�X�o�[�G���A
			ShowArea(&Statusbar, 1);
			char Copyright[] = "Active - Message Editor    Version 1.01";
			int CopyrightX = Statusbar.Nest[2] - GetDrawStringWidth(Copyright, strlen(Copyright));
			int CopyrightY = Statusbar.Nest[1];
			DrawFormatString(CopyrightX, CopyrightY, black, Copyright); //�����̕\��

			//�}���`�K�C�h
			MultiGuide();//�S���b�Z�[�W�ŋ��L���邽�߁CMathWritingP���ɓ���Ȃ����ƁB
		}//for�̏I���
	}//while�̏I���

	DxLib_End();// �c�w���C�u�����g�p�̏I������
	return -1;// �\�t�g�̏I��
}
//ActiveMessageEditor




