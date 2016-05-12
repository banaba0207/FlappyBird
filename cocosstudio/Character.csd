<GameFile>
  <PropertyGroup Name="Character" Type="Node" ID="ae8ec8bf-3f35-4ffb-b959-0c165014f46e" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="11" Speed="0.6667" ActivedAnimationName="fly">
        <Timeline ActionTag="-165542997" Property="FileData">
          <TextureFrame FrameIndex="1" Tween="False">
            <TextureFile Type="Normal" Path="Assets/bird/bird1_1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="Normal" Path="Assets/bird/bird1_3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="Assets/bird/bird1_1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="7" Tween="False">
            <TextureFile Type="Normal" Path="Assets/bird/bird1_3.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="9" Tween="False">
            <TextureFile Type="Normal" Path="Assets/bird/bird1_1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="11" Tween="False">
            <TextureFile Type="Normal" Path="Assets/bird/bird1_3.png" Plist="" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-165542997" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="1" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="3" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="5" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="7" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="9" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="11" Tween="False" Src="1" Dst="771" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="fly" StartIndex="1" EndIndex="11">
          <RenderColor A="150" R="255" G="250" B="205" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Character" Tag="4" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="bird" ActionTag="-165542997" Tag="5" IconVisible="False" LeftMargin="-17.0000" RightMargin="-17.0000" TopMargin="-12.0000" BottomMargin="-12.0000" ctype="SpriteObjectData">
            <Size X="34.0000" Y="24.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Assets/bird/bird1_3.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>