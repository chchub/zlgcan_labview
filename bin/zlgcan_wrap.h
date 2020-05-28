#ifndef ZLGCAN_WRAP_H_
#define ZLGCAN_WRAP_H_

#include "zlgcan.h"

// 采用对齐后的结构体
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


// CANFD标准
UINT FUNC_CALL ZCAN_SetCANFDStandard( DEVICE_HANDLE hDev, UINT channelIdx, int canfd_standard );

//设置仲裁域波特率(USBCANFD系列,PCIECANFD系列设备)
UINT FUNC_CALL ZCAN_SetAbitBaud(DEVICE_HANDLE hDev, UINT channelIdx, UINT abitbaud);

//设置数据域波特率(USBCANFD系列,PCIECANFD系列设备)
UINT FUNC_CALL ZCAN_SetDbitBaud(DEVICE_HANDLE hDev, UINT channelIdx, UINT dbitbaud);

//设置波特率（CANDTU，USBCAN，PCI-50x0-U系列）
UINT FUNC_CALL ZCAN_SetCanBaudrate(DEVICE_HANDLE hDev, UINT channelIdx, UINT baudrate);

//自定义波特率
UINT FUNC_CALL ZCAN_SetBaudRateCustom(DEVICE_HANDLE hDev, UINT channelIdx, char* RateCustom);

//CANDTU-x00UR 工作模式
UINT FUNC_CALL ZCAN_SetWorkmode(DEVICE_HANDLE hDev, UINT channelIdx, int workmode);

//CANDTU-x00UR 验收码
UINT FUNC_CALL ZCAN_DTUacode(DEVICE_HANDLE hDev, UINT channelIdx, char* acc_code);

//CANDTU-x00UR 屏蔽码
UINT FUNC_CALL ZCAN_DTUamask(DEVICE_HANDLE hDev, UINT channelIdx, char* acc_mask);

//滤波生效
UINT FUNC_CALL ZCAN_DTUfilter_confirm(DEVICE_HANDLE hDev, UINT channelIdx, int confirm);

//终端电阻
UINT FUNC_CALL ZCAN_SetResistanceEnable(DEVICE_HANDLE hDev, UINT channelIdx, int enable);

// PCIECANFD系列发送类型
UINT FUNC_CALL ZCAN_PCIeSetSendType(DEVICE_HANDLE hDev, UINT channelIdx, int send_type);

//清除滤波
UINT FUNC_CALL ZCAN_FilterClear(DEVICE_HANDLE hDev, UINT channelIdx, int clear);

//滤波生效
UINT FUNC_CALL ZCAN_FilterAck(DEVICE_HANDLE hDev, UINT channelIdx, int ack);

//滤波模式
UINT FUNC_CALL ZCAN_FilterMode(DEVICE_HANDLE hDev, UINT channelIdx, int send_type);

//滤波起始帧
UINT FUNC_CALL ZCAN_FilterStart(DEVICE_HANDLE hDev, UINT channelIdx, char* filter_start);

//滤波结束帧
UINT FUNC_CALL ZCAN_FilterEnd(DEVICE_HANDLE hDev, UINT channelIdx, char* filter_end);

//定时发送CAN
UINT FUNC_CALL ZCAN_SetAutoSend(DEVICE_HANDLE hDev, UINT channelIdx, ZCAN_AUTO_TRANSMIT_OBJ *pData);

//定时发送CANFD
UINT FUNC_CALL ZCAN_SetAutoSendFD(DEVICE_HANDLE hDev, UINT channelIdx, ZCANFD_AUTO_TRANSMIT_OBJ *pData);

// 使定时发送生效
UINT FUNC_CALL ZCAN_ApplyAutoSend(DEVICE_HANDLE hDev, UINT channelIdx);

//清空定时发送
UINT FUNC_CALL ZCAN_ClearAutoSend(DEVICE_HANDLE hDev, UINT channelIdx);

//PCIECANFD系列 发送失败后重发次数
UINT FUNC_CALL ZCAN_RetrySend(DEVICE_HANDLE hDev, UINT channelIdx, int retry);

//获取云设备信息
UINT FUNC_CALL ZCLOUD_GetDevices(ZCLOUD_DEV_NEW *pDevices, UINT size);


//USBCAN-4E-U,USBCAN-8E-U转发功能
//转发到CAN0
UINT FUNC_CALL ZCAN_RedirectCan0(DEVICE_HANDLE hDev, UINT channelIdx, char* can0);
UINT FUNC_CALL ZCAN_RedirectCan1(DEVICE_HANDLE hDev, UINT channelIdx, char* can1);
UINT FUNC_CALL ZCAN_RedirectCan2(DEVICE_HANDLE hDev, UINT channelIdx, char* can2);
UINT FUNC_CALL ZCAN_RedirectCan3(DEVICE_HANDLE hDev, UINT channelIdx, char* can3);
UINT FUNC_CALL ZCAN_RedirectCan4(DEVICE_HANDLE hDev, UINT channelIdx, char* can4);
UINT FUNC_CALL ZCAN_RedirectCan5(DEVICE_HANDLE hDev, UINT channelIdx, char* can5);
UINT FUNC_CALL ZCAN_RedirectCan6(DEVICE_HANDLE hDev, UINT channelIdx, char* can6);
UINT FUNC_CALL ZCAN_RedirectCan7(DEVICE_HANDLE hDev, UINT channelIdx, char* can7);

//NET-TCP（CANDTU-NET、CANDTU-NET-400、CANET-TCP、CANWIFI-TCP、CANFDNET-TCP）
//TCP工作模式 (服务器，客户端)
UINT FUNC_CALL ZCAN_TCPmode(DEVICE_HANDLE hDev, UINT channelIdx, int tcp_type);
//TCP本地端口
UINT FUNC_CALL ZCAN_TCPLocalPort(DEVICE_HANDLE hDev, UINT channelIdx, int local_port);
//TCP  IP地址
UINT FUNC_CALL ZCAN_TCPip(DEVICE_HANDLE hDev, UINT channelIdx, char* ip);
//TCP 工作端口
UINT FUNC_CALL ZCAN_TCPPort(DEVICE_HANDLE hDev, UINT channelIdx, int work_port);


//NET-UDP（CANET-UDP、CANWIFI-UDP、CANFDNET-UDP）
//UDP本地端口
UINT FUNC_CALL ZCAN_UDPLocalPort(DEVICE_HANDLE hDev, UINT channelIdx, int local_port);
UINT FUNC_CALL ZCAN_UDPip(DEVICE_HANDLE hDev, UINT channelIdx, char* ip);
UINT FUNC_CALL ZCAN_UDPPort(DEVICE_HANDLE hDev, UINT channelIdx, int work_port);

#endif