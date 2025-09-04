using UnrealBuildTool;
using System.Collections.Generic;

public class LDPEditorTarget : TargetRules
{

	public LDPEditorTarget(TargetInfo Target) : base(Target)
	{
       Type = TargetType.Editor;
	  
       DefaultBuildSettings = BuildSettingsVersion.V5;
       IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

        ExtraModuleNames.AddRange( new string[] { "LDP" } );
	}
}
