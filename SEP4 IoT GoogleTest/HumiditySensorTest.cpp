#include "gtest/gtest.h"
#include "fff/fff.h"
DEFINE_FFF_GLOBALS

extern "C" {
#include "temp_hum_sensor.h"
#include "hih8120.h"
#include "GoogleTestDemo/VIAFreeRTOSTest/FreeRTOS_FFF_MocksDeclaration.h"
}
FAKE_VALUE_FUNC(hih8120_driverReturnCode_t, hih8120_initialise);
FAKE_VALUE_FUNC(hih8120_driverReturnCode_t, hih8120_wakeup);

class HumiditySensorTest : public ::testing::Test {
protected:
	void SetUp() override {
		RESET_FAKE(hih8120_initialise);
		RESET_FAKE(hih8120_wakeup);
		RESET_FAKE(xTaskCreate);
		RESET_FAKE(vTaskDelay);
		FFF_RESET_HISTORY();
	}
	void TearDown() override {}
};

TEST_F(HumiditySensorTest, FirstTest) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}