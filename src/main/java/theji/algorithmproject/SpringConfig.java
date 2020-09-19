package theji.algorithmproject;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import theji.algorithmproject.repository.MemberRepository;
import theji.algorithmproject.service.MemberService;

@Configuration
public class SpringConfig {
//    private final DataSource dataSource;
//    public SpringConfig(DataSource datasource){
//        this.dataSource = datasource;
//    }
//    private final EntityManager em;
//
//    public SpringConfig(EntityManager em){
//        this.em = em;
//    }
    private final MemberRepository memberRepository;

    public SpringConfig(MemberRepository memberRepository){
        this.memberRepository = memberRepository;
    }

    @Bean
    public MemberService memberService() {
        return new MemberService(memberRepository);
    }

//    @Bean
//    public MemberRepository memberRepository() {
//        //return new MemoryMemberRepository();
//        //return new JdbcMemberRepository(dataSource);
//        //return new JdbcTemplateMemberRepository(dataSource);
//        return new JpaMemberRepository(em);
//    }
}
