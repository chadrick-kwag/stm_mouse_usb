/**
  ******************************************************************************
  * @file    usb_desc.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Descriptors for Virtual Com Port Demo
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* USB Standard Device Descriptor */
const uint8_t Virtual_Com_Port_DeviceDescriptor[] =
  {
    0x12,   /* bLength */
    USB_DEVICE_DESCRIPTOR_TYPE,     /* bDescriptorType */
    0x00,
    0x02,   /* bcdUSB = 2.00 */
    0x00,   /* bDeviceClass: CDC 0x02. if is ix 0x00, it will be defined in config descriptor*/
    0x00,   /* bDeviceSubClass */
    0x00,   /* bDeviceProtocol */
    0x40,   /* bMaxPacketSize0 */
    0x84,
    0x04,   /* idVendor = 0x0483 */
    0x40,
    0x57,   /* idProduct = 0x7540 */
    0x00,
    0x02,   /* bcdDevice = 2.00 */
    1,              /* Index of string descriptor describing manufacturer */
    2,              /* Index of string descriptor describing product */
    3,              /* Index of string descriptor describing the device's serial number */
    0x01    /* bNumConfigurations */
  };

const uint8_t Virtual_Com_Port_ConfigDescriptor[] =
  {
    /*Configuration Descriptor*/
    0x09,   /* bLength: Configuration Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE,      /* bDescriptorType: Configuration */
    VIRTUAL_COM_PORT_SIZ_CONFIG_DESC,       /* wTotalLength:no of returned bytes */
    0x00,
    0x01,   /* bNumInterfaces: 2 interface <- originally*/
    0x01,   /* bConfigurationValue: Configuration value */
    0x00,   /* iConfiguration: Index of string descriptor describing the configuration */
    0xC0,   /* bmAttributes: self powered */
    0x32,   /* MaxPower 0 mA */
    /*Interface Descriptor*/
    0x09,   /* bLength: Interface Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,  /* bDescriptorType: Interface */
    /* Interface descriptor type */
    0x00,   /* bInterfaceNumber: Number of Interface */
    0x00,   /* bAlternateSetting: Alternate setting */
    0x01,   /* bNumEndpoints: One endpoints used */
    0x03,   /* bInterfaceClass: Communication Interface Class 0x02. 0x03 means HID*/
    0x01,   /* bInterfaceSubClass: Abstract Control Model... boot interface. */
    0x02,   /* bInterfaceProtocol: Common AT commands ... mouse */
    0x00,   /* iInterface: */
    /* hid descriptor */
    0x09, // valid length
    0x21, // descriptor type: HID
    0x10,
    0x01, // 0x0110 : hid class specific version
    0x00, // bcountrycode: none
    0x01, // bNumDescriptors: number of descriptors
    0x22, //    descriptor type. decimal 34=report descriptor
    MOUSE_REPORT_DESC_SIZE,
    0x00, // 2bytes for size.
    
    /* endpoint descriptor*/
    0x07, // valid length
    0x05, // bDescriptorType: ENDPOINT
    0x81, // bEndpointAddress: Endpoint1, IN
    0x03, // bmAttributes: Interrupt. Data endpoint
    0x04,
    0x00, // word. maxpacketsize: 4
    0x32 // bInterval: polling interval, 32ms
    /*END*/
    
//    /*Header Functional Descriptor*/
//    0x05,   /* bLength: Endpoint Descriptor size */
//    0x24,   /* bDescriptorType: CS_INTERFACE */
//    0x00,   /* bDescriptorSubtype: Header Func Desc */
//    0x10,   /* bcdCDC: spec release number */
//    0x01,
//    /*Call Management Functional Descriptor*/
//    0x05,   /* bFunctionLength */
//    0x24,   /* bDescriptorType: CS_INTERFACE */
//    0x01,   /* bDescriptorSubtype: Call Management Func Desc */
//    0x00,   /* bmCapabilities: D0+D1 */
//    0x01,   /* bDataInterface: 1 */
//    /*ACM Functional Descriptor*/
//    0x04,   /* bFunctionLength */
//    0x24,   /* bDescriptorType: CS_INTERFACE */
//    0x02,   /* bDescriptorSubtype: Abstract Control Management desc */
//    0x02,   /* bmCapabilities */
//    /*Union Functional Descriptor*/
//    0x05,   /* bFunctionLength */
//    0x24,   /* bDescriptorType: CS_INTERFACE */
//    0x06,   /* bDescriptorSubtype: Union func desc */
//    0x00,   /* bMasterInterface: Communication class interface */
//    0x01,   /* bSlaveInterface0: Data Class Interface */
//    /*Endpoint 2 Descriptor*/
//    0x07,   /* bLength: Endpoint Descriptor size */
//    USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
//    0x82,   /* bEndpointAddress: (IN2) */
//    0x03,   /* bmAttributes: Interrupt */
//    VIRTUAL_COM_PORT_INT_SIZE,      /* wMaxPacketSize: */
//    0x00,
//    0xFF,   /* bInterval: */
//    /*Data class interface descriptor*/
//    0x09,   /* bLength: Endpoint Descriptor size */
//    USB_INTERFACE_DESCRIPTOR_TYPE,  /* bDescriptorType: */
//    0x01,   /* bInterfaceNumber: Number of Interface */
//    0x00,   /* bAlternateSetting: Alternate setting */
//    0x02,   /* bNumEndpoints: Two endpoints used */
//    0x0A,   /* bInterfaceClass: CDC */
//    0x00,   /* bInterfaceSubClass: */
//    0x00,   /* bInterfaceProtocol: */
//    0x00,   /* iInterface: */
//    /*Endpoint 3 Descriptor*/
//    0x07,   /* bLength: Endpoint Descriptor size */
//    USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
//    0x03,   /* bEndpointAddress: (OUT3) */
//    0x02,   /* bmAttributes: Bulk */
//    VIRTUAL_COM_PORT_DATA_SIZE,             /* wMaxPacketSize: */
//    0x00,
//    0x00,   /* bInterval: ignore for Bulk transfer */
//    /*Endpoint 1 Descriptor*/
//    0x07,   /* bLength: Endpoint Descriptor size */
//    USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
//    0x81,   /* bEndpointAddress: (IN1) */
//    0x02,   /* bmAttributes: Bulk */
//    VIRTUAL_COM_PORT_DATA_SIZE,             /* wMaxPacketSize: */
//    0x00,
//    0x00    /* bInterval */
  };

