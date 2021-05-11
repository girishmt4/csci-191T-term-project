uniform sampler2D myTexture;
varying vec4 texCoord;
varying vec3 position;

void main()
{
	gl_FragColor = texture2D(myTexture, texCoord).gbra;
}