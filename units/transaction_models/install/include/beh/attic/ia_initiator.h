#ifndef IA_INITIATOR_H
#define IA_INITIATOR_H

#include <tlm.h>
#include <tlm_ia.h>
#include <tlm_base.h>
#include <lt_initiator.h>
#include <Adapter.h>

template< unsigned int WIDTH=32 >
class ia_initiator : public TLM_BASE::vpCommon
{
public:

	TLM_IA::IosfPrimaryInitiatorSocket<WIDTH> mBusPort;
	SC_HAS_PROCESS(ia_initiator);

	ia_initiator(sc_module_name mn)
    : vpCommon(mn)
	, mBusPort("mBusPort", this)
    , InitSingleton(InitSingleton->getSingletonObject())
	, m_randomization("m_randomization", false, this)
	, m_rs("m_rs", 0, this)
	, m_command_type("m_command_type", 0, this)
	, m_type("m_type", 0, this)
	, m_fmt("m_fmt", 0, this)
	, m_tc("m_tc", 0, this)
	, m_ns("m_ns", 0, this)
	, m_ro("m_ro", 0, this)
	, m_ido("m_ido", 0, this)
	, m_td("m_td", 0, this)
	, m_ecrc("m_ecrc", 0, this)
	, m_ecrc_generate("m_ecrc_generate", 0, this)
	, m_ecrc_error("m_ecrc_error", 0, this)
	, m_ep("m_ep", 0, this)
	, m_reqid_bus("m_reqid_bus", 0, this)
	, m_reqid_device("m_reqid_device", 0, this)
	, m_reqid_function("m_reqid_function", 0, this)
	, m_tag("m_tag", 0, this)
	, m_lbe("m_lbe", 0, this)
	, m_fbe("m_fbe", 0, this)
	, m_bewd("m_bewd", 0, this)
	, m_th("m_th", 0, this)
	, m_src_id("m_src_id", 0, this)
	, m_dest_id("m_dest_id", 0, this)
	, m_sai("m_sai", 0, this)
	, m_deadline("m_deadline", 0, this)
	, m_IntertransactionDelay("m_IntertransactionDelay", InitSingleton->getIntertransactionDelay(), this)
   {
		std::cout << "Construction of IA initiator: " << basename() << std::endl;
		lt_initiator_1       = new lt_initiator<WIDTH>("lt_initiator_1");
		lt_initiator_1->initiator_socket.bind(m_local_socket);

		setClkPeriod ();
		m_local_socket.register_b_transport       (this, &ia_initiator<WIDTH>::custom_b_transport);
		m_local_socket.register_transport_dbg     (this, &ia_initiator<WIDTH>::custom_transport_dbg);
		m_local_socket.register_get_direct_mem_ptr(this, &ia_initiator<WIDTH>::custom_get_direct_mem_ptr);
   };

private:

    tb_mod_init_options*		      InitSingleton;
	TLM_BASE::Attribute<bool> 	      m_randomization;   ///< randomization
	TLM_BASE::Attribute<unsigned int> m_rs;   ///< root space
	TLM_BASE::Attribute<unsigned int> m_command_type;   ///<command type
	TLM_BASE::Attribute<unsigned int> m_type;
	TLM_BASE::Attribute<unsigned int> m_fmt;
	TLM_BASE::Attribute<unsigned int> m_tc;
	TLM_BASE::Attribute<unsigned int> m_ns;
	TLM_BASE::Attribute<unsigned int> m_ro;
	TLM_BASE::Attribute<unsigned int> m_ido;
	TLM_BASE::Attribute<unsigned int> m_td;
	TLM_BASE::Attribute<unsigned int> m_ecrc;
	TLM_BASE::Attribute<unsigned int> m_ecrc_generate;
	TLM_BASE::Attribute<unsigned int> m_ecrc_error;
	TLM_BASE::Attribute<unsigned int> m_ep;
	TLM_BASE::Attribute<unsigned int> m_reqid_bus;
	TLM_BASE::Attribute<unsigned int> m_reqid_device;
	TLM_BASE::Attribute<unsigned int> m_reqid_function;
	TLM_BASE::Attribute<unsigned int> m_tag;
	TLM_BASE::Attribute<unsigned int> m_lbe;
	TLM_BASE::Attribute<unsigned int> m_fbe;
	TLM_BASE::Attribute<unsigned int> m_bewd;
	TLM_BASE::Attribute<unsigned int> m_th;
	TLM_BASE::Attribute<unsigned int> m_src_id;
	TLM_BASE::Attribute<unsigned int> m_dest_id;
	TLM_BASE::Attribute<unsigned int> m_sai;
	TLM_BASE::Attribute<unsigned int> m_deadline;
	TLM_BASE::Attribute<unsigned int> m_IntertransactionDelay;