/* USB String Descriptors */
const uint8_t Virtual_Com_Port_StringLangID[VIRTUAL_COM_PORT_SIZ_STRING_LANGID] =
  {
    VIRTUAL_COM_PORT_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04 /* LangID = 0x0409: U.S. English */
  };

const uint8_t Virtual_Com_Port_StringVendor[VIRTUAL_COM_PORT_SIZ_STRING_VENDOR] =
  {
    VIRTUAL_COM_PORT_SIZ_STRING_VENDOR,     /* Size of Vendor string */
    USB_STRING_DESCRIPTOR_TYPE,             /* bDescriptorType*/
    /* Manufacturer: "STMicroelectronics" */
    'S', 0, 'T', 0, 'M', 0, 'i', 0, 'c', 0, 'r', 0, 'o', 0, 'e', 0,
    'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0,
    'c', 0, 's', 0
  };

const uint8_t Virtual_Com_Port_StringProduct[VIRTUAL_COM_PORT_SIZ_STRING_PRODUCT] =
  {
    VIRTUAL_COM_PORT_SIZ_STRING_PRODUCT,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    /* Product name: "STM32 Virtual COM Port" */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, ' ', 0, 'V', 0, 'i', 0,
    'r', 0, 't', 0, 'u', 0, 'a', 0, 'l', 0, ' ', 0, 'C', 0, 'O', 0,
    'M', 0, ' ', 0, 'P', 0, 'o', 0, 'r', 0, 't', 0, ' ', 0, ' ', 0
  };

uint8_t Virtual_Com_Port_StringSerial[VIRTUAL_COM_PORT_SIZ_STRING_SERIAL] =
  {
    VIRTUAL_COM_PORT_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,                   /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0
  };


const uint8_t mouse_ReportDescriptor[MOUSE_REPORT_DESC_SIZE] =
  {
    0x05,          /*Usage Page(Generic Desktop)*/
    0x01,
    0x09,          /*Usage(Mouse)*/
    0x02,
    0xA1,          /*Collection(Logical)*/
    0x01,
    0x09,          /*Usage(Pointer)*/
    0x01,
    /* 8 */
    0xA1,          /*Collection(Linked)*/
    0x00,
    0x05,          /*Usage Page(Buttons)*/
    0x09,
    0x19,          /*Usage Minimum(1)*/
    0x01,
    0x29,          /*Usage Maximum(3)*/
    0x03,
    /* 16 */
    0x15,          /*Logical Minimum(0)*/
    0x00,
    0x25,          /*Logical Maximum(1)*/
    0x01,
    0x95,          /*Report Count(3)*/
    0x03,
    0x75,          /*Report Size(1)*/
    0x01,
    /* 24 */
    0x81,          /*Input(Variable)*/
    0x02,
    0x95,          /*Report Count(1)*/
    0x01,
    0x75,          /*Report Size(5)*/
    0x05,
    0x81,          /*Input(Constant,Array)*/
    0x01,
    /* 32 */
    0x05,          /*Usage Page(Generic Desktop)*/
    0x01,
    0x09,          /*Usage(X axis)*/
    0x30,
    0x09,          /*Usage(Y axis)*/
    0x31,
    0x09,          /*Usage(Wheel)*/
    0x38,
    /* 40 */
    0x15,          /*Logical Minimum(-127)*/
    0x81,
    0x25,          /*Logical Maximum(127)*/
    0x7F,
    0x75,          /*Report Size(8)*/
    0x08,
    0x95,          /*Report Count(3)*/
    0x03,
    /* 48 */
    0x81,          /*Input(Variable, Relative)*/
    0x06,
    0xC0,          /*End Collection*/
    0x09,
    0x3c,
    0x05,
    0xff,
    0x09,
    /* 56 */
    0x01,
    0x15,
    0x00,
    0x25,
    0x01,
    0x75,
    0x01,
    0x95,
    /* 64 */
    0x02,
    0xb1,
    0x22,
    0x75,
    0x06,
    0x95,
    0x01,
    0xb1,
    /* 72 */
    0x01,
    0xc0
  }
  ; /* mouse_ReportDescriptor */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
