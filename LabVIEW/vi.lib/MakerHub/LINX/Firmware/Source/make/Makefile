CXX ?= g++

INC=-I../core/device/utility -I../core/device/ -I../core/listener

CORE_LINX=../core/device/utility/LinxDevice.cpp
CORE_LISTENER=../core/listener/utility/LinxListener.cpp
CORE_RPI2=$(CORE_LINX) ../core/device/utility/LinxRaspberryPi.cpp ../core/device/LinxRaspberryPi2B.cpp
CORE_BBB=$(CORE_LINX) ../core/device/utility/LinxBeagleBone.cpp ../core/device/LinxBeagleBoneBlack.cpp

LISTENER_SERIAL=$(CORE_LISTENER) ../core/listener/LinxSerialListener.cpp
LISTENER_TCP=$(CORE_LISTENER) ../core/listener/LinxLinuxTcpListener.cpp
LISTENER_CONFIG=$(CORE_LISTENER) ../core/listener/LinxSerialListener.cpp ../core/listener/LinxLinuxTcpListener.cpp

HW_RPI2B = -DLINX_DEVICE_FAMILY=4 -DLINX_DEVICE_ID=3
HW_BBB = -DLINX_DEVICE_FAMILY=6 -DLINX_DEVICE_ID=1


libs: raspberryPi2BLib beagleBoneBlackLib

beagleBoneBlackAll: beagleBoneBlackSerial beagleBoneBlackTcp beagleBoneBlackConfigurable

raspberryPi2BAll: raspberryPi2BSerial raspberryPi2BTcp raspberryPi2BConfigurable raspberryPi2BLib
	
#----------------------- Shared Objects -----------------------
raspberryPi2BLib:
	$(CXX) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) $(INC) -Wall -shared -fPIC -lrt -o ../core/examples/LinxDeviceLib/bin/liblinxdevice_rpi2.so ../core/examples/LinxDeviceLib/src/LinxDeviceLib.cpp $(CORE_RPI2) $(HW_RPI2B) -DLINXCONFIG -DDEBUG_ENABLED=-1 -g

beagleBoneBlackLib:
	$(CXX) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) $(INC) -Wall -shared -fPIC -lrt -o ../core/examples/LinxDeviceLib/bin/liblinxdevice_bbb.so ../core/examples/LinxDeviceLib/src/LinxDeviceLib.cpp $(CORE_BBB) $(HW_BBB) -DLINXCONFIG -DDEBUG_ENABLED=-1 -g
#----------------------- Listeners -----------------------
	
beagleBoneBlackSerial:
	g++ $(INC) ../core/examples/Beagle_Bone_Black_Serial/src/Beagle_Bone_Black_Serial.cpp $(CORE_BBB) $(LISTENER_SERIAL) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../core/examples/Beagle_Bone_Black_Serial/bin/beagleBoneBlackSerial.out

beagleBoneBlackTcp:
	g++ $(INC) ../core/examples/Beagle_Bone_Black_Tcp/src/Beagle_Bone_Black_Tcp.cpp $(CORE_BBB) $(LISTENER_TCP) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../core/examples/Beagle_Bone_Black_Tcp/bin/beagleBoneBlackTcp.out
	
beagleBoneBlackConfigurable:
	g++ $(INC) ../core/examples/Beagle_Bone_Black_Configurable/src/Beagle_Bone_Black_Configurable.cpp $(CORE_BBB) $(LISTENER_CONFIG) -lrt -DLINXCONFIG -DDEBUG_ENABLED=-1 -o ../core/examples/Beagle_Bone_Black_Configurable/bin/beagleBoneBlackConfigurable.out
	
raspberryPi2BSerial:
	g++ $(INC) ../core/examples/RaspberryPi_2_B_Serial/src/RaspberryPi_2_B_Serial.cpp $(CORE_RPI2) $(LISTENER_SERIAL) -lrt -DLINXCONFIG -DDEBUG_ENABLED=-1 -o ../core/examples/RaspberryPi_2_B_Serial/bin/raspberryPi2BSerial.out
	
raspberryPi2BTcp:
	g++ $(INC) ../core/examples/RaspberryPi_2_B_Tcp/src/RaspberryPi_2_B_Tcp.cpp $(CORE_RPI2) $(LISTENER_TCP) -lrt -DLINXCONFIG -DDEBUG_ENABLED=-1 -o ../core/examples/RaspberryPi_2_B_Tcp/bin/raspberryPi2BTcp.out

raspberryPi2BConfigurable:
	g++ $(INC) ../core/examples/RaspberryPi_2_B_Configurable/src/RaspberryPi_2_B_Configurable.cpp $(CORE_RPI2) $(LISTENER_CONFIG) -lrt -DLINXCONFIG -DDEBUG_ENABLED=-1 -o ../core/examples/RaspberryPi_2_B_Configurable/bin/raspberryPi2BConfigurable.out
	
#----------------------- Tests -----------------------
tests: dio-test i2c-test spi-test

dio-test:
	g++ $(INC) ../tests/src/dio-test.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/diotest.out 

rpi2DioTest:
	g++ $(INC) ../tests/src/rpi2/rpi2DioTest.cpp $(CORE_RPI2) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/rpi2/dioTest.out 
	
rpi2UartTest:
	g++ $(INC) ../tests/src/rpi2/rpi2UartTest.cpp $(CORE_RPI2) -lrt -DLINXCONFIG -DDEBUG_ENABLED=-1 -o ../tests/bin/rpi2/uartTest.out 
	
rpi2SpiTest:
	g++ -g $(INC) ../tests/src/rpi2/rpi2SpiTest.cpp $(CORE_RPI2) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/rpi2/spiTest.out 
	
i2c-test:
	g++ $(INC) ../tests/src/i2c-test.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/i2ctest.out 

pwm-test:
	g++ $(INC) ../tests/src/pwm-test.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/pwmtest.out 
	
spi-test:
	g++ $(INC) ../tests/src/spi-test.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/spitest.out 

uart-test:
	g++ $(INC) ../tests/src/uart-test.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../tests/bin/uarttest.out 
	
#----------------------- Utils -----------------------
utils: blink analogRead uartLoopback

analogRead:
	g++ $(INC) ../utils/src/analogRead.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../utils/bin/analogRead.out

blink:
	g++ $(INC) ../utils/src/blink.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../utils/bin/blink.out 

pwmSetDutyCycle:
	g++ $(INC) ../utils/src/pwmSetDutyCycle.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../utils/bin/pwmSetDutyCycle.out 
	
uartLoopback:
	g++ $(INC) ../utils/src/uartLoopback.cpp $(CORE_BBB) -lrt -DLINXCONFIG -DDEBUG_ENABLED=0 -o ../utils/bin/uartLoopback.out 
	
clean:

cleanUtils: 
	rm -rf ../utils/bin/*

cleanall:
	rm -rf *.o
	rm -rf *.out
	rm -rf ../bin/*
	

