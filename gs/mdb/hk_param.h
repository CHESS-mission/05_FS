#ifndef HK_PARAM_H
#define HK_PARAM_H

#define PO_PARAM_SIZE 8

struct s_po_hk_parameters {
  uint16_t hk_id;
  uint32_t value;
};

struct s_PARAM {
  uint32_t PR_NumPings;
  uint32_t CommandsDispatched;
  uint32_t CommandErrors;
  uint32_t PingLateWarnings;
  uint32_t BD_Cycles;
  uint32_t EPS_Voltage_battery_mV;
  uint32_t EPS_Battery_mode;
  uint32_t EPS_Temp_Battery_Celsuis;
};

#endif