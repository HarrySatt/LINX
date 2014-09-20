#ifndef LINX_SERIAL_LISTENER_H
#define LINX_SERIAL_LISTENER_H

/****************************************************************************************
**  Defines
****************************************************************************************/		
#define LINX_SERIAL_BUFFER_SIZE 64

/****************************************************************************************
**  Includes
****************************************************************************************/		
#include "utility\LinxListener.h"
#include "utility\LinxDevice.h"

//DEBUG
#include <WProgram.h>

/****************************************************************************************
**  Type Defs
****************************************************************************************/		

/****************************************************************************************
**  Classes
****************************************************************************************/		
class LinxSerialListener : public LinxListener
{
	public:
		/****************************************************************************************
		**  Variables
		****************************************************************************************/		
		LinxListenerState State;
		//unsigned char LinxSerialListenerChan;
		
		/****************************************************************************************
		**  Constructors
		****************************************************************************************/
		LinxSerialListener();		//Default Constructor
		
		/****************************************************************************************
		**  Functions
		****************************************************************************************/		
		virtual int Start(LinxDevice* linxDev, unsigned char uartChan);
		virtual int Connected();			
		virtual int Close();			
		virtual int Exit();
		
		virtual int CheckForCommands();
		
		
	private:
		/****************************************************************************************
		**  Variables
		****************************************************************************************/		
				
		/****************************************************************************************
		**  Functions
		****************************************************************************************/
	
};

extern LinxSerialListener LinxConnection;

#endif //LINX_SERIAL_LISTENER_H