#include "gtest/gtest.h"
#include "fff/fff.h"
DEFINE_FFF_GLOBALS

extern "C" {
#include "co2_sensor.h"
#include "mh_z19.h"
#include "GoogleTestDemo/VIAFreeRTOSTest/FreeRTOS_FFF_MocksDeclaration.h"
}

FAKE_VOID_FUNC(mh_z19_initialise, serial_comPort_t);
FAKE_VOID_FUNC(mh_z19_injectCallBack);

class CO2SensorTest : public ::testing::Test {
protected:
	void SetUp() override {
		RESET_FAKE(mh_z19_initialise);
		RESET_FAKE(mh_z19_injectCallBack);
		RESET_FAKE(xTaskCreate);
		RESET_FAKE(vTaskDelay);
		FFF_RESET_HISTORY();
	}
	void TearDown() override {}
};

TEST_F(CO2SensorTest, FirstTest) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}