<?xml version="1.0" encoding="ISO-8859-1"?>

<!--
	Ýêðàí ãëàâíîãî ìåíþ
-->
<window>
	<params 
		name = "profile_buttons" 
	/>
	
	<!--Èåðàðõèÿ îáúåêòîâ-->
	<object name = "hierarchy" type = "objects">
		<object name = "clouds1" type = "effect" effect = "particles\backgrounds\sky_startup" x = "0" y = "0" />
		<object name = "clouds3" type = "effect" effect = "particles\backgrounds\sky_loop_lower" x = "0" y = "0" />
		<object name = "clouds2" type = "effect" effect = "particles\backgrounds\sky_loop_upper" x = "0" y = "0" />
		<object name = "timer_clouds2" type = "timer"  max_time = "80" loop = "1">
			<spawn name = "OnTime">
				<do object = "screen.clouds2" command = "Start"/>	
			</spawn>
		</object>
		<object name = "timer_clouds3" type = "timer"  max_time = "160" loop = "1">
			<spawn name = "OnTime">
				<do object = "screen.clouds3" command = "Start"/>	
			</spawn>
		</object>


		<object name = "sky" type = "sprite" sprite_name = "sky" blend_mode="2" tex_name = "objects\screens\main_menu\gui_effects\mainmenu_tex_st" scaleX = "512.0" scaleY = "1.0" />
		<object name = "1_light_rocks" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\1_light_rocks" x = "0" y = "768" time_scale = "60"/>
		<object name = "2_dark_rocks" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\2_dark_rocks" x = "0" y = "768" time_scale = "40"/>
		
		<!--object name = "3_wfall" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\3_wfall" x = "0" y = "768" time_scale = "20"/-->
		<object name = "3_wfall" type = "objects" x = "0" y = "768">
			<object name = "3_wfall_vanim" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\3_wfall" x = "0" y = "0" time_scale = "20"/>
			<object name = "3_wfall_particles" type = "effect" effect = "particles\backgrounds\waterfall" x = "0" y = "0" />
		</object>
		
		<object name = "4_tree" type = "objects" x = "0" y = "768">
			<object name = "4_tree_vanim" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\4_tree" time_scale = "3"/>
			<object name = "4_tree_particles" type = "effect" effect = "particles\backgrounds\leafs" />
		</object>	
		<object name = "5_grass" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\5_grass" x = "0" y = "768" time_scale = "8"/>
		<!--object name = "sun_rays" type = "distortion_anim" effect = "objects\screens\main_menu\gui_effects\sun_rays" x = "0" y = "768" time_scale = "15"/-->
		
		<object name = "1_left" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\1_left" x = "0" y = "768" time_scale = "1"/>
		<object name = "2_left" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\2_left" x = "0" y = "768" time_scale = "1"/>
		<object name = "3_left" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\3_left" x = "0" y = "768" time_scale = "1"/>
		<object name = "4_left" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\4_left" x = "0" y = "768" time_scale = "1"/>
		<object name = "5_left" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\5_left" x = "0" y = "768" time_scale = "1"/>
		
		<object name = "1_left_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\1_left" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "2_left_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\2_left" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "3_left_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\3_left" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "4_left_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\4_left" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "5_left_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\5_left" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		
		<object name = "1_right" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\1_right" x = "0" y = "768" time_scale = "1"/>
		<object name = "2_right" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\2_right" x = "0" y = "768" time_scale = "1"/>
		<object name = "3_right" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\3_right" x = "0" y = "768" time_scale = "1"/>
		<object name = "4_right" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\4_right" x = "0" y = "768" time_scale = "1"/>
		<object name = "5_right" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\5_right" x = "0" y = "768" time_scale = "1"/>
		
		<object name = "1_right_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\1_right" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "2_right_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\2_right" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "3_right_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\3_right" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "4_right_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\4_right" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
		<object name = "5_right_r" type = "object_anim" effect = "objects\screens\main_menu\gui_effects\5_right" x = "0" y = "768" time_scale = "1" forward_anim = "0" />
	</object>

	<!--Îïèñàíèå ïîâåäåíèé-->
	<behaviors>
		<behavior name = "Init">
			<start>
			
				<do object = "clouds1" command = "Start" instant = "1"/>
				<do object = "clouds2" command = "Start" instant = "1"/>
				<do object = "clouds3" command = "Start" instant = "1"/>
				<do object = "1_light_rocks" command = "Start" instant = "1"/>
				<do object = "2_dark_rocks" command = "Start" instant = "1"/>
				<do object = "3_wfall_vanim" command = "Start" instant = "1"/>
				<do object = "3_wfall_particles" command = "Start" instant = "1"/>
				<do object = "4_tree_vanim" command = "Start" instant = "1"/>
				<do object = "4_tree_particles" command = "Start" instant = "1"/>
				<do object = "5_grass" command = "Start" instant = "1"/>
				<!--do object = "sun_rays" command = "Start" instant = "1"/-->

				<do object = "timer_clouds2" command = "Start" instant = "1"/>
				<do object = "timer_clouds3" command = "Start" instant = "1"/>
			</start>
			<stop/>
		</behavior>
		
		<behavior name = "StopAnimation">
			<start>
				<do command = "Set" param = "enable = 0" instant = "1"/>
			</start>
		</behavior>


		<behavior name = "StartAnimation">
			<start>
				<do command = "Set" param = "enable = 1" instant = "1"/>
			</start>
		</behavior>


		<behavior name = "ToLeft">
			<start>
				<do object = "1_left_r" command = "ToStart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_left_r" command = "ToStart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_left_r" command = "ToStart" param = "3_wfall" instant = "1"/>
				<do object = "4_left_r" command = "ToStart" param = "4_tree" instant = "1"/>
				<do object = "5_left_r" command = "ToStart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>

		<behavior name = "ToCenter">
			<start>
				<do object = "1_left" command = "ToStart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_left" command = "ToStart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_left" command = "ToStart" param = "3_wfall" instant = "1"/>
				<do object = "4_left" command = "ToStart" param = "4_tree" instant = "1"/>
				<do object = "5_left" command = "ToStart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>


		<behavior name = "ToRight">
			<start>
				<do object = "1_right_r" command = "ToStart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_right_r" command = "ToStart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_right_r" command = "ToStart" param = "3_wfall" instant = "1"/>
				<do object = "4_right_r" command = "ToStart" param = "4_tree" instant = "1"/>
				<do object = "5_right_r" command = "ToStart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>


		<behavior name = "LeftToCenter">
			<start>
				<do object = "1_left_r" command = "Restart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_left_r" command = "Restart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_left_r" command = "Restart" param = "3_wfall" instant = "1"/>
				<do object = "4_left_r" command = "Restart" param = "4_tree" instant = "1"/>
				<do object = "5_left_r" command = "Restart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>


		<behavior name = "CenterToLeft">
			<start>
				<do object = "1_left" command = "Restart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_left" command = "Restart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_left" command = "Restart" param = "3_wfall" instant = "1"/>
				<do object = "4_left" command = "Restart" param = "4_tree" instant = "1"/>
				<do object = "5_left" command = "Restart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>


		<behavior name = "RightToCenter">
			<start>
				<do object = "1_right_r" command = "Restart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_right_r" command = "Restart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_right_r" command = "Restart" param = "3_wfall" instant = "1"/>
				<do object = "4_right_r" command = "Restart" param = "4_tree" instant = "1"/>
				<do object = "5_right_r" command = "Restart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>


		<behavior name = "CenterToRight">
			<start>
				<do object = "1_right" command = "Restart" param = "1_light_rocks" instant = "1"/>
				<do object = "2_right" command = "Restart" param = "2_dark_rocks" instant = "1"/>
				<do object = "3_right" command = "Restart" param = "3_wfall" instant = "1"/>
				<do object = "4_right" command = "Restart" param = "4_tree" instant = "1"/>
				<do object = "5_right" command = "Restart" param = "5_grass" instant = "1"/>
			</start>
			<stop/>
		</behavior>
		
	</behaviors>
</window>