#pragma once
#include <tlm.h>
#include <tlm_ia.h>
#include <tlm_base.h>
#include <lt_target.h>
#include <constants.h>

// ToDo: this is not yet tested and it should actually take advantage of existing elements
template< unsigned int WIDTH=32 >
class ia_target : public TLM_BASE::vpCommon
{
public:
	TLM_IA::IosfPrimaryTargetSocket<WIDTH> mBusPort;
	SC_HAS_PROCESS(ia_target);

	lt_target<WIDTH> *m_lt_target_CFG;
	lt_target<WIDTH> *m_lt_target_MEM;
	lt_target<WIDTH> *m_lt_target_IO;
	TLM_BASE::AddressSpace m_memSpace;
	TLM_BASE::AddressSpace m_cfgSpace;
	TLM_BASE::AddressSpace m_ioSpace;
    tlm_utils::simple_initiator_socket<ia_target, WIDTH> initiator_socket_cfg;
    tlm_utils::simple_initiator_socket<ia_target, WIDTH> initiator_socket_mem;
    tlm_utils::simple_initiator_socket<ia_target, WIDTH> initiator_socket_io;
	sc_core::sc_time m_slave_delay;

	ia_target(sc_module_name mn)
    : vpCommon(mn)
	, mBusPort  ("mBusPort", TARGET_ADDRESS_RANGE, TARGET_ADDRESS_RANGE, TARGET_ADDRESS_RANGE, this)
	, m_memSpace("memSpace", TARGET_ADDRESS_RANGE, this)
	, m_cfgSpace("cfgSpace", TARGET_ADDRESS_RANGE, this)
	, m_ioSpace ("ioSpace", TARGET_ADDRESS_RANGE, this)
	, m_slave_delay(SC_ZERO_TIME)
	{
		std::cout << "Construction of IA target : " << basename() << std::endl;
		mBusPort.setTemporalDecoupling(true);
		m_lt_target_CFG       = new lt_target<WIDTH>("m_lt_target_CFG");
		initiator_socket_cfg.bind(m_lt_target_CFG->m_memory_socket);
		m_lt_target_MEM       = new lt_target<WIDTH>("m_lt_target_MEM");
		initiator_socket_mem.bind(m_lt_target_MEM->m_memory_socket);
		m_lt_target_IO       = new lt_target<WIDTH>("m_lt_target_IO");
		initiator_socket_io.bind(m_lt_target_IO->m_memory_socket);
		mBusPort.registerResource(m_memSpace, 0x0, TLM_IA::MEM);
		mBusPort.registerResource(m_cfgSpace, 0x0, TLM_IA::CONFIG);
		mBusPort.registerResource(m_ioSpace,  0x0, TLM_IA::IO);

		m_memSpace.setWriteCB   ( this, &ia_target::memspaceWriteCb );
		m_memSpace.setReadCB    ( this, &ia_target::memspaceReadCb  );
		m_memSpace.setWriteDbgCB( this, &ia_target::memspaceWriteDbgCb );
		m_memSpace.setReadDbgCB ( this, &ia_target::memspaceReadDbgCb  );

		m_cfgSpace.setWriteCB   ( this, &ia_target::cfgspaceWriteCb );
		m_cfgSpace.setReadCB    ( this, &ia_target::cfgspaceReadCb  );
		m_cfgSpace.setWriteDbgCB( this, &ia_target::cfgspaceWriteDbgCb );
		m_cfgSpace.setReadDbgCB ( this, &ia_target::cfgspaceReadDbgCb  );
		setClkPeriod ();
	};

	int memspaceWriteCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("memspaceWriteCb with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_mem->b_transport(gp, m_slave_delay);
		return res;
	};

	int memspaceReadCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("memspaceReadCbGP with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_mem->b_transport(gp, m_slave_delay);
		return res;
	};

	int memspaceWriteDbgCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("memspaceWriteDbgCb with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_mem->transport_dbg(gp);
		return res;
	};

	int memspaceReadDbgCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("memspaceReadDbgCbGP with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_mem->transport_dbg(gp);
		return res;
	};

	int cfgspaceWriteCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("cfgspaceWriteCb with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_cfg->b_transport(gp, m_slave_delay);
		return res;
	};

	int cfgspaceReadCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("cfgspaceReadCbGP with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_cfg->b_transport(gp, m_slave_delay);
		return res;
	};

	int cfgspaceWriteDbgCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("cfgspaceWriteDbgCb with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_cfg->transport_dbg(gp);
		return res;
	};

	int cfgspaceReadDbgCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("cfgspaceReadDbgCbGP with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_cfg->transport_dbg(gp);
		return res;
	};


	int iospaceWriteCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("iospaceWriteCb with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_io->b_transport(gp, m_slave_delay);
		return res;
	};

	int iospaceReadCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("iospaceReadCbGP with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_io->b_transport(gp, m_slave_delay);
		return res;
	};

	int iospaceWriteDbgCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("iospaceWriteDbgCb with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_io->transport_dbg(gp);
		return res;
	};

	int iospaceReadDbgCb(tlm::tlm_generic_payload &gp)
	{
		TLM_BASE::ret_t res = 1;
		LOG_DEBUG("iospaceReadDbgCbGP with payload " << report::print(gp) << " called"<< endl);
		initiator_socket_io->transport_dbg(gp);
		return res;
	};

	void setClkPeriod ()
	{
		dbg.note() << "setting new clock period" << endl;
	    kernelClockPeriod = sc_time(5, SC_NS);
	    mBusPort.setClockPeriod(sc_time(5, SC_NS));
	};

	virtual const char *kind() const
	{
		return "sc_module_slave";
	};

};