	lt_initiator<WIDTH>    *lt_initiator_1;

	/**
	 */
	void
	attach_extension(tlm::tlm_generic_payload &payload,
			unsigned int command_type = 0,
			unsigned int rs = 0)
	{
        payload.set_extension< TLM_IA::tExtension >( new TLM_IA::tExtension );

		if (m_randomization.value) {
			(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::MWr32); //ToDo fix real random
			(payload.get_extension< TLM_IA::tExtension >())->set_rs(rand()%10);//ToDo fix real random
		}
		else {
			//payload.set_extension< TLM_IA::tExtension >( new TLM_IA::tExtension );
			if (payload.get_command()==tlm::TLM_WRITE_COMMAND) {
			switch (command_type) {
			case 0:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::MWr32);
				break;
			case 1:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::CfgWr0);
				break;
			case 2:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::IOWr);
				break;
			default:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::MWr32);
				break;
			}
			}
			else {
			switch (command_type) {
			case 0:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::MRd32);
				break;
			case 1:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::CfgRd0);
				break;
			case 2:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::IORd);
				break;
			default:
				(payload.get_extension< TLM_IA::tExtension >())->set_type(tlm_iface::iosf::MRd32);
				break;
			};
			};
			(payload.get_extension< TLM_IA::tExtension >())->set_rs(rs);
		};

        payload.set_command(tlm::TLM_IGNORE_COMMAND);
	};

	/** customized b_transport function
	 */
	void
	custom_b_transport(
			tlm::tlm_generic_payload &payload
			, sc_core::sc_time &delay_time
			)
	{
		attach_extension(payload, m_command_type, m_rs);
		mBusPort->b_transport(payload, delay_time);
	};

	/** customized transport_dbg  function
	 */
	unsigned int
	custom_transport_dbg(
			tlm::tlm_generic_payload &payload
			)
	{
		attach_extension(payload, m_command_type, m_rs);
		return mBusPort->transport_dbg(payload);
	};

	/** customized DMI function
	 */
	bool
	custom_get_direct_mem_ptr(
			tlm::tlm_generic_payload& trans,
			tlm::tlm_dmi& dmi_data
			)
	{
		return mBusPort->get_direct_mem_ptr(trans, dmi_data);
	};

	tlm_utils::simple_target_socket<ia_initiator, WIDTH> m_local_socket;

	void setClkPeriod ()
	{
		dbg.note() << "setting new clock period, fixed at " << m_IntertransactionDelay.value << " SC_NS" << endl;
	    kernelClockPeriod = sc_time(m_IntertransactionDelay.value , SC_NS);
	};

#define SC_TRACE_SIG(x) sc_trace(tf, x,       std::string(name()) + "." + #x)
#define SC_TRACE_VAR(x) sc_trace(tf, x,       std::string(name()) + "." + #x)
#define SC_TRACE_ATT(x) sc_trace(tf, x.value, std::string(name()) + "." + #x)
	void trace(sc_trace_file* tf)
	{
		SC_TRACE_ATT(m_randomization);
		SC_TRACE_ATT(m_rs);
		SC_TRACE_ATT(m_command_type);
		SC_TRACE_ATT(m_type);
		SC_TRACE_ATT(m_fmt);
		SC_TRACE_ATT(m_tc);
		SC_TRACE_ATT(m_ns);
		SC_TRACE_ATT(m_ro);
		SC_TRACE_ATT(m_ido);
		SC_TRACE_ATT(m_td);
		SC_TRACE_ATT(m_ecrc);
		SC_TRACE_ATT(m_ecrc_generate);
		SC_TRACE_ATT(m_ecrc_error);
		SC_TRACE_ATT(m_ep);
		SC_TRACE_ATT(m_reqid_bus);
		SC_TRACE_ATT(m_reqid_device);
		SC_TRACE_ATT(m_reqid_function);
		SC_TRACE_ATT(m_tag);
		SC_TRACE_ATT(m_lbe);
		SC_TRACE_ATT(m_fbe);
		SC_TRACE_ATT(m_bewd);
		SC_TRACE_ATT(m_th);
		SC_TRACE_ATT(m_src_id);
		SC_TRACE_ATT(m_dest_id);
		SC_TRACE_ATT(m_sai);
		SC_TRACE_ATT(m_deadline);
	};

	virtual const char *kind() const
	{
		return "sc_module_master";
	};

};

#endif
