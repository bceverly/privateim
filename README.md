0123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789

PrivateIM

This command-line tool allows interactive private communication between two 
parties.  It is intended to be implement this using the following techniques:

1.  All communication is encrypted before it leaves your machine and enters the 
    internet using a public key provided by the party with whom you are
    communicating

2.  If you want to begin communicating with another person, the system asks
    them for a copy of their public key and then encrypts that, along with their
    userid with your private key. This ensures that if your local cache files
    are captured by a third party, that they will be opaque and the third party
    won't be able to identify anyone with whom you are communicating.
    
3.  Your private key is saved on your local system with a password - which is
    required when you start the program.  This will ensure that even if your
    private key is exfiltrated from your system, the third party will not be
    able to use it to decrypt any data on your system.
    
4.  A central server will be maintained that has the last known good IP address
    for each party you are actively communicating with.  Each user's entry
    (userid and IP) will be encrypted using your private key before it is stored
    on the server.  This will ensure that, if the central server is comprimized
    and data exfiltrated, the third party will not be able to know with whom you
    are communicating nor know their IP address.
    
5.  All communication between parties will be direct to each other's IP
    addresses as reported to the central server.  This prevents a third party
    from monitoring the central server to determine which IP addresses are
    communicating with each other.
    
6.  All encrypted traffic will be sent through port 80 which will limit the
    amount of filtering that might get in the way of the communication between
    two parties.
    
All of the code for this application will be written in C to ensure maximum
portability to multiple systems.
