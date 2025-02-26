#include "hal_core/netlist/event_system/event_log.h"

#include "hal_core/utilities/log.h"
#include "hal_core/netlist/event_system/gate_event_handler.h"
#include "hal_core/netlist/event_system/module_event_handler.h"
#include "hal_core/netlist/event_system/net_event_handler.h"
#include "hal_core/netlist/event_system/netlist_event_handler.h"
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/module.h"
#include "hal_core/netlist/net.h"
#include "hal_core/netlist/netlist.h"

namespace hal
{
    namespace event_log
    {
        namespace
        {
            void handle_gate_event(gate_event_handler::event event, Gate* gate, u32 associated_data)
            {
                UNUSED(associated_data);
                if (event == gate_event_handler::event::created)
                {
                    log_info("event", "created new gate '{}' (type '{}', id {:08x})", gate->get_name(), gate->get_type()->get_name(), gate->get_id());
                }
                else if (event == gate_event_handler::event::removed)
                {
                    log_info("event", "deleted gate '{}' (type '{}', id {:08x})", gate->get_name(), gate->get_type()->get_name(), gate->get_id());
                }
                else if (event == gate_event_handler::event::name_changed)
                {
                    log_info("event", "changed name of gate with id {:08x} to '{}'", gate->get_id(), gate->get_name());
                }
                else
                {
                    log_error("event", "unknown gate event");
                }
            }

            void handle_net_event(net_event_handler::event event, Net* net, u32 associated_data)
            {
                if (event == net_event_handler::event::created)
                {
                    log_info("event", "created new net '{}' (id {:08x})", net->get_name(), net->get_id());
                }
                else if (event == net_event_handler::event::removed)
                {
                    log_info("event", "deleted net '{}' (id {:08x})", net->get_name(), net->get_id());
                }
                else if (event == net_event_handler::event::name_changed)
                {
                    log_info("event", "changed name of net with id {:08x} to '{}'", net->get_id(), net->get_name());
                }
                else if (event == net_event_handler::event::src_added)
                {
                    auto gate = net->get_netlist()->get_gate_by_id(associated_data);
                    log_info("event", "added gate '{}' (id {:08x}) as a source for net '{}' (id {:08x})", gate->get_name(), gate->get_id(), net->get_name(), net->get_id());
                }
                else if (event == net_event_handler::event::src_removed)
                {
                    auto gate = net->get_netlist()->get_gate_by_id(associated_data);
                    log_info("event", "removed source gate '{}' (id {:08x}) from net '{}' (id {:08x})", gate->get_name(), gate->get_id(), net->get_name(), net->get_id());
                }
                else if (event == net_event_handler::event::dst_added)
                {
                    auto gate = net->get_netlist()->get_gate_by_id(associated_data);
                    log_info("event", "added gate '{}' (id {:08x}) as a destination for net '{}' (id {:08x})", gate->get_name(), gate->get_id(), net->get_name(), net->get_id());
                }
                else if (event == net_event_handler::event::dst_removed)
                {
                    auto gate = net->get_netlist()->get_gate_by_id(associated_data);
                    log_info("event", "removed destination gate '{}' (id {:08x}) from net '{}' (id {:08x})", gate->get_name(), gate->get_id(), net->get_name(), net->get_id());
                }
                else
                {
                    log_error("event", "unknown net event");
                }
            }

