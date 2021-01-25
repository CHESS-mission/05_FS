#ifndef HK_PARAM_H
#define HK_PARAM_H

// Temporary implementation
// Parameters used in PUS3 hk report #1

#define PO_PARAM_SIZE 8

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