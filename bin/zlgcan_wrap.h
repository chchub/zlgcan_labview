#ifndef ZLGCAN_WRAP_H_
#define ZLGCAN_WRAP_H_

#include "zlgcan.h"

// ���ö����Ľṹ��
typedef struct _ZCLOUD_DEV_NEW {
	int devIndex;           
	char type[64];
	char model[64];
	int status;             // 0:online, 1:offline
	BYTE bCanUploads[16];   // each channel enable upload can
	BYTE canNum; 
	BYTE bGpsUpload;
	BYTE reserved[2];
} ZCLOUD_DEV_NEW;


// CANFD��׼
UINT FUNC_CALL ZCAN_SetCANFDStandard( DEVICE_HANDLE hDev, UINT channelIdx, int canfd_standard );

//�����ٲ�������(USBCANFDϵ��,PCIECANFDϵ���豸)
UINT FUNC_CALL ZCAN_SetAbitBaud(DEVICE_HANDLE hDev, UINT channelIdx, UINT abitbaud);

//��������������(USBCANFDϵ��,PCIECANFDϵ���豸)
UINT FUNC_CALL ZCAN_SetDbitBaud(DEVICE_HANDLE hDev, UINT channelIdx, UINT dbitbaud);

//���ò����ʣ�CANDTU��USBCAN��PCI-50x0-Uϵ�У�
UINT FUNC_CALL ZCAN_SetCanBaudrate(DEVICE_HANDLE hDev, UINT channelIdx, UINT baudrate);

//�Զ��岨����
UINT FUNC_CALL ZCAN_SetBaudRateCustom(DEVICE_HANDLE hDev, UINT channelIdx, char* RateCustom);

//CANDTU-x00UR ����ģʽ
UINT FUNC_CALL ZCAN_SetWorkmode(DEVICE_HANDLE hDev, UINT channelIdx, int workmode);

//CANDTU-x00UR ������
UINT FUNC_CALL ZCAN_DTUacode(DEVICE_HANDLE hDev, UINT channelIdx, char* acc_code);

//CANDTU-x00UR ������
UINT FUNC_CALL ZCAN_DTUamask(DEVICE_HANDLE hDev, UINT channelIdx, char* acc_mask);

//�˲���Ч
UINT FUNC_CALL ZCAN_DTUfilter_confirm(DEVICE_HANDLE hDev, UINT channelIdx, int confirm);

//�ն˵���
UINT FUNC_CALL ZCAN_SetResistanceEnable(DEVICE_HANDLE hDev, UINT channelIdx, int enable);

// PCIECANFDϵ�з�������
UINT FUNC_CALL ZCAN_PCIeSetSendType(DEVICE_HANDLE hDev, UINT channelIdx, int send_type);

//����˲�
UINT FUNC_CALL ZCAN_FilterClear(DEVICE_HANDLE hDev, UINT channelIdx, int clear);

//�˲���Ч
UINT FUNC_CALL ZCAN_FilterAck(DEVICE_HANDLE hDev, UINT channelIdx, int ack);

//�˲�ģʽ
UINT FUNC_CALL ZCAN_FilterMode(DEVICE_HANDLE hDev, UINT channelIdx, int send_type);

//�˲���ʼ֡
UINT FUNC_CALL ZCAN_FilterStart(DEVICE_HANDLE hDev, UINT channelIdx, char* filter_start);

//�˲�����֡
UINT FUNC_CALL ZCAN_FilterEnd(DEVICE_HANDLE hDev, UINT channelIdx, char* filter_end);

//��ʱ����CAN
UINT FUNC_CALL ZCAN_SetAutoSend(DEVICE_HANDLE hDev, UINT channelIdx, ZCAN_AUTO_TRANSMIT_OBJ *pData);

//��ʱ����CANFD
UINT FUNC_CALL ZCAN_SetAutoSendFD(DEVICE_HANDLE hDev, UINT channelIdx, ZCANFD_AUTO_TRANSMIT_OBJ *pData);

// ʹ��ʱ������Ч
UINT FUNC_CALL ZCAN_ApplyAutoSend(DEVICE_HANDLE hDev, UINT channelIdx);

//��ն�ʱ����
UINT FUNC_CALL ZCAN_ClearAutoSend(DEVICE_HANDLE hDev, UINT channelIdx);

//PCIECANFDϵ�� ����ʧ�ܺ��ط�����
UINT FUNC_CALL ZCAN_RetrySend(DEVICE_HANDLE hDev, UINT channelIdx, int retry);

//��ȡ���豸��Ϣ
UINT FUNC_CALL ZCLOUD_GetDevices(ZCLOUD_DEV_NEW *pDevices, UINT size);


//USBCAN-4E-U,USBCAN-8E-Uת������
//ת����CAN0
UINT FUNC_CALL ZCAN_RedirectCan0(DEVICE_HANDLE hDev, UINT channelIdx, char* can0);
UINT FUNC_CALL ZCAN_RedirectCan1(DEVICE_HANDLE hDev, UINT channelIdx, char* can1);
UINT FUNC_CALL ZCAN_RedirectCan2(DEVICE_HANDLE hDev, UINT channelIdx, char* can2);
UINT FUNC_CALL ZCAN_RedirectCan3(DEVICE_HANDLE hDev, UINT channelIdx, char* can3);
UINT FUNC_CALL ZCAN_RedirectCan4(DEVICE_HANDLE hDev, UINT channelIdx, char* can4);
UINT FUNC_CALL ZCAN_RedirectCan5(DEVICE_HANDLE hDev, UINT channelIdx, char* can5);
UINT FUNC_CALL ZCAN_RedirectCan6(DEVICE_HANDLE hDev, UINT channelIdx, char* can6);
UINT FUNC_CALL ZCAN_RedirectCan7(DEVICE_HANDLE hDev, UINT channelIdx, char* can7);

//NET-TCP��CANDTU-NET��CANDTU-NET-400��CANET-TCP��CANWIFI-TCP��CANFDNET-TCP��
//TCP����ģʽ (���������ͻ���)
UINT FUNC_CALL ZCAN_TCPmode(DEVICE_HANDLE hDev, UINT channelIdx, int tcp_type);
//TCP���ض˿�
UINT FUNC_CALL ZCAN_TCPLocalPort(DEVICE_HANDLE hDev, UINT channelIdx, int local_port);
//TCP  IP��ַ
UINT FUNC_CALL ZCAN_TCPip(DEVICE_HANDLE hDev, UINT channelIdx, char* ip);
//TCP �����˿�
UINT FUNC_CALL ZCAN_TCPPort(DEVICE_HANDLE hDev, UINT channelIdx, int work_port);


//NET-UDP��CANET-UDP��CANWIFI-UDP��CANFDNET-UDP��
//UDP���ض˿�
UINT FUNC_CALL ZCAN_UDPLocalPort(DEVICE_HANDLE hDev, UINT channelIdx, int local_port);
UINT FUNC_CALL ZCAN_UDPip(DEVICE_HANDLE hDev, UINT channelIdx, char* ip);
UINT FUNC_CALL ZCAN_UDPPort(DEVICE_HANDLE hDev, UINT channelIdx, int work_port);

#endif