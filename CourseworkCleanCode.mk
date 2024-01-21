##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CourseworkCleanCode
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/dpw21/CourseworkClean
ProjectPath            :=/home/dpw21/CourseworkClean/CourseworkCleanCode
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Divij Wankhade
Date                   :=27/01/23
CodeLitePath           :=/home/dpw21/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CourseworkCleanCode.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/BodyData.cpp$(ObjectSuffix) $(IntermediateDirectory)/RK_4Functions.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/BodyData.cpp$(ObjectSuffix): BodyData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BodyData.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BodyData.cpp$(DependSuffix) -MM BodyData.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dpw21/CourseworkClean/CourseworkCleanCode/BodyData.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BodyData.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BodyData.cpp$(PreprocessSuffix): BodyData.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BodyData.cpp$(PreprocessSuffix) BodyData.cpp

$(IntermediateDirectory)/RK_4Functions.cpp$(ObjectSuffix): RK_4Functions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RK_4Functions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RK_4Functions.cpp$(DependSuffix) -MM RK_4Functions.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dpw21/CourseworkClean/CourseworkCleanCode/RK_4Functions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RK_4Functions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RK_4Functions.cpp$(PreprocessSuffix): RK_4Functions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RK_4Functions.cpp$(PreprocessSuffix) RK_4Functions.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dpw21/CourseworkClean/CourseworkCleanCode/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(ObjectSuffix): TextFileInputOutputFunctions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(DependSuffix) -MM TextFileInputOutputFunctions.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dpw21/CourseworkClean/CourseworkCleanCode/TextFileInputOutputFunctions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(PreprocessSuffix): TextFileInputOutputFunctions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextFileInputOutputFunctions.cpp$(PreprocessSuffix) TextFileInputOutputFunctions.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


