# Contiki IoT Workspace

## Bibliography 

"Internet of Things in Five Days" Linan A. Vives A.

"Internet de las Cosas" Linan A. Vives A. Bagula A. Zemarco M. Pietrosemoli E.

## Links

- <a href="https://github.com/contiki-ng/contiki-ng/wiki">Contiki Documentation</a>
- <a href="https://github.com/contiki-os/contiki">Contiki Repository</a>
- <a href="https://github.com/contiki-ng/contiki-ng/wiki/Docker">Contiki Docker Setup</a>
- <a href="http://www.contiki-os.org/">Contiki Website</a>
- <a href="https://www.thingsquare.com/blog/articles/iot-for-beginners/">Thingsquare</a>
- <a href="https://www.thingsquare.com/blog/">Thingsquare Blog</a>
- <a href="https://biblioteca.mincyt.gob.ar/">Biblioteca Electronica de Ciencia y Tecnologia</a>

## Virtual Machine Setup

### Shared Folder Setup

#### Install Build Essential Tools 

```sh
sudo apt install build-essential dkms linux-headers-$(uname -r)
```

#### Add Shared Folder 

1. Poweroff the guest machine
2. VirtualBox -> Select VM -> Settings
    - General -> Advanced -> Shared clipboard: Bidirectional
    - Shared Folders -> Adds New Shared Folder
        - Select Folder Path (Host Directory Path)
        - "Check" Auto-Mount (Auto Mount in Guest Directory)
        - "Check" Make Permanent

## Github Repository

### SSH Key Setup

Generate a new ssh key

```sh
mkdir ~/.ssh
ssh-keygen -t ecdsa -b 521 -C "your@email"
# Select path and paraphrase
# default ~/.ssh/id_ecdsa
# return to no paraphrase

eval $(ssh-agent -s)

ssh-add
```

Repeat on both guest and host machine.

### GitHub Repository Access

Go to your GitHub Repository

1. My Profile
2. Repositories
3. Settings
4. Security -> Deploy Keys
5. Add Deploy Key

Now copy the generated key to the key field

```sh
# Show the generated public key
cat ~/.ssh/id_ecdsa.pub
```
