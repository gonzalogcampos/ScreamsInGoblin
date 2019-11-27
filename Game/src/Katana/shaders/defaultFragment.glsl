#version 330 core

uniform vec3 lightColor;
uniform vec3 lightColordiffuse;
uniform vec3 lightPos;  
uniform vec3 viewPos;
uniform sampler2D myTextureSampler;


in vec2 UV;
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;
void main()
{
	vec3 icolor = texture( myTextureSampler, UV ).rgb;
	float specularStrength = 0.5;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);  

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColordiffuse;
    
	float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);  

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;

	vec3 result = (ambient + diffuse + specular) * icolor;
	FragColor = vec4(result, 1.0);

}  