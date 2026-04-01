# Minecraft-Launcher
1. User enters data
The launcher:

sends a request to the authentication server (using local data),
receives an AccessToken and the user profile,
saves them for future launches.

2. Before launching, the launcher:

checks if the required Minecraft version is available,
downloads or updates files if necessary,
builds a list of libraries and dependencies,
assembles the classpath and launch configuration.

3. The launcher generates parameters for the Java process:

path to the game and libraries,
client version,
user data (AccessToken, UUID, username),
JVM settings (memory, flags).

Example:

java -Xmx2G -cp <libraries> net.minecraft.client.main.Main \
--accessToken=XXX --username=Player

4. Game launch:

starts the process via java or javaw,
passes all arguments.
