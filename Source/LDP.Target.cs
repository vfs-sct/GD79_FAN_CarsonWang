using UnrealBuildTool;
using System.Collections.Generic;

public class LDPTarget : TargetRules
{
	public LDPTarget(TargetInfo Target) : base(Target)
	{

        Type = TargetType.Game;
	   DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

        ExtraModuleNames.AddRange( new string[] { "LDP" } );
	}
}
