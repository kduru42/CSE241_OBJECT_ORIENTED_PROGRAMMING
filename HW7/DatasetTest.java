

public class DatasetTest
{
    public static void main(String arg[])
    {
        Dataset ds = new Dataset();

        Player p1 = new Player();
        Player p2 = new Player();

        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));
        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));
        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));
        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));
        
        System.out.println("Showing lists of Players and Viewers after adding some media objects");
        System.out.println("Playlist of player p1:");
        p1.show_list();
        System.out.println();
        System.out.println("Playlist of player p2:");
        p2.show_list();
        System.out.println();
        System.out.println("Playlist of viewer v1:");
        v1.show_list();
        System.out.println();
        System.out.println("Playlist of viewer p2:");
        v2.show_list();
        System.out.println();

        Playable po = p1.currently_playing();
        Non_playable np = v1.currently_viewing();

        System.out.println("Currently playing media object of player p1");
        po.info();
        System.out.println();
        System.out.println("Currently viewing media object of viewer v1");
        np.info();
        System.out.println();

        System.out.println("Changing the currently playing object of player p1 to the next video object");
        p1.next("video");
        System.out.println();
        System.out.println("Changing the currently viewing object of viewer v1 to the next text object");
        v1.next("text");
        System.out.println();

        po = p1.currently_playing();
        np = v1.currently_viewing();

        System.out.println("Currently playing media object of player p1");
        po.info();
        System.out.println();

        System.out.println("Currently viewing media object of viewer v1");
        np.info();
        System.out.println();



        System.out.println("Changing the currently playing object of player p1 to the previous audio object");
        p1.previous("audio");
        System.out.println();
        System.out.println("Changing the currently viewing object of viewer v1 to the previous image object");
        v1.previous("image");
        System.out.println();

        po = p1.currently_playing();
        np = v1.currently_viewing();

        System.out.println("Currently playing media object of player p1");
        po.info();
        System.out.println();
        System.out.println("Currently viewing media object of viewer v1");
        np.info();
        System.out.println();

        System.out.println("Removing currently playing and viewing objects from dataset");
        ds.remove(po);
        ds.remove(np);
        System.out.println();

        System.out.println("Showing lists of Players and Viewers after removing media objects");
        System.out.println("Playlist of player p1:");
        p1.show_list();
        System.out.println();
        System.out.println("Playlist of player p2:");
        p2.show_list();
        System.out.println();
        System.out.println("Playlist of viewer v1:");
        v1.show_list();
        System.out.println();
        System.out.println("Playlist of viewer p2:");
        v2.show_list();
        System.out.println();
    }
}