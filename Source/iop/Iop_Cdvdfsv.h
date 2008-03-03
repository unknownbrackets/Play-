#ifndef _IOP_CDVDFSV_H_
#define _IOP_CDVDFSV_H_

#include "Iop_Module.h"
#include "../SIF.h"
#include "../SifModuleAdapter.h"
#include "../ISO9660/ISO9660.h"

namespace Iop
{

	class CCdvdfsv : public CModule
	{
	public:
						    CCdvdfsv(CISO9660*&, CSIF&);
		virtual			    ~CCdvdfsv();

        virtual std::string GetId() const;
        virtual void        Invoke(CMIPS&, unsigned int);
//		virtual void	    SaveState(Framework::CStream*);
//		virtual void	    LoadState(Framework::CStream*);

		enum MODULE_ID
		{
			MODULE_ID_1 = 0x80000592,
			MODULE_ID_2 = 0x80000593,
			MODULE_ID_3 = 0x80000594,
			MODULE_ID_4 = 0x80000595,
			MODULE_ID_5 = 0x80000596,
			MODULE_ID_6 = 0x80000597,
			MODULE_ID_7 = 0x8000059C,
		};

	private:
		void			    Invoke592(uint32, uint32*, uint32, uint32*, uint32, uint8*);
		void			    Invoke593(uint32, uint32*, uint32, uint32*, uint32, uint8*);
		void			    Invoke595(uint32, uint32*, uint32, uint32*, uint32, uint8*);
		void			    Invoke597(uint32, uint32*, uint32, uint32*, uint32, uint8*);
		void			    Invoke59C(uint32, uint32*, uint32, uint32*, uint32, uint8*);

		//Methods
		void			    Read(uint32*, uint32, uint32*, uint32, uint8*);
		void			    StreamCmd(uint32*, uint32, uint32*, uint32, uint8*);
		void			    SearchFile(uint32*, uint32, uint32*, uint32, uint8*);

		uint32              m_nStreamPos;
        CISO9660*&          m_iso;

        CSifModuleAdapter   m_module592;
        CSifModuleAdapter   m_module593;
        CSifModuleAdapter   m_module595;
        CSifModuleAdapter   m_module597;
        CSifModuleAdapter   m_module59C;
	};

}

#endif