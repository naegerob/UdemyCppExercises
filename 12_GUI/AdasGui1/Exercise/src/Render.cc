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

void plot_table(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles)
{
    (void)ego_vehicle; // to avoid warning
    (void)vehicles;    // to avoid warning

    const auto num_cols = std::size_t{ 5 };
	const auto num_rows = std::size_t{ 5 };

	/// TODO: Add code here
	ImGui::SetNextWindowPos(ImVec2(0.0F, BELOW_LANES));
	ImGui::SetNextWindowSize(ImVec2(VEHICLE_TABLE_WIDTH, VEHICLE_TABLE_HEIGHT));

    if (ImGui::Begin("TableWindow", nullptr, WINDOW_FLAGS_CLEAN))
    {
        if (ImGui::BeginTable("Table", num_cols, TABLE_FLAGS))
        {
			ImGui::TableSetupColumn("Pos");
			ImGui::TableSetupColumn("Id");
			ImGui::TableSetupColumn("Lane");
			ImGui::TableSetupColumn("Distance");
			ImGui::TableSetupColumn("Speed");
			ImGui::TableHeadersRow();

			// Table data
			for (int i = 0; i < num_cols; i++)
			{
				
				ImGui::TableNextRow();			// Switch to next row
				ImGui::TableSetColumnIndex(0); // Set row in column
				//ImGui::TableNextRow();
				ImGui::Text("Ego");
				//ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(1);
				ImGui::Text("%d", 2);
				//ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(2);
				ImGui::Text("%d", 77);
				//ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(3);
				ImGui::Text("%.2f", 3.6);
				//ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(4);
				ImGui::Text("%.2f", 8.5);
			}

			ImGui::EndTable();
        }

        ImGui::End();
    }
}
