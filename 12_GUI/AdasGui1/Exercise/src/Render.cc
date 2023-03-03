#include <cstdint>

#include "imgui.h"
#include "implot.h"

#include "Render.hpp"
#include "RenderConstants.hpp"

void render_cycle(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles)
{
    ImGui::SetNextWindowPos(ImVec2(0.0F, 0.0F));
    ImGui::SetNextWindowSize(ImVec2(WINDOWS_WIDTH, LANE_PLOT_TOTAL_HEIGHT));

    if (ImGui::Begin("MainWindow", nullptr, WINDOW_FLAGS_CLEAN))
    {
        ImPlot::CreateContext();
        plot_lanes(ego_vehicle, vehicles);
        plot_table(ego_vehicle, vehicles);
        ImGui::End();
    }
}

void plot_lanes(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles)
{
    (void)ego_vehicle; // to avoid warning
    (void)vehicles;    // to avoid warning

    if (ImPlot::BeginPlot("Lanes"))
    {
        ImPlot::EndPlot();
    }
}

void plot_line_in_table(const VehicleType vehicle)
{
	ImGui::TableNextRow();			// Switch to next row
	ImGui::TableSetColumnIndex(0); // Set row in column
	ImGui::Text("%s", position[vehicle.id + 1]);
	ImGui::TableSetColumnIndex(1);
	ImGui::Text("%d", vehicle.id);
	ImGui::TableSetColumnIndex(2);
	ImGui::Text("%d", vehicle.lane);
	ImGui::TableSetColumnIndex(3);
	ImGui::Text("%.4f", vehicle.distance_m);
	ImGui::TableSetColumnIndex(4);
	ImGui::Text("%.4f", vehicle.speed_mps);
}

void plot_table(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles)
{
    const auto num_cols = std::size_t{ 5 };

	/// TODO: Add code here
	ImGui::SetNextWindowPos(ImVec2(0.0F, BELOW_LANES));
	ImGui::SetNextWindowSize(ImVec2(VEHICLE_TABLE_WIDTH, VEHICLE_TABLE_HEIGHT));

    if (ImGui::Begin("TableWindow", nullptr, WINDOW_FLAGS_CLEAN))
    {
        if (ImGui::BeginTable("Table", num_cols, TABLE_FLAGS))
        {
			// Define header rows
			ImGui::TableSetupColumn("Pos");
			ImGui::TableSetupColumn("Id");
			ImGui::TableSetupColumn("Lane");
			ImGui::TableSetupColumn("Distance");
			ImGui::TableSetupColumn("Speed");
			ImGui::TableHeadersRow();

			// insert data in table
			plot_line_in_table(ego_vehicle);
			plot_line_in_table(vehicles.vehicles_left_lane[0]);
			plot_line_in_table(vehicles.vehicles_left_lane[1]);
			plot_line_in_table(vehicles.vehicles_center_lane[0]);
			plot_line_in_table(vehicles.vehicles_center_lane[1]);
			plot_line_in_table(vehicles.vehicles_right_lane[0]);
			plot_line_in_table(vehicles.vehicles_right_lane[1]);
			
			ImGui::EndTable();
        }

        ImGui::End();
    }
}