            void handle_netlist_event(netlist_event_handler::event event, Netlist* netlist, u32 associated_data)
            {
                if (event == netlist_event_handler::event::id_changed)
                {
                    log_info("event", "changed netlist id from {:08x} to {:08x}", associated_data, netlist->get_id());
                }
                else if (event == netlist_event_handler::event::input_filename_changed)
                {
                    log_info("event", "changed input filename of netlist with id {:08x} to '{}'", netlist->get_id(), netlist->get_input_filename().string());
                }
                else if (event == netlist_event_handler::event::design_name_changed)
                {
                    log_info("event", "changed design name of netlist with id {:08x} to '{}'", netlist->get_id(), netlist->get_design_name());
                }
                else if (event == netlist_event_handler::event::device_name_changed)
                {
                    log_info("event", "changed target device name of netlist with id {:08x} to '{}'", netlist->get_id(), netlist->get_device_name());
                }
                else if (event == netlist_event_handler::event::marked_global_vcc)
                {
                    auto gate = netlist->get_gate_by_id(associated_data);
                    log_info("event", "marked gate '{}' (id {:08x}) as a global vcc gate in netlist with id {:08x}", gate->get_name(), gate->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::marked_global_gnd)
                {
                    auto gate = netlist->get_gate_by_id(associated_data);
                    log_info("event", "marked gate '{}' (id {:08x}) as a global gnd gate in netlist with id {:08x}", gate->get_name(), gate->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::unmarked_global_vcc)
                {
                    auto gate = netlist->get_gate_by_id(associated_data);
                    log_info("event", "unmarked gate '{}' (id {:08x}) as a global vcc gate in netlist with id {:08x}", gate->get_name(), gate->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::unmarked_global_gnd)
                {
                    auto gate = netlist->get_gate_by_id(associated_data);
                    log_info("event", "unmarked gate '{}' (id {:08x}) as a global gnd gate in netlist with id {:08x}", gate->get_name(), gate->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::marked_global_input)
                {
                    auto net = netlist->get_net_by_id(associated_data);
                    log_info("event", "marked net '{}' (id {:08x}) as a global input net in netlist with id {:08x}", net->get_name(), net->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::marked_global_output)
                {
                    auto net = netlist->get_net_by_id(associated_data);
                    log_info("event", "marked net '{}' (id {:08x}) as a global output net in netlist with id {:08x}", net->get_name(), net->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::marked_global_inout)
                {
                    auto net = netlist->get_net_by_id(associated_data);
                    log_info("event", "marked net '{}' (id {:08x}) as a global inout net in netlist with id {:08x}", net->get_name(), net->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::unmarked_global_input)
                {
                    auto net = netlist->get_net_by_id(associated_data);
                    log_info("event", "unmarked net '{}' (id {:08x}) as a global input net in netlist with id {:08x}", net->get_name(), net->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::unmarked_global_output)
                {
                    auto net = netlist->get_net_by_id(associated_data);
                    log_info("event", "unmarked net '{}' (id {:08x}) as a global output net in netlist with id {:08x}", net->get_name(), net->get_id(), netlist->get_id());
                }
                else if (event == netlist_event_handler::event::unmarked_global_inout)
                {
                    auto net = netlist->get_net_by_id(associated_data);
                    log_info("event", "unmarked net '{}' (id {:08x}) as a global inout net in netlist with id {:08x}", net->get_name(), net->get_id(), netlist->get_id());
                }
                else
                {
                    log_error("event", "unknown netlist event");
                }
            }

            void handle_submodule_event(module_event_handler::event event, Module* submodule, u32 associated_data)
            {
                if (event == module_event_handler::event::created)
                {
                    log_info("event", "created new submodule '{}' (id {:08x})", submodule->get_name(), submodule->get_id());
                }
                else if (event == module_event_handler::event::removed)
                {
                    log_info("event", "deleted submodule '{}' (id {:08x})", submodule->get_name(), submodule->get_id());
                }
                else if (event == module_event_handler::event::name_changed)
                {
                    log_info("event", "changed name of submodule '{}' (id {:08x}) to '{}'", submodule->get_name(), submodule->get_id(), submodule->get_name());
                }
                else if (event == module_event_handler::event::type_changed)
                {
                    log_info("event", "changed type of submodule '{}' (id {:08x}) to '{}'", submodule->get_name(), submodule->get_id(), submodule->get_type());
                }
                else if (event == module_event_handler::event::parent_changed)
                {
                    log_info("event",
                             "changed parent of submodule '{}' (id {:08x}) to submodule '{}' (id {:08x})",
                             submodule->get_name(),
                             submodule->get_id(),
                             submodule->get_parent_module()->get_name(),
                             submodule->get_parent_module()->get_id());
                }
                else if (event == module_event_handler::event::submodule_added)
                {
                    log_info("event",
                             "added submodule '{}' (id {:08x}) to submodule '{}' (id {:08x})",
                             submodule->get_netlist()->get_module_by_id(associated_data)->get_name(),
                             associated_data,
                             submodule->get_name(),
                             submodule->get_id());
                }
                else if (event == module_event_handler::event::submodule_removed)
                {
                    log_info("event", "removed submodule with id {:08x} from submodule '{}' (id {:08x})", associated_data, submodule->get_name(), submodule->get_id());
                }
                else if (event == module_event_handler::event::gate_assigned)
                {
                    auto gate = submodule->get_netlist()->get_gate_by_id(associated_data);
                    log_info("event", "inserted gate '{}' (id {:08x}) into submodule '{}' (id {:08x})", gate->get_name(), associated_data, submodule->get_name(), submodule->get_id());
                }
                else if (event == module_event_handler::event::gate_removed)
                {
                    log_info("event", "removed gate with id {:08x} from submodule '{}' (id {:08x})", associated_data, submodule->get_name(), submodule->get_id());
                }
                else if (event == module_event_handler::event::input_port_name_changed)
                {
                    log_info("event", "changed input port name of net with id {:08x} from submodule '{}' (id {:08x})", associated_data, submodule->get_name(), submodule->get_id());
                }
                else if (event == module_event_handler::event::output_port_name_changed)
                {
                    log_info("event", "changed output port name of net with id {:08x} from submodule '{}' (id {:08x})", associated_data, submodule->get_name(), submodule->get_id());
                }
                else
                {
                    log_error("event", "unknown submodule event");
                }
            }
        }    // namespace

        void initialize()
        {
            LogManager::get_instance().add_channel("event", {LogManager::create_stdout_sink(), LogManager::create_file_sink(), LogManager::create_gui_sink()}, "info");
            
            
            //gate_event_handler::register_callback("event_log", &handle_gate_event);
            //net_event_handler::register_callback("event_log", &handle_net_event);
            //netlist_event_handler::register_callback("event_log", &handle_netlist_event);
            //module_event_handler::register_callback("event_log", &handle_submodule_event);
            
            
        }
    }    // namespace event_log
}    // namespace hal
