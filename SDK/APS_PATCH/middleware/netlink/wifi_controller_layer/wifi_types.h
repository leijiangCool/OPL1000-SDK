/******************************************************************************
*  Copyright 2017 - 2018, Opulinks Technology Ltd.
*  ---------------------------------------------------------------------------
*  Statement:
*  ----------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Opulinks Technology Ltd. (C) 2018
******************************************************************************/

#ifndef __WIFI_TYPES_H__
#define __WIFI_TYPES_H__

#include <stdint.h>
#include <stdbool.h>
#include "controller_wifi_com.h"

#ifdef __cplusplus
extern "C" {
#endif


/** \defgroup WIFI_APIs WIFI APIs
  * @brief WIFI APIs 
  */

/** @addtogroup WIFI_APIs
  * @{
  */


/******************************************************
 *                    Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

/**@brief The maximum length of SSID.
*/
#define WIFI_MAX_LENGTH_OF_SSID             (32+1)

/**@brief MAC address length.
*/
#define WIFI_MAC_ADDRESS_LENGTH             (6)

/**@brief Length of 802.11 MAC header.
*/
#define WIFI_LENGTH_802_11                  (24)

/**@brief Beacon interval length in a frame header.
*/
#define WIFI_BEACON_INTERVAL_LENGTH         (2)

/**@brief Length of capability information in a frame header.
*/
#define WIFI_CAPABILITY_INFO_LENGTH         (2)


/**@brief The maximum length of passphrase used in WPA-PSK and WPA2-PSK encryption types.
*/
#define WIFI_LENGTH_PASSPHRASE              (64)

/**@brief maximum number of ap list items which can stored
*/
#define WIFI_MAX_SCAN_AP_NUM                (16)

/**@brief maximum number of supported rates which can used
*/
#define WIFI_MAX_SUPPORTED_RATES            (8)

/******************************************************
 *                   Enumerations
 ******************************************************/

/**@defgroup WIFI_ENUM Enumeration
* @{
*/

/** @brief This enumeration defines the supported events generated by the Wi-Fi driver.
  *        The event will be sent to the upper layer handler registered in #wifi_register_event_handler().
  */
typedef enum
{
    WIFI_EVENT_NONE = -1,               /**< Reserved */
    WIFI_EVENT_INIT_COMPLETE = 0,       /**< Wi-Fi initialization complete event. */
    WIFI_EVENT_SCAN_COMPLETE,           /**< Scan completed event */
    WIFI_EVENT_STA_START,               /**< station start */
    WIFI_EVENT_STA_STOP,                /**< station stop */
    WIFI_EVENT_STA_CONNECTED,           /**< station connected to AP event */
    WIFI_EVENT_STA_DISCONNECTED,        /**< station disconnected from AP */
    WIFI_EVENT_STA_CONNECTION_FAILED,   /**< Connection has failed. For the reason code, please refer to #wifi_reason_code_t. */
    WIFI_EVENT_STA_GOT_IP,              /**< station got IP from connected AP */
    WIFI_EVENT_MAX
} wifi_event_t;

typedef enum {
    WIFI_MODE_NULL = 0,         /**< null mode */
    WIFI_MODE_STA,              /**< Wi-Fi station mode */
    WIFI_MODE_AP,               /**< Wi-Fi soft-AP mode */
    WIFI_MODE_MAX
} wifi_mode_t;


/** @brief This enumeration defines the wireless authentication mode to indicate the Wi-Fi device authentication attribute.
*/
typedef enum {
    WIFI_AUTH_OPEN = 0,         /**< authenticate mode : open */
    WIFI_AUTH_WEP,              /**< authenticate mode : WEP */
    WIFI_AUTH_WPA_PSK,          /**< authenticate mode : WPA_PSK */
    WIFI_AUTH_WPA2_PSK,         /**< authenticate mode : WPA2_PSK */
    WIFI_AUTH_WPA_WPA2_PSK,     /**< authenticate mode : WPA_WPA2_PSK */
    WIFI_AUTH_WPA2_ENTERPRISE,  /**< authenticate mode : WPA2_ENTERPRISE */
} wifi_auth_mode_t;


/** @brief This enumeration defines the reason code of the WIFI_EVENT_STA_CONNECTION_FAILED event in #wifi_event_t.
  * Find the details for the reason code below.
  */
typedef enum {
    WIFI_REASON_CODE_SUCCESS,                             /**<  0   Reserved. */
    WIFI_REASON_CODE_FIND_AP_FAIL,                        /**<  1   (Internal) No AP found. */
    WIFI_REASON_CODE_PREV_AUTH_INVALID,                   /**<  2   Previous authentication is no longer valid. */
    WIFI_REASON_CODE_DEAUTH_LEAVING_BSS,                  /**<  3   Deauthenticated because sending STA is leaving (or has left) IBSS or ES. */
    WIFI_REASON_CODE_DISASSOC_INACTIVITY,                 /**<  4   Disassociated due to inactivity. */
    WIFI_REASON_CODE_DISASSOC_AP_OVERLOAD,                /**<  5   Disassociated because AP is unable to handle all currently associated STAs. */
    WIFI_REASON_CODE_CLASS_2_ERR,                         /**<  6   Class 2 frame received from nonauthenticated STA. */
    WIFI_REASON_CODE_CLASS_3_ERR,                         /**<  7   Class 3 frame received from nonauthenticated STA. */
    WIFI_REASON_CODE_DISASSOC_LEAVING_BSS,                /**<  8   Disassociated because sending STA is leaving (or has left) BSS. */
    WIFI_REASON_CODE_ASSOC_BEFORE_AUTH,                   /**<  9   STA requesting (re)association is not authenticated with responding STA. */
    /* 802.11h */
    WIFI_REASON_CODE_DISASSOC_PWR_CAP_UNACCEPTABLE,       /**<  10  Disassociated because the information in the Power Capability element is unacceptable. */
    WIFI_REASON_CODE_DISASSOC_SUP_CHS_UNACCEPTABLE,       /**<  11  Disassociated because the information in the Supported Channels element is unacceptable. */
    /* 802.11i */
    WIFI_REASON_CODE_INVALID_INFO_ELEM = 13,              /**<  13  Invalid information element. */
    WIFI_REASON_CODE_MIC_FAILURE,                         /**<  14  Message integrity code (MIC) failure. */
    WIFI_REASON_CODE_4_WAY_HANDSHAKE_TIMEOUT,             /**<  15  4-Way Handshake time out. */
    WIFI_REASON_CODE_GROUP_KEY_UPDATE_TIMEOUT,            /**<  16  Group Key Handshake time out. */
    WIFI_REASON_CODE_DIFFERENT_INFO_ELEM,                 /**<  17  Information element in 4-Way Handshake different from (Re)Association Request/Probe Response/Beacon frame. */
    WIFI_REASON_CODE_GROUP_CIPHER_INVALID_VALID,          /**<  18  Invalid group cipher. */
    WIFI_REASON_CODE_PAIRWISE_CIPHER_INVALID,             /**<  19  Invalid pairwise cipher. */
    WIFI_REASON_CODE_AKMP_INVALID,                        /**<  20  Invalid AKMP. */
    WIFI_REASON_CODE_UNSUPPORTED_RSNE_VERSION,            /**<  21  Unsupported RSN information element version. */
    WIFI_REASON_CODE_INVALID_RSNE_CAPABILITIES,           /**<  22  Invalid RSN information element capabilities. */
    WIFI_REASON_CODE_IEEE_802_1X_AUTH_FAILED,             /**<  23  IEEE 802.1X authentication failed. */
    WIFI_REASON_CODE_CIPHER_REJECTED,                     /**<  24  Cipher suite rejected because of the security policy. */

    WIFI_REASON_CODE_AUTO_CONNECT_FAILED = 200,          /**<  200  Auto connect failed. */
} wifi_reason_code_t;

/** @brief This enumeration defines the wireless STA scan type
*/
typedef enum {
    WIFI_SCAN_TYPE_ACTIVE = 0,      /**< Actively scan a network by sending 802.11 probe(s)         */
    WIFI_SCAN_TYPE_PASSIVE,         /**< Passively scan a network by listening for beacons from APs */
} wifi_scan_type_t;

typedef enum {
    WIFI_FAST_SCAN = 0,             /**< Do fast scan, scan will end after find SSID match AP */
    WIFI_ALL_CHANNEL_SCAN,          /**< All channel scan, scan will end after scan all the channel */
}wifi_scan_method_t;

typedef enum {
    WIFI_CONNECT_AP_BY_SIGNAL = 0,  /**< Sort match AP in scan list by RSSI */
    WIFI_CONNECT_AP_BY_SECURITY,    /**< Sort match AP in scan list by security mode */
}wifi_sort_method_t;

typedef enum {
    WIFI_BW_HT20 = 1,               /**< Bandwidth is HT20 */
    WIFI_BW_HT40,                   /**< Bandwidth is HT40 */
} wifi_bandwidth_t;

/** @brief This enumeration defines wireless security cipher suits.
*/
typedef enum {
    WIFI_CIPHER_TYPE_NONE = 0,      /**< 0, the cipher type is none */
    WIFI_CIPHER_TYPE_WEP40,         /**< 1, the cipher type is WEP40 */
    WIFI_CIPHER_TYPE_WEP104,        /**< 2, the cipher type is WEP104 */
    WIFI_CIPHER_TYPE_TKIP,          /**< 3, the cipher type is TKIP */
    WIFI_CIPHER_TYPE_CCMP,          /**< 4, the cipher type is CCMP */
    WIFI_CIPHER_TYPE_TKIP_CCMP,     /**< 5, the cipher type is TKIP and CCMP */
    WIFI_CIPHER_TYPE_UNKNOWN,       /**< 6, the cipher type is unknown */
} wifi_cipher_type_t;
/**
* @}
*/

/******************************************************
 *                 Type Definitions
 ******************************************************/

typedef int (*wifi_event_notify_cb_t)(void *data);

/******************************************************
 *                    Structures
 ******************************************************/
/** @brief Range of active scan times per channel */
typedef struct {
    uint32_t min;                           /**< minimum active scan time per channel, units: millisecond */
    uint32_t max;                           /**< maximum active scan time per channel, units: millisecond, values above 1500ms may
                                                 cause station to disconnect from AP and are not recommended.  */
} wifi_active_scan_time_t;

/** @brief Aggregate of active & passive scan time per channel */
typedef union {
    wifi_active_scan_time_t active;         /**< active scan time per channel, units: millisecond. */
    uint32_t passive;                       /**< passive scan time per channel, units: millisecond, values above 1500ms may
                                                cause station to disconnect from AP and are not recommended. */
} wifi_scan_time_t;


/** @brief Structure describing parameters for a Wi-Fi fast scan */
typedef struct {
    int8_t              rssi;               /**< The minimum rssi to accept in the fast scan mode */
    wifi_auth_mode_t    authmode;           /**< The weakest authmode to accept in the fast scan mode */
}wifi_fast_scan_threshold_t;


/** @brief This structure defines the inforamtion of scanned APs
*/
typedef struct {
    uint8_t  ssid[WIFI_MAX_LENGTH_OF_SSID];    /**< Stores the predefined SSID. */
    uint8_t  ssid_length;                      /**< Length of the SSID. */
    uint8_t  bssid[WIFI_MAC_ADDRESS_LENGTH];   /**< AP's MAC address. */
    uint8_t  channel;                          /**< The channel used. */
    wifi_auth_mode_t auth_mode;                /**< Please refer to the definition of #wifi_auth_mode_t. */
    wifi_cipher_type_t pairwise_cipher;        /**< pairwise cipher of AP, Please refer to the definition of #wifi_encrypt_type_t. */
    wifi_cipher_type_t group_cipher;           /**< group cipher of AP */
    int   rssi;                                /**< Records the RSSI value when probe response is received. */
    uint16_t beacon_interval;                  /**< Indicates the beacon interval. */
    uint16_t capability_info;                  /**< The Capability Information field contains a number of subfields that are used to indicate requested or advertised optional capabilities. */
} wifi_scan_info_t;

/** @brief Parameters for an SSID scan. */
typedef struct {
    uint8_t *ssid;                             /**< SSID of AP */
    uint8_t *bssid;                            /**< MAC address of AP */
    uint8_t channel;                           /**< channel, scan the specific channel */
    bool show_hidden;                          /**< enable to scan AP whose SSID is hidden */
    wifi_scan_type_t scan_type;                /**< scan type, active or passive */
    wifi_scan_time_t scan_time;                /**< scan time per channel */
} wifi_scan_config_t;


/** @brief This structure defines the list of scanned APs with their corresponding information.
*/
typedef struct {
    wifi_scan_info_t ap_record[WIFI_MAX_SCAN_AP_NUM]; /**< The information about an AP obtained through the scan result is stored */
    int       num;                                    /**< number of AP in the list */
} wifi_scan_list_t;


/** @brief This structure is the Wi-Fi configuration for initialization for STA mode.
*/
typedef struct {
    uint8_t ssid[WIFI_MAX_LENGTH_OF_SSID];    /**< The SSID of the target AP. */
    uint8_t ssid_length;                      /**< The length of the SSID. */
    uint8_t bssid_present;                    /**< The BSSID is present if it is set to 1. Otherwise, it is set to 0. */
    uint8_t bssid[WIFI_MAC_ADDRESS_LENGTH];   /**< The MAC address of the target AP. */
    uint8_t password[WIFI_LENGTH_PASSPHRASE]; /**< The password of the target AP. */
    uint8_t password_length;                  /**< The length of the password. If the length is 64, the password is regarded as PMK. */
    wifi_scan_method_t scan_method;           /**< do all channel scan or fast scan */
    wifi_sort_method_t sort_method;           /**< sort the connect AP in the list by rssi or security mode */
    wifi_fast_scan_threshold_t  threshold;    /**< When scan_method is set to WIFI_FAST_SCAN, only APs which have an auth mode that is more secure than the selected auth mode and a signal stronger than the minimum RSSI will be used. */
} wifi_sta_config_t;

/** @brief This structure is the Wi-Fi configuration for initialization for Soft-AP mode.
*/
typedef struct {
    uint8_t ssid[WIFI_MAX_LENGTH_OF_SSID];    /**< The SSID of the Soft-AP. */
    uint8_t ssid_length;                      /**< The length of the SSID. */
    uint8_t password[WIFI_LENGTH_PASSPHRASE]; /**< The password of the Soft-AP. */
    uint8_t password_length;                  /**< The length of the password. */
    wifi_auth_mode_t auth_mode;               /**< The authentication mode. */
    wifi_cipher_type_t encrypt_type;          /**< The encryption mode. */
    uint8_t channel;                          /**< The channel of Soft-AP. */
    uint8_t ssid_hidden;                      /**< Broadcast SSID or not, default 0, broadcast the SSID */
    uint8_t max_connection;                   /**< Max number of stations allowed to connect in, default 4, max 4 */
    uint16_t beacon_interval;                 /**< Beacon interval, 100 ~ 60000 ms, default 100 ms */
} wifi_ap_config_t;


/** @brief Wi-Fi configuration for initialization.
*/
typedef union {
    wifi_ap_config_t ap_config;              /**< The configurations for certain AP. It should be set when the OPMODE is #WIFI_MODE_AP_ONLY . */
    wifi_sta_config_t sta_config;            /**< The configurations for the STA. It should be set when the OPMODE is #WIFI_MODE_STA_ONLY. */
} wifi_config_t;

/**
 * @brief WiFi stack configuration parameters
 */
typedef struct {
    wifi_event_notify_cb_t event_handler;    /**< WiFi event handler */
    int              magic;                  /**< WiFi init magic number, it should be the last field */
} wifi_init_config_t;

/**
 * @brief WiFi auto connect info parameters
 */
typedef struct {
    bool            free_ocpy;                         //scan info buffer is free or occupied, 0:free, 1:occupied
    uint8_t         bssid[WIFI_MAC_ADDRESS_LENGTH];    /* BSS ID - 48 bit HW address */
    uint8_t         ap_channel;                        /* Which Channel */
    unsigned long   latest_beacon_rx_time;             /* Timestamp - Last interaction with BSS */
    int8_t          ssid[WIFI_MAX_LENGTH_OF_SSID];     /* SSID of the BSS - 33 bytes */
    uint8_t         supported_rates[WIFI_MAX_SUPPORTED_RATES];
    int8_t          rssi;                              /* Last observed Rx Power (dBm) */
    uint16_t        beacon_interval;                   /* Beacon interval - In time units of 1024 us */
    uint16_t        capabilities;                      /* Supported capabilities */
    uint8_t         dtim_prod;                         //DTIM Period

    wpa_ie_data_t wpa_data;
    uint8_t         rsn_ie[100];
    uint8_t         wpa_ie[100];
    int8_t          passphrase[WIFI_LENGTH_PASSPHRASE];  /* maximum number of passphrase is 64 bytes */
    int8_t          hid_ssid[WIFI_MAX_LENGTH_OF_SSID];   /* [APS write/MSQ read] Hidden SSID of the BSS. When ssid is null, using this field. */
    uint8_t         psk[32];
    uint8_t         fast_connect;
} wifi_auto_connect_info_f;


/**
  * @}
  */


/**
  * @}
  */
 
#ifdef __cplusplus
}
#endif

#endif /* __WIFI_EVENT_H__ */
